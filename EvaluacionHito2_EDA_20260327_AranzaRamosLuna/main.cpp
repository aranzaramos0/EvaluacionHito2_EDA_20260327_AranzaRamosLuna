#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    string nombre;
    string codigo;
    Nodo* siguiente;
};

class FilaAtencion {
private:
    Nodo* inicio;
    Nodo* fin;

public:
    FilaAtencion() {
        inicio = nullptr;
        fin = nullptr;
    }

    ~FilaAtencion() {
        while (inicio != nullptr) {
            desencolar();
        }
    }

    void encolar() {
        string nom, cod;
        cout << "Ingrese el nombre: ";
        cin.ignore();
        getline(cin, nom);
        cout << "Ingrese el código: ";
        getline(cin, cod);

        Nodo* nuevo = new Nodo;
        nuevo->nombre = nom;
        nuevo->codigo = cod;
        nuevo->siguiente = nullptr;

        if (inicio == nullptr) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        cout << "Estudiante registrado con éxito.\n";
    }

    void desencolar() {
        if (inicio == nullptr) {
            cout << "No hay estudiantes en espera.\n";
            return;
        }
        Nodo* temp = inicio;
        cout << "Atendiendo a: " << temp->nombre << " (Código: " << temp->codigo << ")\n";
        inicio = inicio->siguiente;
        if (inicio == nullptr) fin = nullptr;
        delete temp;
    }

    void mostrar() {
        if (inicio == nullptr) {
            cout << "No hay estudiantes registrados.\n";
            return;
        }
        Nodo* actual = inicio;
        int pos = 1;
        cout << "\n=== ESTUDIANTES EN ESPERA ===\n";
        while (actual != nullptr) {
            cout << pos << ". " << actual->nombre << " - " << actual->codigo << "\n";
            actual = actual->siguiente;
            pos++;
        }
    }

    void buscar() {
        if (inicio == nullptr) {
            cout << "No hay estudiantes en la fila.\n";
            return;
        }
        string nombreBuscado;
        cout << "Nombre del estudiante a buscar: ";
        cin.ignore();
        getline(cin, nombreBuscado);

        Nodo* actual = inicio;
        int pos = 1;
        bool encontrado = false;

        while (actual != nullptr) {
            if (actual->nombre == nombreBuscado) {
                cout << "Estudiante encontrado: " << actual->nombre
                     << " (Código: " << actual->codigo << ") - Posición: " << pos << "\n";
                encontrado = true;
                break;
            }
            actual = actual->siguiente;
            pos++;
        }
        if (!encontrado) cout << "No se encontró al estudiante.\n";
    }
};

int main() {
    FilaAtencion cola;
    int op;

    do {
        cout << "\n=== SISTEMA DE GESTIÓN DE TURNOS ===\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Atender estudiante\n";
        cout << "3. Mostrar estudiantes en espera\n";
        cout << "4. Buscar estudiante por nombre\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> op;

        switch (op) {
            case 1: cola.encolar(); break;
            case 2: cola.desencolar(); break;
            case 3: cola.mostrar(); break;
            case 4: cola.buscar(); break;
            case 5: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (op != 5);

    return 0;
}
