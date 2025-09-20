#include <iostream>
#include <string>
using namespace std;

// =================== STRUCT ===================
struct Estudiante {
    string carnet;   // Carnet del estudiante
    string nombre;   // Nombre completo
    float promedio;  // Promedio final
};

// =================== FUNCIONES ===================

// Ingresar estudiantes en el arreglo dinámico
void ingresarEstudiantes(Estudiante* estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "Carnet: ";
        cin >> estudiantes[i].carnet;
        cin.ignore(); // Limpiar buffer
        cout << "Nombre: ";
        getline(cin, estudiantes[i].nombre);
        cout << "Promedio: ";
        cin >> estudiantes[i].promedio;
    }
}

// Mostrar todos los estudiantes
void mostrarEstudiantes(Estudiante* estudiantes, int n) {
    cout << "\n Lista de Estudiantes:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " 
             << estudiantes[i].carnet << " | " 
             << estudiantes[i].nombre << " | Promedio: " 
             << estudiantes[i].promedio << endl;
    }
}

// Ordenar estudiantes por promedio descendente (burbuja)
void ordenarPorPromedio(Estudiante* estudiantes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (estudiantes[j].promedio < estudiantes[j + 1].promedio) {
                // Intercambiar usando un puntero temporal
                Estudiante temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
}

// Mostrar el estudiante con mejor y peor promedio
void mostrarMejorPeor(Estudiante* estudiantes, int n) {
    if (n == 0) {
        cout << "\nNo hay estudiantes registrados.\n";
        return;
    }
    cout << "\n Mejor promedio:\n"
         << estudiantes[0].carnet << " | "
         << estudiantes[0].nombre << " | "
         << estudiantes[0].promedio << endl;

    cout << "\n Peor promedio:\n"
         << estudiantes[n - 1].carnet << " | "
         << estudiantes[n - 1].nombre << " | "
         << estudiantes[n - 1].promedio << endl;
}

// =================== PROGRAMA PRINCIPAL ===================
int main() {
    int n;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;

    // Crear arreglo dinámico de estudiantes
    Estudiante* estudiantes = new Estudiante[n];

    // Ingresar datos
    ingresarEstudiantes(estudiantes, n);

    // Mostrar lista original
    mostrarEstudiantes(estudiantes, n);

    // Ordenar por promedio
    ordenarPorPromedio(estudiantes, n);

    // Mostrar lista ordenada
    cout << "\nLista ordenada por promedio (descendente):\n";
    mostrarEstudiantes(estudiantes, n);

    // Mostrar mejor y peor promedio
    mostrarMejorPeor(estudiantes, n);

    // Liberar memoria
    delete[] estudiantes;

    return 0;
}
