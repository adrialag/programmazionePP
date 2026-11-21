#include <iostream>
#include <stdexcept>
#include <Eigen/Dense>
#include "parametricLayer.hpp"
#include "matrix.hpp"
#include "sequential.hpp"

void prova_matrix() {
    // 1. set e get
    Matrix a(2, 3);              // 2 x 3, tutti a 0
    a.set(0, 2, 5.0);
    a.set(1, 0, 7.0);
    std::cout << a.get(0, 2) << " " << a.get(1, 0) << " "
              << a.get(1, 1) << std::endl;
    // 2. un indice sbagliato
    try {
        a.get(2, 0);             // la riga 2 non esiste
        std::cout << "nessuna eccezione" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "eccezione: " << e.what() << std::endl;
    }
    // 3. la copia
    Matrix b = a;                // costruttore di copia
    b.set(0, 2, 9.0);
    std::cout << a.get(0, 2) << " " << b.get(0, 2) << std::endl;
    // 4. l'assegnamento
    Matrix c(4, 4);
    c = a;                       // operator=
    std::cout << c.getRows() << " " << c.getCols() << " "
              << c.get(1, 0) << std::endl;
}
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

int main() {
    prova_matrix();
    prova_dense_layer();
    prova_sequential();
    return 0;
}