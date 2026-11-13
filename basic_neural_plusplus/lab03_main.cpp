#include <iostream>
#include <cmath>

double relu(double x);
double relu_derivative(double x);
double sigmoid(double x);
double sigmoid_derivative(double x);
double tanh_act(double x);
double tanh_derivative(double x);
double sigmoid_numerical(double x, double h);
double tanh_numerical(double x, double h);

int main(){
    //ciclo for per testare un po' di valori
    std::cout << "Tabella funzioni di attivazione" << std::endl;
    for(int i=-5; i<=5; i++){
        double x = i;
        std::cout << x << "\t" << relu(x) << "\t" << relu_derivative(x)
                << "\t" << sigmoid(x) << "\t" << sigmoid_derivative(x)
                << "\t" << tanh_act(x) << "\t" << tanh_derivative(x) << std::endl;
    }
    std::cout << "Confronto derivate numeriche e analitiche" << std::endl;
    double h = 1e-5;
    for(int i=-10; i<=10; i++){
        double val = i * 0.5;
        double d1 = std::fabs(sigmoid_derivative(val) - sigmoid_numerical(val, h));
        double d2 = std::fabs(tanh_derivative(val) - tanh_numerical(val, h));
        if(d2<1e-6 && d1<1e-6){
            std::cout << "Successo per val = " << val << std::endl;
        }
        else{
            std::cout << "Fallito per val = " << val << std::endl;  
        }
    }
    return 0;
}

//funzione d'attivazione relu
double relu(double x){
    if(x>0.0){
        return x;
    }
    else{
        return 0.0;
    }
}
//derivata delal relu
double relu_derivative(double x){
    if(x>0.0){
        return 1.0;
    }
    else{
        return 0.0;
    }
}
//funzione di attivazione sigmoide
double sigmoid(double x){
    return 1/(1+std::exp(-1.0*x));
}
//derivata della sigmoide
double sigmoid_derivative(double x){
    double val = sigmoid(x);
    return val * (1 - val);
}
//funzione di attivazione tangente iperbolica
double tanh_act(double x){
    return std::tanh(x);
}
//derivata di tanh
double tanh_derivative(double x){
    double val = tanh_act(x);
    return 1 - val*val;
}
//funzioni delle derivate alle differenze finite
double sigmoid_numerical(double x, double h){
    return (sigmoid(x+h)-sigmoid(x-h))/(2*h);
}
double tanh_numerical(double x, double h){
    return (tanh_act(x+h)-tanh_act(x-h))/(2*h);
}