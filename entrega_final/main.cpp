//PRIMER AVANCE - POPULARIDAD DE MARCAS DE ROPA
//Dante Hernández Ramírez - A01668070
//(VERSIÓN 1.2 DEL PROYECTO)
//............................................................................

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "ordenamiento.h"
#include "mejor_venta.h"
#include "editar.h"

using namespace std;
//............................................................................
// IMPLEMENTACIÓN DE UN MENÚ PARA QUE EL USUARIO INTERACTÚE CON EL PROGRAMA
void mostrarMenu() {
    cout << "----- MENÚ DE ANÁLISIS DE VENTAS DE ROPA -----" << endl;
    cout << "1. Ventas ordenadas por su cantidad vendida" << endl;
    cout << "2. Prendas que tuvieron mejores ganancias" << endl;
    cout << "3. Análisis completo" << endl;
    cout << "4. Ganancias totales de todas las prendas" << endl;
    cout << "5. Agregar una prenda" << endl;
    cout << "6. Editar una prenda" << endl;
    cout << "7. Eliminar una prenda" << endl;
    cout << "Seleccione una opción: ";
}

//............................................................................
int main(){
/*
Se cargan el archivo con los datos de las ventas y estaísticas de las
prendas.
*/
  ifstream file("ventas_otros.csv");
  string line;
  vector<Prenda> prendas;

  /*
  Se verifica si se abrió correctamente el archivo, si no, se envía un
  mensaje de error.

  Si si, se verifica linea por linea, después las separa por comas
  */
  if (!file.is_open()) {
    cerr << "Error: No se pudo abrir el archivo" << endl;
    return 1;
  }

  //Salta la primera línea (encabezados)
  getline(file, line);

  while (getline(file,line)) {
    stringstream ss(line);
    string campo;
    Prenda prenda;
    int columna = 0;

    //Convertir los datos de las ventas a número
    while (getline(ss, campo, ',')) {
      try{
        //Se eliminan los espacios
        campo.erase(remove_if(campo.begin(), campo.end(), ::isspace), campo.end());
        switch(columna) {
          case 0:prenda.nombre = campo;break;
          case 1: prenda.tipo = campo;break;
          case 2: prenda.precio = stod(campo);break;
          case 3: prenda.ventasMes = stoi(campo);break;
          case 4: prenda.ventasSemestre = stoi(campo);break; 

        }
        columna ++;
      }
      catch (const invalid_argument& e) {
        cerr << "Error en la conversión de datos" << endl;
      }
      catch (const out_of_range& e) {
        cerr << "El dato se encuentra fuera de rango" << endl;
      }
    } 

    //Se agrega la prenda al vector
    if (columna == 5) {
      prendas.push_back(prenda);
    }

      
  nodoPrenda* nuevo = new nodoPrenda(prenda);
  nuevo->siguiente = listaPrincipal;
  listaPrincipal = nuevo;
  }

  //se cierra el archivo con los datos...
  file.close();

  ordenamiento sorter;
  sorter.quicksort(prendas, 0, prendas.size() - 1);

  //Analisis de ganancias
  ListaProfit listaGanancias;

  for (const auto& prenda : prendas) {
    listaGanancias.insertOrden(prenda);
  }
 
  //Menú, pero dentro del main...
  int opcion;
  do {
    mostrarMenu();
    cin >> opcion;

    //Si se ingresa una opción inválida
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opción inválida." << endl;
        continue;
    }
    cout << endl;

    switch (opcion) {
        case 1:
            sorter.verPrendas(prendas);
            break;
        case 2:
            int numPrend;
            cout << "¿Cuántas prendas con mejores ganancias desea ver? ";
            cin >> numPrend;

            if(numPrend < 1 || numPrend > prendas.size()) {
                cout << "Número inválido de prendas." << endl;
            } else {
                listaGanancias.mostrarTopGanancias(numPrend);
            }
            break;
        case 3:
            sorter.verPrendas(prendas);
            cout << endl;
            listaGanancias.mostrarTopGanancias(5);
            break;
        case 4: {
            float gananciaTotal = listaGanancias.calcularGananciaTotal();
            cout << "La ganancia total de todas las prendas es: $" << fixed << setprecision(2) << gananciaTotal << endl;
            break;
        }
        case 5:
            agregarCosas(prendas);
            sorter.quicksort(prendas, 0, prendas.size() - 1);
            listaGanancias = ListaProfit(); 
            for (const auto& prenda : prendas) {
              listaGanancias.insertOrden(prenda);
            }
            break;

        case 6:
            editarCosas(prendas);
            sorter.quicksort(prendas, 0, prendas.size() - 1);
            listaGanancias = ListaProfit();
            for (const auto& prenda : prendas) {
              listaGanancias.insertOrden(prenda);
            }
            break;

        case 7:
            eliminarCosas(prendas);
            sorter.quicksort(prendas, 0, prendas.size() - 1);
            listaGanancias = ListaProfit();
            for (const auto& prenda : prendas) {
              listaGanancias.insertOrden(prenda);
            }
            
        default:
            cout << "Opción inválida. Por favor, seleccione una opción del 1 al 4." << endl;
            break;
    }
    if (opcion != 0) {
        cout << "Presiona cualquier tecla para continuar...";
        cin.ignore();
        cin.get();
    }
   
  }while (opcion != 0);

return(0);
}