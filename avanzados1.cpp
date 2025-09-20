#include <iostream>   // Librería para entrada/salida de datos (cout, cin)
#include <vector>     // Librería para usar vectores (arreglos dinámicos)
#include <string>     // Librería para manejar strings (texto)
using namespace std;  // Evita escribir std:: en cout, cin, string, etc.

// Estructura que representa un producto en el inventario
struct Producto {
    int id;         // Identificador único
    string nombre;  // Nombre del producto
    double precio;  // Precio unitario
    int cantidad;   // Cantidad en inventario
};

// ================= FUNCIONES =================

// Agregar un nuevo producto al inventario
void agregarProducto(vector<Producto>& inventario) {
    Producto p;  // Objeto temporal donde guardamos los datos

    cout << "\nIngrese ID del producto: ";
    cin >> p.id;  // Leemos el ID

    cout << "Ingrese nombre: ";
    cin.ignore();            // Ignora el salto de línea pendiente
    getline(cin, p.nombre);  // Leemos el nombre completo

    cout << "Ingrese precio: ";
    cin >> p.precio;  // Leemos el precio

    cout << "Ingrese cantidad: ";
    cin >> p.cantidad;  // Leemos la cantidad

    inventario.push_back(p);  // Agregamos el producto al vector
    cout << " Producto agregado correctamente.\n";
}

// Buscar producto por ID (devuelve posición o -1 si no existe)
int buscarPorId(const vector<Producto>& inventario, int id) {
    for (size_t i = 0; i < inventario.size(); i++) { // Recorremos todo el inventario
        if (inventario[i].id == id) { // Si el ID coincide
            return i; // Devolvemos la posición
        }
    }
    return -1; // No se encontró
}

// Actualizar la cantidad de un producto
void actualizarCantidad(vector<Producto>& inventario) {
    int id, nuevaCantidad;
    cout << "\nIngrese ID del producto a actualizar: ";
    cin >> id;

    int pos = buscarPorId(inventario, id); // Buscamos producto
    if (pos == -1) {
        cout << "Producto no encontrado.\n";
    } else {
        cout << "Cantidad actual: " << inventario[pos].cantidad << endl;
        cout << "Ingrese nueva cantidad: ";
        cin >> nuevaCantidad;
        inventario[pos].cantidad = nuevaCantidad; // Actualizamos
        cout << "Cantidad actualizada.\n";
    }
}

// Calcular el valor total del inventario
void calcularValorTotal(const vector<Producto>& inventario) {
    double total = 0; // Acumulador
    for (const auto& p : inventario) { // Recorremos todos los productos
        total += p.precio * p.cantidad; // Sumamos precio * cantidad
    }
    cout << "\n Valor total del inventario: $" << total << endl;
}

// Mostrar todos los productos del inventario
void mostrarInventario(const vector<Producto>& inventario) {
    cout << "\n Inventario:\n";
    for (const auto& p : inventario) { // Recorremos todos
        cout << "ID: " << p.id 
             << " | Nombre: " << p.nombre
             << " | Precio: $" << p.precio
             << " | Cantidad: " << p.cantidad << endl;
    }
}

// ================= PROGRAMA PRINCIPAL =================
int main() {
    vector<Producto> inventario; // Vector dinámico que guarda todos los productos
    int opcion; // Variable para el menú

    do {
        // Menú de opciones
        cout << "\n--- Sistema de Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto por ID\n";
        cout << "3. Actualizar cantidad\n";
        cout << "4. Calcular valor total\n";
        cout << "5. Mostrar inventario\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Ejecutamos la opción elegida
        switch (opcion) {
            case 1:
                agregarProducto(inventario); 
                break;

            case 2: {
                int id;
                cout << "\nIngrese ID a buscar: ";
                cin >> id;
                int pos = buscarPorId(inventario, id);
                if (pos == -1) {
                    cout << " Producto no encontrado.\n";
                } else {
                    cout << " Encontrado -> "
                         << inventario[pos].nombre 
                         << " (Cantidad: " << inventario[pos].cantidad << ")\n";
                }
                break;
            }

            case 3:
                actualizarCantidad(inventario);
                break;

            case 4:
                calcularValorTotal(inventario);
                break;

            case 5:
                mostrarInventario(inventario);
                break;

            case 0:
                cout << " Saliendo del sistema...\n";
                break;

            default:
                cout << " Opción inválida.\n";
        }
    } while (opcion != 0); // Repite hasta que el usuario elija salir

    return 0; // Fin del programa
}
