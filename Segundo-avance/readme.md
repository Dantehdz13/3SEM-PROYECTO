# Proyecto: Nombre de tu proyecto
Con el fin de identificar las tendencias de ropa por temporadas, se implementó un algoritmo que permita a los dueños
de las sucursales identificar precios y tendencias que les ayude a adaptarse a los cambios constantes del consumo de
los clientes

## Descripción del avance 1
Este avance contiene el siguiente algoritmo de ordenamiento: quicksort. Junto con la posibilidad de obtener datos por medios
externos como documentos csv

## Descripción del avance 2
Se implementó el uso de estructuras de datos para el análisis de precios de las prendas, con el fin de obtener la que genera
más ganancias a la tienda

### Cambios sobre el primer avance
1. Escribe la lista de cambios realizados sobre el planteamiento original: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

1. Se implementó la estructura ListaProfit para registrar y analizar las ganancias de cada prenda. Este cambio permite extender el análisis más allá del simple ordenamiento.
2. Se añadió el módulo de ordenamiento rápido (quicksort) para optimizar la clasificación de las prendas según sus ventas o precios.
3. Se mejoró la lectura del archivo CSV eliminando espacios en blanco y gestionando posibles errores de conversión.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp  -std=c++11 -o segundo_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./segundo_avance` 

## Descripción de las entradas del avance de proyecto
El programa utiliza un archivo de entrada llamado `ventas_otros.csv`, que contiene los datos de las prendas con el siguiente formato:

nombre,tipo,precio,ventasMes,ventasSemestre

## Descripción de las salidas del avance de proyecto
El programa muestra en consola el listado ordenado de prendas, así como el análisis de las 10 con mayores ganancias. También despliega mensajes de depuración indicando la cantidad de prendas cargadas y procesadas.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se analizó la complejidad del algoritmo quicksort, que es O(n log n) en promedio, lo que permite ordenar eficientemente grandes volúmenes de prendas. También se evaluó la eficiencia de las inserciones en la estructura ListaProfit.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Las operaciones de inserción en ListaProfit presentan complejidad O(n) y el uso del vector para almacenar prendas permite acceso aleatorio eficiente. El análisis de ganancias se realiza de manera óptima gracias a la estructura enlazada.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se eligió quicksort porque es eficiente especialmente con datos parcialmente ordenados, lo cual se adapta al comportamiento esperado de las ventas de prendas. Su implementación permite obtener rápidamente los listados requeridos.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Se implementaron funciones para consultar y mostrar la información de prendas y ganancias de forma precisa, accediendo a los datos desde las estructuras sin pérdidas ni inconsistencias.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
La lectura del archivo CSV fue implementada considerando la eliminación de espacios y el manejo de errores de conversión, asegurando que los datos se cargan correctamente en las estructuras correspondientes.