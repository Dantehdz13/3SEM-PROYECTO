#ifndef EDITAR_H
#define EDITAR_H
#include <iostream>
#include <iomanip>
#include <iostream>
#include "ordenamiento.h"
#include "mejor_venta.h"

using namespace std;


struct nodoPrenda {
    Prenda prenda;
    nodoPrenda* siguiente;
    nodoPrenda(Prenda p) : prenda(p), siguiente(nullptr) {}
};

extern nodoPrenda* listaPrincipal;
//............................................................................
//Guardar los datos en el archivo
void guardarCosas(const string& nombreArchivo) {
    ofstream file(nombreArchivo);

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo para guardar los datos." << endl;
        return;
    }

    file << "Nombre,Tipo,Precio,VentasMes,VentasSemestre" << endl;


        nodoPrenda* tmp = listaPrincipal;
        while(tmp != nullptr){
            file << tmp->prenda.nombre << "," 
                << tmp->prenda.tipo << ","
                << tmp->prenda.precio << ","
                << tmp->prenda.ventasMes << ","
                << tmp->prenda.ventasSemestre << "\n";
            tmp = tmp->siguiente;
    }

    file.close();
    cout << "Datos guardados correctamente..."<< endl;
}
//............................................................................
//agregar nuevas prendas
void agregarCosas(vector<Prenda>& prendas) {
    Prenda nuevaPrenda;
    cout << "Ingrese el nombre de la prenda: " << endl;
    getline(cin, nuevaPrenda.nombre);
    cout << "Ingrese el tipo de prenda: ";
    getline(cin, nuevaPrenda.tipo);
    cout << "Ingrese el precio de la prenda: ";
    cin >> nuevaPrenda.precio;
    cout << "Ingrese las ventas del mes: ";
    cin >> nuevaPrenda.ventasMes;
    cout << "Ingrese las ventas del semestre: ";
    cin >> nuevaPrenda.ventasSemestre;

    if (nuevaPrenda.precio < 0 || nuevaPrenda.ventasMes < 0 || nuevaPrenda.ventasSemestre < 0) {
        cout << "No pueden existir valores negativos" << endl;
        return;
    }
    prendas.push_back(nuevaPrenda);
    nodoPrenda* nuevo = new nodoPrenda(nuevaPrenda);
    nuevo->siguiente = listaPrincipal;
    listaPrincipal = nuevo;
    cout << "Prenda agregada" << endl;

    cout << "¿Guardar los datos? s/n" << endl;
    char opcion;
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        guardarCosas("ventas_otros.csv");
    }
}
//............................................................................
//editar una prenda ya ingresada
void editarCosas(vector<Prenda>& prendas) {
    if (prendas.empty()) {
        cout << "No hay nada para editar" << endl;
        return;
    }
    cout << "Prendas para editar: " << endl;

    for (size_t i = 0; i < prendas.size(); ++i) {
        cout << i + 1 << ". " << prendas[i].nombre << " Ventas: " << prendas[i].ventasMes << endl;
    }  

    cout << "Selecciona (por número) la prenda que deseas editar: ";
    int sel;
    cin >> sel;

    if (sel < 1 || sel > prendas.size()) {
        cout << "Selección inválida." << endl;
        return;
    }

    Prenda& prenda = prendas[sel - 1];
    string nombreOriginal = prenda.nombre;

    cout << "Editando prenda: " << prenda.nombre << endl;
    cout << "1. Editar nombre" << endl;
    cout << "2. Editar tipo" << endl;
    cout << "3. Editar precio" << endl;
    cout << "4. Editar ventas del mes" << endl;
    cout << "5. Editar ventas del semestre" << endl;
    cout << "6. Editar todo" << endl;

    int opcionEditar;
    cin >> opcionEditar;
    cin.ignore(); 

    switch (opcionEditar) {
        case 1:
            cout << "Nuevo nombre: ";
            getline(cin, prenda.nombre);
            break;
        case 2:
            cout << "Nuevo tipo: ";
            getline(cin, prenda.tipo);
            break;
        case 3:
            cout << "Nuevo precio: ";
            cin >> prenda.precio;
            break;
        case 4:
            cout << "Nuevas ventas del mes: ";
            cin >> prenda.ventasMes;
            break;
        case 5:
            cout << "Nuevas ventas del semestre: ";
            cin >> prenda.ventasSemestre;
            break;
        case 6:
            cout << "Nuevo nombre: ";
            getline(cin, prenda.nombre);
            cout << "Nuevo tipo: ";
            getline(cin, prenda.tipo);
            cout << "Nuevo precio: ";
            cin >> prenda.precio;
            cout << "Nuevas ventas del mes: ";
            cin >> prenda.ventasMes;
            cout << "Nuevas ventas del semestre: ";
            cin >> prenda.ventasSemestre;
            break;
        default:
            cout << "Error" << endl;
            return;
    }

    cout << "Prenda editada" << endl;
    nodoPrenda* tmp = listaPrincipal;
    while(tmp != nullptr) {
        if(tmp->prenda.nombre == nombreOriginal) {
            tmp->prenda = prenda;
            break;
        }
        tmp = tmp->siguiente;
    }
    cout << "¿Guardar los datos? s/n" << endl;
    char opcion;
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        guardarCosas("ventas_otros.csv");
    }
}
//............................................................................
//Eliminar una prenda
void eliminarCosas(vector<Prenda>& prendas) {
    if (prendas.empty()) {
        cout << "No hay nada para eliminar" << endl;
        return;
    }

    cout << "Prendas para eliminar: " << endl;
    for (size_t i = 0; i < prendas.size(); ++i) {
        cout << i + 1 << ". " << prendas[i].nombre << "_" << prendas[i].tipo << endl;
    }
    cout << "Selecciona (por número) la prenda que deseas eliminar: ";
    int sel;
    cin >> sel;

    if (sel < 1 || sel > prendas.size()) {
        cout << "Selección inválida." << endl;
        return;
    }

    string nombreEliminada = prendas[sel - 1].nombre;
    cout << "¿Estás seguro de que deseas eliminar " << nombreEliminada << "? s/n: ";
    char confirmacion;
    cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S') {
        prendas.erase(prendas.begin() + sel - 1);
        nodoPrenda* tmp = listaPrincipal;
        nodoPrenda* anterior = nullptr;
        
        while(tmp != nullptr && tmp->prenda.nombre != nombreEliminada) {
            anterior = tmp;
            tmp = tmp->siguiente;
        }
        
        if(tmp != nullptr) {
            if(anterior == nullptr) {
                listaPrincipal = tmp->siguiente;
            } else {
                anterior->siguiente = tmp->siguiente;
            }
            delete tmp;
        }
        cout << "Prenda eliminada." << endl;

        cout << "¿Guardar los datos? s/n" << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            guardarCosas("ventas_otros.csv");
        }
    } else {
        cout << "Eliminación cancelada." << endl;
    }
}

nodoPrenda* listaPrincipal = nullptr;

#endif 