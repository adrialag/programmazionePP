#include <chrono>
#include <iostream>

const int N = 500;
double A[N][N], B[N][N], C[N][N];  // globali, come in C

void prodotto() {                  // C = A B
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            double a = A[i][k];
            for (int j = 0; j < N; j++) {
                C[i][j] += a * B[k][j];
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0.001 * (i + j);
            B[i][j] = 0.001 * (i - j);
        }
    }
    auto inizio = std::chrono::high_resolution_clock::now();
    prodotto();
    auto fine = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<
        std::chrono::milliseconds>(fine - inizio).count();
    std::cout << "C[1][2] = " << C[1][2] << "\n";
    std::cout << "tempo: " << ms << " ms\n";
    return 0;
}