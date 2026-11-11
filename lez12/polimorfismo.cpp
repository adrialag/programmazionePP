#include <iostream>
#include <vector>

class Layer {
public:
    virtual void forward() const { std::cout << "Layer::forward\n"; }
    //virtual per fare correttamente chiamare le derivata e non quello delle case base
    //sceglie il metodo durante la compilazione
};

class DenseLayer : public Layer {
private:
    int Nn_, Ni_;
public:
    DenseLayer(int Nn, int Ni) : Nn_(Nn), Ni_(Ni) {}
    void for    ward() const override { //qua viene ridefinito forward
        //override serve a ridefinire (anche se non strettamente necessario)
        //override obbliga ad esserci un metodo nella classe base (sennò problem con typo)
        std::cout << "DenseLayer: W x + b, W di " << Nn_ << " x " << Ni_ << "\n";
    }
};

class SigmoidLayer : public Layer {
public:
    void forward() const override { std::cout << "SigmoidLayer: sigma(z)\n"; }
};
int main() {
    DenseLayer d(128, 784);
    SigmoidLayer s;
    std::vector<Layer*> rete;//sto dichiarando rete contiene puntatori a tipo layer
    rete.push_back(&d);//avrò layer diversi (faccio push back dell'indirizzo ovviamente)
    rete.push_back(&s);
    for (Layer* l : rete) {//di nuovo il metodo in stile python
        l->forward();//forward diverso in base ai layer -> si adatta
        //senza virtual ci sarebbe stato un comportamento diverso
        //così abbiamo ottenuto un polimorfismo dinamico
    }
    return 0;
}