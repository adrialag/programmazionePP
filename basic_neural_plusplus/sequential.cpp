#include "sequential.hpp"

Sequential::~Sequential() {
    for(Layer* layer: layers){
        delete layer; //chiama il distruttore
    }
    layers.clear();
}

void Sequential::add(Layer* layer) {
    layers.push_back(layer);
}

Eigen::MatrixXd Sequential::forward(
        const Eigen::MatrixXd& input) {
    Eigen::MatrixXd corrente = input;
    for (Layer* l : layers) {
        corrente = l->forward(corrente);
    }
    return corrente;
}