#include <iostream>

class Vettore2D {
private:
    double x_, y_;
public:
    Vettore2D(double x, double y) : x_(x), y_(y) {}
    friend std::ostream& operator<<(std::ostream& os,//è una funzione non dipende se private o pubic
                                    const Vettore2D& v);
    //chiamare friend serve a concedere il permesso di accedere ai membri privati
    //alternativa usare i getter -> poi sono accessibili a tutti i membri
};

std::ostream& operator<<(std::ostream& os, const Vettore2D& v) {
    os << "(" << v.x_ << ", " << v.y_ << ")";//accedo a metodi privati tanto ho la funzione friend
    return os;
}

int main() {
    Vettore2D v(3.0, 4.0);
    std::cout << "v = " << v << "\n";//non devo chiamre la funzione, ho ridefinito l'operatore
    return 0;
}