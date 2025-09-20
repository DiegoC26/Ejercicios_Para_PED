#include <iostream>   // Para entrada y salida
#include <string>     // Para manejar strings
using namespace std;

// =================== DEFINICIÓN DEL STRUCT ===================
struct Contacto {
    string nombre;   // Nombre del contacto
    string telefono; // Número de teléfono
    string correo;   // Correo electrónico
};

// =================== FUNCIONES ===================

// Agregar un nuevo contacto a la lista dinámica
void agregarContacto(Contacto**& lista, int& size) {
    // 1. Crear un nuevo arreglo con espacio para un contacto más
    Contacto** nuevaLista = new Contacto*[size + 1];

    // 2. Copiar contactos existentes a la nueva lista
    for (int i = 0; i < size; i++) {
        nuevaLista[i] = lista[i];
    }

    // 3. Crear un nuevo contacto
    nuevaLista[size] = new Contacto;

    cout << "\nIngrese nombre: ";
    cin.ignore();                  // Limpiar buffer
    getline(cin, nuevaLista[size]->nombre);

    cout << "Ingrese telefono: ";
    getline(cin, nuevaLista[size]->telefono);

    cout << "Ingrese correo: ";
    getline(cin, nuevaLista[size]->correo);

    // 4. Liberar la lista vieja y actualizar puntero
    delete[] lista;
    lista = nuevaLista;
    size++;

    cout << "✅ Contacto agregado correctamente.\n";
}

// Mostrar todos los contactos
void mostrarContactos(Contacto** lista, int size) {
    if (size == 0) {
        cout << "\n📭 No hay contactos.\n";
        return;
    }
    cout << "\n📒 Lista de contactos:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". "
             << "Nombre: " << lista[i]->nombre
             << " | Teléfono: " << lista[i]->telefono
             << " | Correo: " << lista[i]->correo << endl;
    }
}

// Buscar un contacto por nombre
void buscarContacto(Contacto** lista, int size, const string& nombre) {
    for (int i = 0; i < size; i++) {
        if (lista[i]->nombre == nombre) {
            cout << "\n✅ Contacto encontrado:\n";
            cout << "Nombre: " << lista[i]->nombre
                 << " | Teléfono: " << lista[i]->telefono
                 << " | Correo: " << lista[i]->correo << endl;
            return;
        }
    }
    cout << "❌ Contacto no encontrado.\n";
}

// Eliminar un contacto por nombre
void eliminarContacto(Contacto**& lista, int& size, const string& nombre) {
    int pos = -1;

    // Buscar contacto
    for (int i = 0; i < size; i++) {
        if (lista[i]->nombre == nombre) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "❌ Contacto no encontrado.\n";
        return;
    }

    // Liberar memoria del contacto encontrado
    delete lista[pos];

    // Crear una nueva lista con espacio reducido
    Contacto** nuevaLista = new Contacto*[size - 1];

    // Copiar todos menos el eliminado
    for (int i = 0, j = 0; i < size; i++) {
        if (i != pos) {
            nuevaLista[j++] = lista[i];
        }
    }

    delete[] lista;   // Liberar lista vieja
    lista = nuevaLista;
    size--;

    cout << "🗑️ Contacto eliminado correctamente.\n";
}

// =================== FUNCIÓN PRINCIPAL ===================
int main() {
    Contacto** lista = nullptr; // Lista dinámica de contactos (puntero a puntero)
    int size = 0;               // Número de contactos
    int opcion;

    do {
        cout << "\n--- Agenda de Contactos ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Mostrar contactos\n";
        cout << "3. Buscar contacto por nombre\n";
        cout << "4. Eliminar contacto\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarContacto(lista, size);
                break;
            case 2:
                mostrarContactos(lista, size);
                break;
            case 3: {
                string nombre;
                cout << "\nIngrese nombre a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                buscarContacto(lista, size, nombre);
                break;
            }
            case 4: {
                string nombre;
                cout << "\nIngrese nombre a eliminar: ";
                cin.ignore();
                getline(cin, nombre);
                eliminarContacto(lista, size, nombre);
                break;
            }
            case 0:
                cout << "👋 Saliendo de la agenda...\n";
                break;
            default:
                cout << "⚠️ Opcion invalida.\n";
        }
    } while (opcion != 0);

    // Liberar memoria antes de salir
    for (int i = 0; i < size; i++) {
        delete lista[i];
    }
    delete[] lista;

    return 0;
}
