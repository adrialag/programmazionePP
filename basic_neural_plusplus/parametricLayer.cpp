#include "parametricLayer.hpp"

//in parametric.cpp si scrivono effettivamente tutti i metodi dichiarati prima

DenseLayer::DenseLayer(int Nn, int Ni) {
    Wt = Eigen::MatrixXd::Random(Nn, Ni);        // valori casuali tra -1 e 1
    biases = Eigen::MatrixXd::Zero(Nn, 1);       // bias nulli
}
/*
Ragioniamo un attimo sulle dimensioni di tutti questi strati
uno strato prende in input 784 ingressi ha 100 neuroni
i pesi devono essere oni ingresso pesato per 100
e qundi cosi si crea la matrice
ora noi stiamo facendo W = z*x+b
quindi vuol dire che x è una matrice Ni * 1 la'ltra deve essere Nn * Ni affichè si possa 
fare il prodotto

Nella funzione forward io dovrò creare una matrice
assegnarla al prodotto + la somma
e darla in return
*/




Eigen::MatrixXd DenseLayer::forward(const Eigen::MatrixXd& input) {
    Eigen::MatrixXd output = Wt * input + biases;    
    return output;
}

const Eigen::MatrixXd& DenseLayer::getWeights() const { return Wt; }
const Eigen::MatrixXd& DenseLayer::getBiases() const { return biases; }