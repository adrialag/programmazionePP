#ifndef SEQUENTIAL_HPP
#define SEQUENTIAL_HPP
#include <vector>
#include "layer.hpp"

class Sequential {
private:
    std::vector<Layer*> layers;
public:
    Sequential() {}
    ~Sequential();
    Sequential(const Sequential&) = delete;//blocca la copia -> meglio di errore in esecuzione
    Sequential& operator=(const Sequential&) = delete;
    void add(Layer* layer);
    Eigen::MatrixXd forward(const Eigen::MatrixXd& input);//farà il passo in avanti
    int size() const { return layers.size(); }
};
#endif