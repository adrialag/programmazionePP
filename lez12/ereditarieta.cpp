#include <iostream>
#include <string>
class Layer {
protected: //privato ma accessibile alle classi derivate
//se cambiato con private da un errore perchè dopo viene fatto l'accesso
    std::string tipo_;
public:
    Layer(const std::string& tipo) : tipo_(tipo) {}
    //elimina il costruttore di default 
    //se poi elimino a riga 18 layer crea problemi
    void stampa_tipo() const { std::cout << "layer di tipo " << tipo_ << "\n"; }
};

class DenseLayer : public Layer {
private:
    int Nn_, Ni_;
public:
    DenseLayer(int Nn, int Ni) : Layer("DenseLayer"), Nn_(Nn), Ni_(Ni) {}
    //costruttore chiama classe base per assegnargli il tipo
    void stampa_dimensioni() const {
        std::cout << tipo_ << ": " << Nn_ << " neuroni, " << Ni_ << " ingressi\n";
        //qua per esempio ho utilizzato tipo_ perchè messo protected
    }
};
int main() {
    DenseLayer d(128, 784);
    d.stampa_tipo();         // metodo ereditato da Layer -> denselayer non ce lo ha
    d.stampa_dimensioni();   // metodo di DenseLayer
    return 0;
}