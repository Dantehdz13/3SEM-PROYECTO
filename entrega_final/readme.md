# GESTIÓN DE VENTAS EN ROPA - SISTEMA INTELIGENTE DE GESTIÓN Y ANÁLISIS DE INVENTARIO

## Proyecto - resumen general
El Analizador de Ventas de Ropa es un sistema en C++ diseñado para dueños de tiendas y administradores de inventario que necesitan comprender el comportamiento real de sus prendas, identificar productos rentables y optimizar decisiones de compra y reposición.

El sistema contiene un enfoque básico basado en vectores y ordenamientos simples, integrando:

* QuickSort: Para el ordenamiento de prendas por ventas
* Listas enlazadas: Para analizar y priorizar las ganancias mensuales
* Lectura dinámica de archivos externos (CSV)
* Un menú para consultar, editar, agregar y eliminar productos



## Descripción del avance 1
El avance 1 consistió en la construcción de la base del programa: 

* Lectura del archivo de ejemplo (ventsa_otros.csv).
* Almacenamiento de cada prenda en un vector de estructuras (Prenda).
* Ordenamiento descendente por ventas con el uso de quicksort. (O(nlog(n))).
* consulta básica del listado para la observación y análisis de los productos.

El sistema en este punto únicamente es capaz de mostrar ventas por volumen, sin considerar rentabilidad.

El usuario no podía interactuar con el programa por las limitaciones de opciones que se ofrecían.

## Descripción del avance 2
Se implementó en el proyecto un análisis financiero básico, en el cuál se incorpora:

* ListaProfit: una lista enlazada ordenada por ganancia mensual.
* Incersión ordenada en la lista (O(n)) para mantener los artículos más "rentables" al incio
* Reporte de los artículos con mejor desempeño.

Con esto se agregan más opciones para un análisis más completo referente a la rentabilidad de los artículos. Ayudando a una mejor toma de decisiones administrativas

### Cambios sobre el primer avance
1. Se sustituyó la impresión del vector para la lista enlazada referente a las ganancias.
2. El algoritmo quicksort se cambió a otro archivo.h.
3. Se reforzó el manejo de lectura del archivo CSV para poder hacer el resto de procedimientos correctamente.
4. Se corrigió el análisis de evaluación de componentes. Incluyéndose en el README referente al avance 2.

## Descripción del avance 3
El tercer avance agrega un menú interactivo de gestión de inventario, accediendo a opciones como:

* Ordenamiento de árticulos por cantidad de ventas
* Consultar las mejores ganancias
* Análisis completo
* Ganancia total
* Agregar, editar o eliminar prendas

Esto permite finalmente que el usuario pueda interactuar por completo con el proyecto y las opciones que este contiene.

### Cambios sobre el segundo avance
1. Se implementaron opciones para que el usuario interactúe con el programa.
2. Se corrigieron erroeres relacionados con la lectura del archivo CSV
3. El usuario puede modificar su inventario sin necesidad de reiniciar el programa

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o a.out` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./a.out` 

## Descripción de las entradas del avance de proyecto
1. Archivo `ventas_otros.csv`

Contiene un catálogo de prueba con prendas y su respectiva información

Fomrato:
Nombre,Tipo,Precio,VentasMes,VentasSemestre
PlayeraBasica,casual,250,45,260


2. Entradas por teclado

Desplegadas en forma de menú en la terminal (opciones 1 a 7) en las cuales el usuario puede:
* Consultar diferentes listas
* Agregar prendas
* Editar prendas
* Eliminar prendas

En cada una de las opciones está presente una validación para evitar errores.

## Descripción de las salidas del avance de proyecto
El programa es capaz de mostrar:

* Listado ordenado de los artículos presentes en el archivo CSV
* Prendas más rentables para el negocio
* Análisis completo (ventas y ganancias)
* Ganancia total
* Mensajes de confirmación al querer modificar la información del archivo

Ejemplos:
Datos guardados correctamente.
Prenda eliminada.
La ganancia total es: $15430.50

## Desarrollo de competencias -------------------------------------------------

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El proyecto utiliaz quicksort, en donde:
* Mejor caso: O(n log(n)): En un escenario ideal, el pivote divide los datos de manera "equilibrada", dejando los "subproblemas" con la misma cantidad de valores, reduciendo el número de particiones.

* Caso promedio: O(n log(n)): Se presetan escenarios en donde los datos están parcialmente desordenados, como consecuencia, las divisiones de los subproblemas son imperfecta, pero tampoco afectan tanto el rendimiento.

* Peor caso: O(n^2): En el peor escenario, el pivote resulta ser el menor o mayor valor de forma frecuente, produciendo subproblemas muy desbalanceados, lo que aumenta la profundidad de la función recursiva.
 

