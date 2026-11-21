#include <cmath>
#include "parametricLayer.hpp"
#include "randnumgen.hpp"
//in parametric.cpp si scrivono effettivamente tutti i metodi dichiarati prima
//dobbiamo costruire la funzione per generare numeri gaussiani BOX-MULLER
//static indica che una funzione si vede solo all'interno del file dove si trova
static double gauss(){
    double x1, x2;
    do{
        x1 = rng.ranf();
        x2 = rng.ranf();
    } while (x1 == 0 || x2 == 0);
    return std::cos(2 * M_PI * x2) * std::sqrt(-2.0 * std::log(x1));
}
//inizializzare i pesi con la distribuzione e la sigma voluta
DenseLayer::DenseLayer(int Nn, int Ni, InitType type,
                       DistroType distro) {
    double s = 0.0;
    switch(type){
        case InitType::HE:
            if(distro == DistroType::UNIFORM){
                s =  std::sqrt(6.0 / Ni);
            }
            else{
                s = std::sqrt(2.0 / Ni);
            }
            break;
        case InitType::XAVIER:
            if(distro == DistroType::UNIFORM){
                s = std::sqrt(2.0 / (Nn + Ni));
            }
            else{
                s = std::sqrt(6.0 / (Nn + Ni));
            }
            break;
    }
    // pesi uniformi in [-s, s), o gaussiani con sigma = s
    Wt = Eigen::MatrixXd(Nn, Ni);
    for (int i = 0; i < Nn; i++) {
        for (int j = 0; j < Ni; j++) {
            if (distro == DistroType::UNIFORM)
                Wt(i, j) = 2.0 * s * (rng.ranf() - 0.5);
            else
                Wt(i, j) = s * gauss();
        }
    }
    biases = Eigen::MatrixXd::Zero(Nn, 1);   // bias nulli
}

Eigen::MatrixXd DenseLayer::forward(const Eigen::MatrixXd& input) {
    Eigen::MatrixXd output = Wt * input + biases;    
    return output;
}

const Eigen::MatrixXd& DenseLayer::getWeights() const { return Wt; }
const Eigen::MatrixXd& DenseLayer::getBiases() const { return biases; }