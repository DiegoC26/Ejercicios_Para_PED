#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Llenar matriz con valores aleatorios
void llenarMatriz(vector<vector<int>>& matriz, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100; // 0 a 99
        }
    }
}

// Mostrar matriz
void mostrarMatriz(const vector<vector<int>>& matriz, int n) {
    cout << "\n📋 Matriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Suma de la diagonal principal
int sumaDiagonalPrincipal(const vector<vector<int>>& matriz, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz[i][i];
    }
    return suma;
}

// Suma de la diagonal secundaria
int sumaDiagonalSecundaria(const vector<vector<int>>& matriz, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz[i][n - 1 - i];
    }
    return suma;
}

// Transponer matriz
void transponerMatriz(vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matriz[i][j], matriz[j][i]);
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;

    // Crear matriz dinámica usando vector
    vector<vector<int>> matriz(n, vector<int>(n));

    // Llenar y mostrar matriz
    llenarMatriz(matriz, n);
    mostrarMatriz(matriz, n);

    // Calcular sumas
    cout << "\n🔹 Suma diagonal principal: " << sumaDiagonalPrincipal(matriz, n) << endl;
    cout << "🔹 Suma diagonal secundaria: " << sumaDiagonalSecundaria(matriz, n) << endl;

    // Transponer y mostrar
    transponerMatriz(matriz, n);
    cout << "\nMatriz transpuesta:\n";
    mostrarMatriz(matriz, n);

    return 0;
}
