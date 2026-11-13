#include <iostream>

//costruiamo la struct per le matrici
struct CMatrix{
    int rows;
    int cols;
    double *data;
};
//scrivo alcune funzioni per poter gestire le matrici
CMatrix cmat_alloc(int rows, int cols){
    CMatrix m;
    //imposta righe, colonne e puntatore con lo spazio necessario
    m.rows = rows;
    m.cols = cols;
    m.data = new double[rows*cols];
    return m;
}
void cmat_free(CMatrix& m){
    delete[] m.data;
    m.data = nullptr;
    m.rows = 0;
    m.cols = 0;
}
double cmat_get(const CMatrix& m, int i, int j){
    return m.data[i* m.cols + j];
}
void cmat_set(CMatrix& m, int i, int j, double val){
    m.data[i * m.cols + j] = val;
}
//funzione per la vera e proprio rete neurale
void layer_forward(const CMatrix& w, const double* x, const double* b, double* z){
    for(int j=0; j<w.rows; j++){
        double acc = 0;
        for(int i=0; i<w.cols; i++){
            acc = acc + cmat_get(w, j, i) * x[i];
        }
        z[j] = acc + b[j];
    }
}

int main(){
    //il programma chiede di inserire il numero di neuroni
    int N;
    std::cout << "Inserire il numero di neuroni" << std::endl;
    std::cin >> N;
    if(N<=0){
        std::cout << "Numero di neuroni non valido" << std::endl;
        return 1;
    }
    std::cout << "Numero neuroni inserito : " << N << std::endl;
    //riservo memoria nell'heap -> due diverse liste
    //new serve proprio a dire predi memoria heap
    double* input = new double[N];
    double* pesi = new double[N];
    //inizializzazione con valori di prova
    for(int i=0; i<N; i++){
        input[i] = 1.0;
        pesi[i] = 0.01;
    }
    //calcolo del prodotto scalare più il bias
    double z = 0.0;
    double b = 0.5;
    for(int i=0; i<N; i++){
        z += pesi[i]*input[i];
    }
    z += b;
    std::cout << "Il calcolo ha prodotto " << z << std::endl;
    delete[] input;
    delete[] pesi;
    //TASK 6
    int M = 3;
    std::cout << "Riga 72" << std::endl;
    CMatrix w = cmat_alloc(M, N);
    std::cout << "Riga 74" << std::endl;
    //abbiamo creato una matrice con 3 righe 784 righe sono i pesi di 3 neuroni con 784 ingressi
    //dobbiamo creare le altre liste utili
    //x sarà la lista dei miei input
    double* x = new double[N];
    double* z_out = new double[M];
    double* bias = new double[M];
    std::cout << "Riga 81" << std::endl;
    for(int i=0; i<3; i++){
        bias[i] = 0.5;
    }
    for(int j=0; j<N; j++){
        x[j] = 1.0;
        for(int i=0; i<M; i++){
            cmat_set(w, i, j, 0.01*(i+1));
        }
    }
    layer_forward(w, x, bias, z_out);
    std::cout << "Risultati ottenuti" << std::endl;
    std::cout << z_out[0] << std::endl;
    std::cout << z_out[1] << std::endl;
    std::cout << z_out[2] << std::endl;

    //libero tutta la memoria utilizzata
    cmat_free(w);
    delete[] bias;
    delete[] z_out;
    delete[] x; 
    return 0;
}