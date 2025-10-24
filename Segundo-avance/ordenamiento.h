/*
Utilización de "quick-sort" para ordenar las ventas de prendas en el último
*/

#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
//............................................................................
    //Almacenar los datos de cada prenda
struct Prenda {
    string nombre;
    string tipo;
    float precio;
    int ventasMes;
    int ventasSemestre;
};

class ordenamiento{
    public:
    //INICIA EL QUICKSORT: swap entre dos elementos
    void swap(Prenda &a, Prenda &b) {
        Prenda temp = a;
        a = b;
        b = temp;
    }

    //Función para empezar el quicksort
    int particion(vector<Prenda> &prendas, int low, int high) {
        int pivote = prendas[high].ventasMes;
        int i = low-1;

            //Se ordenan de menor a mayor
            for (int j = low; j<high; j++) {
                if (prendas[j].ventasMes > pivote) {
                    i++;
                    swap(prendas[i], prendas[j]);
                }
            }
            swap(prendas[i + 1], prendas[high]);
            return i + 1;
    }

    //Se hace recursiva
    void quicksort(vector<Prenda> &prendas, int low, int high) {
        if (low < high) {
            int pi = particion(prendas, low, high);
            quicksort(prendas, low, pi-1);
            quicksort(prendas, pi+1, high);
        }
    }

    //Se imprimen los resultados
    void verPrendas(const vector<Prenda> &prendas) {
        cout << "MAYORES VENTAS DEL ME" << endl;

        for (size_t i = 0; i < prendas.size(); i++) {
            cout << i+1 << ". " << prendas[i].nombre << endl;
            cout << "   Tipo: " << prendas[i].tipo << endl;
            cout << "   Precio: " << prendas[i].precio << endl;
            cout << "   Ventas último mes: " << prendas[i].ventasMes << endl;
            cout << "   Ventas semestrales: " << prendas[i].ventasSemestre << endl;  
        }
    }
     

};

#endif