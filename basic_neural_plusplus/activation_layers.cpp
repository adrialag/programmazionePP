#include "activation_layers.hpp"

Eigen::MatrixXd SigmoidLayer::forward(const Eigen::MatrixXd& input) {
    Eigen::MatrixXd output = 1.0 / (1.0 + (-input.array()).exp());   // da completare
    return output;
}

Eigen::MatrixXd TanhLayer::forward(const Eigen::MatrixXd& input){
    Eigen::MatrixXd output = input.array().tanh();
    return output;
}