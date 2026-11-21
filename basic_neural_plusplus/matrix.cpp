#include "matrix.hpp"
#include <stdexcept>   // invalid_argument, out_of_range


//devo scrivere tutte le funzioni per le matrici
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument(
            "Matrix: dimensioni non positive");
    }
    //alloca la memoria necessaria
    data = new double[rows * cols];
    //inizializza tutta la memoria a 0.0
    for (int i = 0; i < rows * cols; i++) {
        data[i] = 0.0;
    }
}

Matrix::~Matrix() {
    //le altre variabili stanno nello stack e quindi il compilatore sa quanto eliminare
    //bisogna specificare quanto eliminare dall'heap
    delete[] data;
}
// elemento (r, c): la riga r comincia alla cella r * cols
double Matrix::get(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix::get: indici fuori dai limiti");
    }
    //restituisce semplicemente l'elemento
    return data[r * cols + c];
}
//imposto un determinato valore con il metodo set
void Matrix::set(int r, int c, double val){
    //aggiungo lo stesso check su r e c presente in get
    if (r < 0 || r >= rows || c < 0  || c>= cols) {
        throw std::out_of_range("Matrix::set:indici fuori dai limiti");
    }
    //imposta il valore voluto
    data[r * cols + c] = val;
}

//metodo definito nella stessa riga
int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

//Applicazione della regola del tre
//se non vado a definire queste due funzioni scoppia tutto
//più matrici hanno puntatori che puntano allo stesso array
Matrix::Matrix(const Matrix& altra)
    : rows(altra.rows), cols(altra.cols),
      data(new double[altra.rows * altra.cols]) {
    for (int i = 0; i < rows * cols; i++) {
        data[i] = altra.data[i];
    }
}
//ultimo step della regola del 3
//riassegnare l'operatore = per copiare da un'altra matrice
Matrix& Matrix::operator=(const Matrix& altra) {
    if (this == &altra) return *this;  // a. auto-assegnamento: m = m
    else{
        //elimino i vecchi data
        delete[] data;
        //fisso le nuove colonne e righe
        rows = altra.rows;
        cols = altra.cols;
        data = new double[rows * cols];
        //con un ciclo for riassegno tutti i valori di data
        for (int i=0; i< rows * cols; i++){
            data[i] = altra.data[i];
        }
    }
    //restituisce l'oggetto derefenrenziato
    return *this;                      
}