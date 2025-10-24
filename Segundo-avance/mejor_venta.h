#ifndef MEJOR_VENTA_H
#define MEJOR_VENTA_H
#include <iostream>
#include <iomanip>
#include <iostream>
#include "ordenamiento.h"

using namespace std;
//............................................................................
//Nodo de la lista enlazada
struct NodoPrenda {
    Prenda prenda;
    float ganTotal;
    //puntero a la siguiente
    NodoPrenda* sig;

    //Constructor del puntero
    NodoPrenda(const Prenda & p): prenda(p), sig(0) {
        ganTotal = p.precio* p.ventasMes; 
    }
};

class ListaProfit {
    private:
        //atributos privaods
        NodoPrenda* cabeza;
        int cant;  
    
    public:
        /*
        Constructores y destructores del método de las ganancias para despleg-
        ar en pantalla
        */
        ListaProfit() : cabeza(0), cant(0) {}
        ~ListaProfit() {
            while (cabeza !=0) {
                NodoPrenda* tempo = cabeza;
                cabeza = cabeza-> sig;
                delete tempo;
            }
        }

        //Inseta la prenda (de mayor a menor ganancia)
        void insertOrden(const Prenda& prenda) {
            NodoPrenda* nuevo = new NodoPrenda(prenda);

            /*
            caso 1: lista vacía. El nurvo apunta al antiguo puntero, después
            se vuelve el primero
            */
           if (cabeza == 0|| nuevo->ganTotal > cabeza->ganTotal) {
                nuevo->sig = cabeza;
                cabeza = nuevo;
           }
           else {
            /*
            Caso 2: se busca la posición en la lista. Va avanzando mientras el que
            siga tenga más ganancias. 
            */
            NodoPrenda* actual = cabeza;

            while (actual->sig !=0 && actual->sig->ganTotal > nuevo->ganTotal) {
                actual = actual->sig;
            }

            //Se inserta  entre actual y actual->sig
            nuevo->sig = actual->sig;
            actual->sig = nuevo;
           }

           cant ++;
        }

        /*
        Se obtiene la prenda que ha significado más ganancias a la tienda
        */
       NodoPrenda* obtenerMax() {
        if (cabeza == 0) {
            cerr << "La lista no tienen ningún elemento" << endl;
            return 0;
        }
        return cabeza;
       }

       //Vemos si está vacía
       bool estaVacia() {
            return cabeza == 0;
       }

       int tamaño() {
        return cant;
       }

       // prendas más rentables para seguir en stock
        void mostrarTopGanancias(int n) {

        cout << "las " << n << " mejores ventas del mes" << endl;
        
        if (cabeza == 0) {
            cout << "No hay prendas en la lista" << endl;
            return;
        }
        
        NodoPrenda* actual = cabeza;
        int count = 0;
        
        while (actual != nullptr && count < n) {
            cout << count + 1 << ". " << actual->prenda.nombre << endl;
            cout << "   Tipo: " << actual->prenda.tipo << endl;
            cout << "   Precio: " << fixed << setprecision(2) << actual->prenda.precio << endl;
            cout << "   Ventas del mes: " << actual->prenda.ventasMes << endl;
            cout << "   GANANCIA TOTAL: $" << actual->ganTotal << endl;
            cout << endl;
            
            actual = actual->sig;
            count++;
        }
    }
    //Calcular todas las prendas
    float calcularGananciaTotal() {
        float total = 0;
        NodoPrenda* actual = cabeza;
        
        while (actual != 0) {
            total += actual->ganTotal;
            actual = actual->sig;
        }
        
        return total;
    }   
};





#endif