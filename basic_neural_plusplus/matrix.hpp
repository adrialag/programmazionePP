#ifndef MATRIX_HPP
#define MATRIX_HPP

//qua vado a definire la mia classe nel file header (.hpp) faccio solo le dichiarazioni
//tutte le funzioni sono implementate nel file matrix.cpp
class Matrix {
private:
    // i miei dati private
    int rows;
    int cols;
    double* data;  // rows * cols, row-major

public:
    //costruttore della classe
    Matrix(int r, int c);
    //metodo con tilde è il distruttore
    ~Matrix();
    //un costruttore diverso -> creerà una copia della matrice
    Matrix(const Matrix& altra);
    //ridefinisco un operatore -> posso assegnare così una matrice
    Matrix& operator=(const Matrix& altra);

    //get e set per ottenere e impostare valori all'interno della matrice
    double get(int r, int c) const;
    void set(int r, int c, double val);
    //restituiscono rispettivamente il numero di colonne e di righe
    int getRows() const;
    int getCols() const;
};

#endif