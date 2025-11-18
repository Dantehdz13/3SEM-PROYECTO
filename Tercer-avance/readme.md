# Proyecto: Analizador de ventas de ropa
Con el fin de identificar las tendencias de ropa por temporadas, se implementó un sistema en C++ que permite a los dueños
de las sucursales visualizar el comportamiento de sus prendas, ubicar las referencias más rentables y ajustar su inventario
conforme cambian los hábitos de compra de los clientes

## Descripción del avance 1
Se construyó la base del programa: lectura del archivo `ventas_otros.csv`, almacenamiento de cada prenda en un vector de
estructuras y aplicación de QuickSort (en orden descendente) para ordenar por ventas del último mes. El usuario podía consultar el listado ordenado
para identificar con rapidez los productos mejor posicionados

## Descripción del avance 2
Se añadió la estructura de datos `ListaProfit`, una lista enlazada que calcula la ganancia mensual de cada prenda e inserta
los nodos de forma ordenada. Con ello se habilitó la consulta de las prendas más rentables y se enriqueció el análisis
con métricas económicas además del volumen de ventas

### Cambios sobre el primer avance
1. Se sustituyó la impresión directa del vector por la lista enlazada ordenada por ganancias para priorizar la rentabilidad y no solo las ventas
2. El algoritmo de ordenamiento fue pasado a un archivo.h aparte
3. Se reforzó el manejo de errores al leer el CSV para evitar algún tipo de error en el análisis

## Descripción del avance 3
El tercer avance convierte la herramienta en un panel interactivo: se agregó un menú con siete opciones para ordenar,
consultar las mejores ganancias, calcular la utilidad total y ejecutar acciones de edición del archivo externo (agregar, editar y eliminar prendas)
persistiendo los datos en el mismo CSV. Después de cada cambio se reejecuta el ordenamiento y se reconstruye la lista de
ganancias, por lo que el análisis siempre refleja el estado más reciente (después de la edición del CSV)

### Cambios sobre el segundo avance
1. Se implementaron opciones para que el usuario interactúe con el programa, no solo se despliegue información
2. Se corrigieron erroeres relacionados con la lectura del archivo CSV

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o a.out` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./a.out` 

## Descripción de las entradas del avance de proyecto
1. Archivo `ventas_otros.csv`: contiene los encabezados `Nombre,Tipo,Precio,VentasMes,VentasSemestre`. Cada fila describe una prenda, su categoría, precio unitario, ventas del último mes y ventas acumuladas del semestre. Ejemplo: `PlayeraBasica,casual,250,45,260`.
2. Entradas por teclado: el usuario selecciona una opción del menú (1–7) y, según el caso, tiene la posibilidad de agregar, editqr o eliminar prendas del mismo archivo csv en el código presentado (validando siempre que las opciones proporcionadas por el usuario sean correctas)

## Descripción de las salidas del avance de proyecto
1. Listado ordenado de prendas (opción 1) mostrando nombre, tipo, precio y ventas mensuales/semestrales
2. Top de ganancias (opción 2) indicando la ganancia mensual estimada de cada prenda (`precio * ventasMes`)
3. Análisis completo (opción 3) que combina los dos puntos anteriores
4. Ganancia total acumulada del catálogo (opción 4) mostrada con dos decimales
5. Mensajes de confirmación y persistencia al agregar, editar o eliminar prendas que confirman si los datos se guardaron correctamente

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo principal de ordenamiento es QuickSort (`ordenamiento::quicksort`), que divide el vector en torno a un pivote y procesa recursivamente ambos subarreglos. En el mejor caso y promedio la complejidad es `O(n log n)` gracias al particionamiento balanceado, mientras que el peor caso se mantiene en `O(n^2)` para entradas ya ordenadas inversamente. Es importante mencionar que el algoritmo funciona de mandera descendente (mayor a menor, por la naturalidad del proyecto)

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El vector de `Prenda` ofrece inserciones amortizadas `O(1)` cuando se agregan registros y acceso directo `O(1)` al recorrerlo para imprimir. Para priorizar por ganancias se usa la lista enlazada `ListaProfit`, cuya inserción ordenada es `O(n)` pero evita ordenar nuevamente el vector, de modo que el top de ganancias se obtiene en tiempo `O(k)` donde `k` es el número de elementos solicitados. Ambas estructuras se recorren en `main.cpp` para actualizarse tras cada operación.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Además del ordenamiento, las operaciones de edición del archivo son lineales porque requieren ubicar la prenda dentro del vector (`O(n)`). La lectura del archivo también es lineal respecto al número de líneas. Considerando que tras cualquier modificación se reordena el vector y se reconstruye la lista, la complejidad dominante del ciclo de actualización es `O(n log n)` (por el quickSort anteriormente descrito) más la inserción secuencial en la lista (`O(n)`), dando como resultado final `O(n log n)` para sincronizar el catálogo completo.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El algoritmo quickSort fue elegido porque el volumen de prendas no es fijo y se necesitan reordenamientos frecuentes cada vez que se agrega o edita una prenda. El algoritmo evita la sobrecarga de memoria de otras alternativas como MergeSort. Su implementación se encuentra en la clase `ordenamiento` para reutilizarla después de cada cambio del catálogo.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
El vector permite recorrer y mostrar la información en el orden exacto que entrega el quickSort. Para el análisis de ganancias era preferible no mezclar responsabilidades, por lo que la lista enlazada `ListaProfit` conserva sólo los datos necesarios y se mantiene siempre ordenada de mayor a menor utilidad, facilitando consultas como “ver las mejores n prendas”

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
El menú de `main.cpp` ofrece consultas dirigidas sobre el vector ordenado (`verPrendas`) y sobre la lista de ganancias (`mostrarTopGanancias`, `calcularGananciaTotal`). Cada consulta limpia la entrada y valida límites para asegurar que el usuario reciba respuestas consistentes incluso si solicita más elementos de los existentes.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Se abre `ventas_otros.csv`, se salta el encabezado y se recorre cada línea usando `stringstream`. Al convertir los campos se eliminan espacios, se usan `stod`/`stoi` y se capturan excepciones de formato para garantizar que sólo se agreguen prendas completas. Esto asegura que el vector quede sincronizado con el archivo incluso si hay datos corruptos.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
El módulo `editar.h` guarda la función `guardarCosas`, que reescribe el CSV con los encabezados y los valores actuales del vector. Cada operación pregunta al usuario si desea persistir los cambios; en caso afirmativo se vuelca el contenido del vector, preservando el formato esperado por el lector