El algortimo se implementa de forma descendente según las necesidades establecidas por el usuario o negocio.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
EN el vector Prenda:
* Inserción amortizada O(1): cuando se agrega una prenda con push_back, el vector solo se extiende si tiene el espacio, siendo ese su nivel.
* Acceso directo O(1): Acceder a cualquier elemento del vector, tomando siempre tiempo constante.

En la lista enlazada ListaProfit:
* Inserción ordenada O(n): Para la colocación de cada prenda (de mayor a menor ganancia), es necesario que se recorra desde el inicio hasta encontrar el punto solicitado.
* Recorridos O(n): No se permite el acceso directo en las listas enlazadas, por lo cual se necesita recorrer nodo por nodo para buscar los elementos.
* Consulta top ganancias O(k): Como la lista está ordenada con la mayor ganancia al frente (mejor caso), obtener los primeros x elementos requiere avanzar x nodos (eficiente cuando solo quieres un top de elementos).

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
El proyecto cuenta con varios componentes que se ejecutan cada vez que el usuario quiere realizar un tipo de acción (ya sea consultar, agregar, editar o eliminar). Para esto:

Lectura y actualización del vector:
* Cuando se altera la lista, se recorre el vector para encontrar la prenda (O(n)), posterior a esto se actualiza la estructura con los nuevos datos.

quicksort:
* Una vez se actualiza el vector, se recorre de nuevo (casos ya desglosados anteriormente).

Reconstrucción de la lista:
* Para re-calcular las ganancias se recorre el vector, en donde cada inserción ordenada toma O(n), siendo este su resultado (es un costo lineal ya que solo se reinserta el orden, no se ordena nada).

Menú:
* tanto mostrar prendas, calcular ganancia total como eliminar prenda se toman como O(n), ya que son operaciones lineales.


Con este rápido análisis, se concluye que el nivel de complejidad total del proyecto es de O(n log(n)), siendo la operación más "difícil" dentro del código.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El algoritmo quickSort fue elegido porque el volumen de prendas no es fijo y se necesitan reordenamientos frecuentes cada vez que se agrega o edita una prenda. El algoritmo evita la sobrecarga de memoria de otras alternativas como MergeSort. Su implementación se encuentra en la clase `ordenamiento` para reutilizarla después de cada cambio del catálogo.

* Su complejidad promedio y de mejor caso es O(n log(n)), lo que permite escalar a catálogos medianos sin que el tiempo de respuesta se vuelva exagerado.
* A diferencia de algoritmos como bubblesort o selectionsort, que siempre son O(n^2), QuickSort reduce drásticamente el número de comparaciones necesarias.
* A diferencia de mergesort, no requiere memoria adicional significativa, lo cual es conveniente en un programa de consola que se ejecuta sobre estructuras ya cargadas en la RAM.
#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Se integran dos estructuras principales, un vector Prenda y la lista enlazada ListaProfit, en donde.

El vector permite:
* Recorrer e imprimir las prendas en el orden exacto generado por el quicksort.
* Acceso directo a elementos mediante índice en O(1), útil para actualizaciones y recorridos secuenciales.

La lista enlazada ListaProfit se utiliza para el análisis de ganancias porque:
* Mantiene los nodos siempre ordenados de mayor a menor ganancia mensual.
* Permite consultar fácilmente las prendas más rentables sin tener que volver a ordenar el vector.
* Se centra únicamente en la información necesaria para el análisis económico, separando responsabilidades respecto al catálogo completo.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
El menú de `main.cpp` ofrece consultas dirigidas sobre el vector ordenado (`verPrendas`) y sobre la lista de ganancias (`mostrarTopGanancias`, `calcularGananciaTotal`). Cada consulta limpia la entrada y valida límites para asegurar que el usuario reciba respuestas consistentes incluso si solicita más elementos de los existentes.

El menú principal definido en `main.cpp` ofrece distintas opciones que funcionan como "experimentos controlados" sobre las estructuras de datos: cada opción ejecuta una consulta o acción específica sobre el vector ordenado o la lista enlazada.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Se abre `ventas_otros.csv`, se salta el encabezado y se recorre cada línea usando `stringstream`. Al convertir los campos se eliminan espacios, se usan `stod`/`stoi` y se capturan excepciones de formato para garantizar que sólo se agreguen prendas completas. Esto asegura que el vector quede sincronizado con el archivo incluso si hay datos corruptos.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
El módulo `editar.h` guarda la función `guardarCosas`, que reescribe el CSV con los encabezados y los valores actuales del vector. Cada operación pregunta al usuario si desea persistir los cambios; en caso afirmativo se vuelca el contenido del vector, preservando el formato esperado por el lector