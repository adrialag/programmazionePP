#ifndef PARAMETRIC_LAYER_HPP
#define PARAMETRIC_LAYER_HPP
#include "layer.hpp"

//non devo più includere Eigen perchè è gia dentro layer


//devo rifermi alla classe madre -> ora denselayer è classe derivata
class DenseLayer : public Layer {
private:
    Eigen::MatrixXd Wt;       // W: Nn x Ni
    Eigen::MatrixXd biases;   // b: Nn x 1
public:
    DenseLayer(int Nn, int Ni);  // neuroni, ingressi -> identico a prima
    Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) override; //override -> per dire che riscrive
    //primo const protegge output(accesso diretto alla matrice) secondo dentro la funzione
    const Eigen::MatrixXd& getWeights() const;
    const Eigen::MatrixXd& getBiases() const;
};
#endif