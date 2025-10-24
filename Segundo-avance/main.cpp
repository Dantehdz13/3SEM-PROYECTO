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

using namespace std;
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
  }

  //se cierra el archivo con los datos...
  file.close();

  ordenamiento sorter;
  sorter.quicksort(prendas, 0, prendas.size() - 1);
  sorter.verPrendas(prendas);

  //Analisis de ganancias
  ListaProfit listaGanancias;

  for (const auto& prenda : prendas) {
    listaGanancias.insertOrden(prenda);
  }
  listaGanancias.mostrarTopGanancias(10);

return(0);
}