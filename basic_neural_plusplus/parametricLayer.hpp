#ifndef PARAMETRIC_LAYER_HPP
#define PARAMETRIC_LAYER_HPP
//ricordare sempre che in hpp si dichiarano solo i metodi che poi vengono scritti in cpp
#include <Eigen/Dense>

class DenseLayer {
private:
    //l'obiettivo è uno strato di neuroni che calcola z = Wx + B
    //ha bisogno dei pasi e del bias in input
    Eigen::MatrixXd Wt;       // W: Nn x Ni
    Eigen::MatrixXd biases;   // b: Nn x 1

public:
    //questo è il costruttore 
    DenseLayer(int Nn, int Ni);  // neuroni, ingressi

    //metodo che effettivamente fa il passo forward
    Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input);
    
    //I due const hanno ruoli completamente diversi
    //il primo const dice che ciò che ricevi non puoi modificarlo
    //perchè io sto passando direttamente il puntatore alla matrice originale 
    //quindi sarebbe grave se poi lo si può modificare
    //invece il secondo const dice che la funzione non può modificare this che riceve
    const Eigen::MatrixXd& getWeights() const;
    const Eigen::MatrixXd& getBiases() const;
};

#endif