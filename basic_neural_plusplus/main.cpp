#include <iostream>
#include <cmath>

double sigmoid(double valore);
double dx_sigmoid(double valore);

int main(){
    std::cout << "Inizio progetto BASIC_NEURAL++" << std::endl;
    
    //TASK 2 - fare un gradient descent
    /*
    double lr;
    //due cicli for provano diversi learning rate
    for(int j = 1; j<6; j++){
        double x = 1.0;
        lr = j * 0.25;
        std::cout << "Inizio discesa con " << lr << std::endl;
        for(int i=0; i<5; i++){
            x = x - lr * 2 * x;
            std::cout << x << std::endl;
            if(x == 0){
                std::cout << "Raggiunta soglia perdita 0" << std::endl;
                break;
            }
        }
    }
    */
    
    //TASK 3 - rete di due neuroni
    /*
    double x = 1.0, w1 = 1.0, w2 = 1.0, y = 1.0;
    double z1, a1, z2, a2, E;
    double d1, d2;
    //Forward propagation
    z1 = x * w1;
    a1 = sigmoid(z1);
    z2 = a1 * w2;
    a2 = sigmoid(z2);
    E = (a2 - y) * (a2 - y); //E sarebbe la funzione di costa -> differenza dal target
    std::cout << "E = "<< E << std::endl;
    //Backward propagation -> devo inserire tutte le delte
    d2 = 2 * (a2 - y) * dx_sigmoid(z2);
    d1 = d2 * w2 * dx_sigmoid(z1);
    std::cout << "Derivata = " << d1 << std::endl; 
    */

    //TASK 5 - rete che si aggiorna
    double x = 1.0, w1 = 1.0, w2 = 1.0, y = 1.0;
    double z1, a1, z2, a2, E;
    double d1, d2, dE_dw1, dE_dw2;
    double lr = 1.0;//learning rate
    for(int t=0; t<200; t++){//la rete fa 200 passi per aggiornarsi
        //inizio con il forward identico alla task precedente
        z1 = x * w1;
        a1 = sigmoid(z1);
        z2 = a1 * w2;
        a2 = sigmoid(z2);
        E = (a2 - y)*(a2 - y);
        if(t%20 == 0){
            std::cout << "Al passo " << t << ": E = " << E << ", w1 = " << w1 << ", w2 = " << w2 << std::endl;
        }
        //faccio i passaggi della backpropagation per aggiornare il tutto
        d2 = 2 * (a2 - y) * dx_sigmoid(z1);
        d1 = d2 * w2 * dx_sigmoid(z1);
        dE_dw2 = d2 * a1;
        dE_dw1 = d1;//qua ci sarebbe un per 1
        //aggiorno i pesi
        w1 = w1 - lr * dE_dw1;
        w2 = w2 - lr * dE_dw2;
    }

    return 0;
}

double sigmoid(double valore){
    return 1.0 / (1.0 + std::exp(-1.0 * valore));  
}

double dx_sigmoid(double valore){
    return std::exp(-1.0 * valore) / ((1+std::exp(-1.0 * valore))*(1+std::exp(-1.0*valore)));
}