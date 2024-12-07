#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int id;
    double promedio;
    int edad; 
};
void mostrarMenu();
void agregarEstudiante(Estudiante estudiantes[], int &cantidad);
void mostrarEstudiantes(Estudiante estudiantes[], int cantidad);
void modificarEstudiante(Estudiante estudiantes[], int cantidad);
void eliminarEstudiante(Estudiante estudiantes[], int &cantidad);

int main() {
    Estudiante estudiantes[100];
    int cantidad = 0;
    int opcion;
    do {
        mostrarMenu();
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarEstudiante(estudiantes, cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                modificarEstudiante(estudiantes, cantidad);
                break;
            case 4:
                eliminarEstudiante(estudiantes, cantidad);
                break;
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intenta de nuevo." << endl;
        }
    } while(opcion != 5);

    return 0;
}
void mostrarMenu() {
    cout << "**** Menu de Gestion de Estudiantes ****" << endl;
    cout << "1. Agregar Estudiante" << endl;
    cout << "2. Mostrar Estudiantes" << endl;
    cout << "3. Modificar Estudiante" << endl;
    cout << "4. Eliminar Estudiante" << endl;
    cout << "5. Salir" << endl;
}
void agregarEstudiante(Estudiante estudiantes[], int &cantidad) {
    if (cantidad < 100) {
        cout << "Ingrese el nombre del estudiante: ";
        cin.ignore();
        getline(cin, estudiantes[cantidad].nombre);
        cout << "Ingrese la ID del estudiante: ";
        cin >> estudiantes[cantidad].id;
        cout << "Ingrese la edad del estudiante: "; 
        cin >> estudiantes[cantidad].edad;
        cout << "Ingrese el promedio del estudiante: ";
        cin >> estudiantes[cantidad].promedio;
        cantidad++;
        cout << "Estudiante agregado con exito!" << endl;
    } else {
        cout << "No se pueden agregar mas estudiantes. Capacidad maxima alcanzada." << endl;
    }
}
void mostrarEstudiantes(Estudiante estudiantes[], int cantidad) {
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl;
    } else {
        cout << "Lista de Estudiantes:" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << "ID: " << estudiantes[i].id << ", Nombre: " << estudiantes[i].nombre 
                 << ", Edad: " << estudiantes[i].edad << ", Promedio: " << estudiantes[i].promedio << endl;
        }
    }
}
void modificarEstudiante(Estudiante estudiantes[], int cantidad) {
    int id;
    cout << "Ingrese la ID del estudiante a modificar: ";
    cin >> id;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].id == id) {
            cout << "Estudiante encontrado. Ingrese nuevo nombre: ";
            cin.ignore();
            getline(cin, estudiantes[i].nombre);
            cout << "Ingrese la nueva edad: "; 
            cin >> estudiantes[i].edad;
            cout << "Ingrese el nuevo promedio: ";
            cin >> estudiantes[i].promedio;
            cout << "Informacion actualizada correctamente." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}
void eliminarEstudiante(Estudiante estudiantes[], int &cantidad) {
    int id;
    cout << "Ingrese la ID del estudiante a eliminar: ";
    cin >> id;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].id == id) {
            for (int j = i; j < cantidad - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            cantidad--;
            cout << "Estudiante eliminado con exito." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado." << endl;
    }
}

