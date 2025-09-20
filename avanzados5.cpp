#include <iostream>
#include <string>
using namespace std;

// =================== STRUCT ===================
struct Cuenta {
    int numeroCuenta;     // Número único de la cuenta
    string nombreTitular; // Nombre del titular
    double saldo;         // Saldo actual
};

// =================== FUNCIONES ===================

// Ingresar datos de las cuentas
void ingresarCuentas(Cuenta* cuentas, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nCuenta #" << i + 1 << endl;
        cout << "Número de cuenta: ";
        cin >> cuentas[i].numeroCuenta;
        cin.ignore(); // Limpiar buffer
        cout << "Nombre del titular: ";
        getline(cin, cuentas[i].nombreTitular);
        cout << "Saldo inicial: ";
        cin >> cuentas[i].saldo;
    }
}

// Mostrar todas las cuentas
void mostrarCuentas(Cuenta* cuentas, int n) {
    cout << "\n Cuentas del banco:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cuenta: " << cuentas[i].numeroCuenta
             << " | Titular: " << cuentas[i].nombreTitular
             << " | Saldo: $" << cuentas[i].saldo << endl;
    }
}

// Buscar cuenta por número, devuelve índice o -1 si no existe
int buscarCuenta(Cuenta* cuentas, int n, int numero) {
    for (int i = 0; i < n; i++) {
        if (cuentas[i].numeroCuenta == numero)
            return i;
    }
    return -1;
}

// Depositar dinero
void depositar(Cuenta* cuentas, int n) {
    int numero;
    double monto;
    cout << "\nIngrese número de cuenta para depositar: ";
    cin >> numero;
    int pos = buscarCuenta(cuentas, n, numero);
    if (pos == -1) {
        cout << " Cuenta no encontrada.\n";
        return;
    }
    cout << "Monto a depositar: ";
    cin >> monto;
    if (monto <= 0) {
        cout << " Monto inválido.\n";
        return;
    }
    cuentas[pos].saldo += monto;
    cout << " Depósito realizado. Saldo actual: $" << cuentas[pos].saldo << endl;
}

// Retirar dinero con validación de fondos
void retirar(Cuenta* cuentas, int n) {
    int numero;
    double monto;
    cout << "\nIngrese número de cuenta para retirar: ";
    cin >> numero;
    int pos = buscarCuenta(cuentas, n, numero);
    if (pos == -1) {
        cout << " Cuenta no encontrada.\n";
        return;
    }
    cout << "Monto a retirar: ";
    cin >> monto;
    if (monto <= 0 || monto > cuentas[pos].saldo) {
        cout << " Fondos insuficientes o monto inválido.\n";
        return;
    }
    cuentas[pos].saldo -= monto;
    cout << " Retiro realizado. Saldo actual: $" << cuentas[pos].saldo << endl;
}

// Transferir entre cuentas
void transferir(Cuenta* cuentas, int n) {
    int origen, destino;
    double monto;
    cout << "\nIngrese número de cuenta origen: ";
    cin >> origen;
    int posOrigen = buscarCuenta(cuentas, n, origen);
    if (posOrigen == -1) {
        cout << " Cuenta origen no encontrada.\n";
        return;
    }

    cout << "Ingrese número de cuenta destino: ";
    cin >> destino;
    int posDestino = buscarCuenta(cuentas, n, destino);
    if (posDestino == -1) {
        cout << " Cuenta destino no encontrada.\n";
        return;
    }

    cout << "Monto a transferir: ";
    cin >> monto;
    if (monto <= 0 || monto > cuentas[posOrigen].saldo) {
        cout << " Fondos insuficientes o monto inválido.\n";
        return;
    }

    cuentas[posOrigen].saldo -= monto;
    cuentas[posDestino].saldo += monto;
    cout << " Transferencia realizada. Nuevo saldo:\n";
    cout << "Cuenta origen: $" << cuentas[posOrigen].saldo << "\n";
    cout << "Cuenta destino: $" << cuentas[posDestino].saldo << endl;
}

// Calcular saldo total del banco
double saldoTotal(Cuenta* cuentas, int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += cuentas[i].saldo;
    }
    return total;
}

// =================== PROGRAMA PRINCIPAL ===================
int main() {
    int n;
    cout << "Ingrese el número de cuentas a registrar: ";
    cin >> n;

    // Crear arreglo dinámico de cuentas
    Cuenta* cuentas = new Cuenta[n];

    // Ingresar datos
    ingresarCuentas(cuentas, n);

    int opcion;
    do {
        cout << "\n--- Menú Banco ---\n";
        cout << "1. Mostrar cuentas\n";
        cout << "2. Depositar dinero\n";
        cout << "3. Retirar dinero\n";
        cout << "4. Transferir dinero\n";
        cout << "5. Saldo total del banco\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarCuentas(cuentas, n);
                break;
            case 2:
                depositar(cuentas, n);
                break;
            case 3:
                retirar(cuentas, n);
                break;
            case 4:
                transferir(cuentas, n);
                break;
            case 5:
                cout << "\n Saldo total del banco: $" << saldoTotal(cuentas, n) << endl;
                break;
            case 0:
                cout << " Saliendo del banco...\n";
                break;
            default:
                cout << " Opción inválida.\n";
        }

    } while(opcion != 0);

    // Liberar memoria
    delete[] cuentas;

    return 0;
}
