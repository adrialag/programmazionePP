#include <iostream>
#include <stdexcept>
#include <Eigen/Dense>
#include <chrono>
#include "parametricLayer.hpp"
#include "sequential.hpp"
#include "activation_layers.hpp"

void prova_dense_layer() {
    // un'immagine MNIST: 784 pixel in colonna
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    // 128 neuroni, 784 ingressi
    DenseLayer strato(128, 784);
    Eigen::MatrixXd z = strato.forward(x);
    std::cout << "z: " << z.rows() << " x " << z.cols()
              << std::endl;

    // z(0,0) ricalcolato con il ciclo del Laboratorio 04
    const Eigen::MatrixXd& W = strato.getWeights();
    double acc = 0.0;
    for (int i = 0; i < 784; i++) {
        acc += W(0, i) * x(i, 0);
    }
    acc += strato.getBiases()(0, 0);
    std::cout << z(0, 0) << " " << acc << std::endl;
}
// Task 5: una rete di due layer, 784 -> 128 -> 10
void prova_sequential() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    Sequential rete;
    rete.add(new DenseLayer(128, 784));
    rete.add(new DenseLayer(10, 128));
    Eigen::MatrixXd z = rete.forward(x);
    std::cout << "layer: " << rete.size() << ", z: "
              << z.rows() << " x " << z.cols() << std::endl;
}

// Task 3: 784 -> 128 -> 10, sigmoide dopo ogni DenseLayer
void costruisci_rete(Sequential& rete) {
    rete.add(new DenseLayer(128, 784));
    rete.add(new SigmoidLayer());
    rete.add(new DenseLayer(10, 128));
    rete.add(new SigmoidLayer());
}

void prova_rete() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    Sequential rete;
    costruisci_rete(rete);
    Eigen::MatrixXd y = rete.forward(x);
    std::cout << "y: " << y.rows() << " x " << y.cols()
              << ", min " << y.minCoeff()
              << ", max " << y.maxCoeff() << std::endl;
}

// Task 4: il tempo di n forward della rete
void misura_tempo() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    Sequential rete;
    costruisci_rete(rete);
    int n = 10000;   // una sola forward e' troppo breve da misurare
    auto inizio = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        rete.forward(x);
    }
    auto fine = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        fine - inizio).count();
    std::cout << n << " forward: " << ms << " ms" << std::endl;
}

int main() {
    prova_dense_layer();
    prova_sequential();
    prova_rete();
    misura_tempo();
    return 0;
}