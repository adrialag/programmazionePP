#ifndef ACTIVATION_LAYERS_HPP
#define ACTIVATION_LAYERS_HPP
#include "layer.hpp"

class SigmoidLayer : public Layer {
public:
    Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) override;
};
#endif