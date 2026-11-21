#ifndef LAYER_HPP
#define LAYER_HPP

#include <Eigen/Dense>

//sto definendo la classe layer che conterrà tutti i tipi di layer
class Layer {
public:
    virtual ~Layer() {}
    virtual Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) = 0;
};

#endif