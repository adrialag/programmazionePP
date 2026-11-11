#include <iostream>
#include <vector>
int main() {
    std::vector<double> v;//posso metterci qualsiasi tipo -> anche i layer in C no
    //estende il concetto di array
    v.push_back(1.5);//metodo a disposizione per poter aggiungere oggetti
    v.push_back(2.5);//posso poi accedere a questi come un array v[0]
    std::cout << v.size() << " " << v[0] << "\n";
    for (double x : v) {//metodo nuovo rispetto al C, molto simile al python
        std::cout << x << "\n";
    }
    return 0;
}