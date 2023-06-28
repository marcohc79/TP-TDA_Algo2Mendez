<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TP/TDA

## Repositorio de Marco Huamani - 95392 - mhcaballero79@gmail.com 

- Para compilar:
    Se utiliza el archivo `makefile` ubicado dentro del proyecto y para las pruebas de la catedra.

    ```bash
    ./.algo2/test.sh
    ```
---
##  Funcionamiento

En el programa implementaremos un **TDA Lista** utilizando **nodos simplemente enlazados**, en la cual no solo tendremos las operaciones básicas sino que también se programará **iteradores externos** e **internos**.<br> Por ultimo se implementará **TDA Pila** y **TDA Cola** reutilizando las funciones de **TDA Lista**.
Las operaciones que implementaremos para nuestro **TDA**:

+ Crear.
+ Insertar.
+ Quitar.
+ Buscar.
+ Eliminar.
+ Iterador externo.
+ Iterador interno.
+ Destruir.

A continuación detallaremos un poco el desarrollo del programa, para antes de esto veamos algunos detalles:

Nuestra **lista** es una estructura que consta de tres partes, un puntero que disecciona el **nodo inicial**, otro al **nodo final** y por ultimo un **contador** de nodos que se van agregando. <br>
Para los nodos, creamos una función la cual se encarga de crear e oficializarlo llamada `nodo_crear()`. En este caso la estructura consta de dos partes, una que apunta al elemento a almacenar y la otra hacia el siguiente nodo. Al momento de su creación ambos apuntan a *NULL*. Por último tenemos la función `buscar_nodo()` el cual nos devuelve el nodo ubicado en la posición requerida.

Ahora veamos las implementaciones de las operación de la lista, cabe aclarar que las mismas serán re-utilizadas para crear **Pilas** y **Colas**.

Tenemos 2 formas de insertar:
+ **lista_insertar()**: la cual inserta directamente el elemento al final de la lista y para ello hay que crear el nodo correspondiente. Posterior a ello tenemos dos consideraciones:
    + Si la lista esta vacía los punteros **nodo_inicial** y **nodo_final** apuntaran al nodo creado.
    + En caso que tenga algún elemento, el último nodo apuntará al creado y al igual que el puntero **nodo_final** de la lista.

<div align="center">
    <img width="750px" src="img/insertar.svg">
</div>

+ **lista_insertar_en_posicion()**: en este caso vamos a requerir como parámetro la posición en donde queramos insertar, tomando en consideración que 0 es colocarlo al comienzo, 1 posterior al primer nodo y así sucesivamente. En este hay que dividirlo en 3 partes ya que depende la posición en la que se desea agregar.
    + Si la posición es 0, esto quiere decir que vamos a reemplazar el comienzo de la lista, por lo cual el puntero **nodo_inicial** apunta al nuevo nodo y éste va a puntar al **viejo** nodo inicial.
    + Si la posición es menor al tamaño actual de lista. Utilizaremos la función **buscar_nodo()**, guardar dicho nodo en una variable auxiliar llamada **nodo_actual** y el siguiente nodo que apunta **nodo_actual** lo guardamos en **nodo_siguiente**, recién ahora podremos redireccionar los punteros, haciendo que el **nodo_actual** apunte al nuevo nodo y este apunte a **nodo_siguiente**.
    + En caso que la posición sea mayor o igual al tamaño se agregará el nuevo nodo al final, para esto nos apoyaremos en la función **lista_insertar()** detallada anteriormente.

Para quitar algún elemento ubicado en algún nodo, igual que anteriormente tenemos 2 funciones:

+ **lista_quitar()**: la cual quita o elimina el último elemento de la lista. En este caso nos guardaremos en la variable **nodo_ultimo** el ultimo nodo de la lista. Ahora vemos las 2 consideraciones a tener:
    + Si el tamaño de lista es 1, solo tendremos que hacer apuntar **nodo_final** y **nodo_inicial** a NULL. Y por ultimo retornar el elemento de **nodo_ultimo**.
    + En otro, al no poder saber cual es el ante ultimo nodo debemos utilizar la función **buscar_nodo()** en la dirección de `tamañio-1`, guardalo en un otro nodo llamado **nodo_anteultimo**. Finalmente haremos que el puntero **nodo_final** apunte a este ultimo nodo creado y retornamos el elemento de **nodo_final**.
    
+ **lista_quitar_de_posicion()**: como su nombre lo dice, ahora podemos eliminar un nodo en cualquier posición. Para ello debemos deparar el problema en 3 bloques:
    + En caso que queramos eliminar en una posición mayor o igual que el tamaño de la lista, utilizaremos la función anteriormente descripta (**lista_quitar()**).
    + Si deseamos eliminar el primer nodo, previamente lo resguardaremos en una variable llamada **nodo_eliminar**. Crearemos otra variable que almacenará lo que apunta **nodo_eliminar** de esta forma haremos que la lista apunte este ultimo nodo y retornaremos el elemento de **nodo_eliminar**.
    + En caso que no sea ninguna de las 2 anteriores, buscaremos cual es el nodo anterior al buscado, la almacenamos en la variable **nodo_anterio**, con este podemos obtener el nodo posterior al que vamos eliminar y lo guardamos en **nodo_siguiente**. Con estos datos hacemos que **nodo_anterior** apunte a **nodo_siguiente** y retornamos el elemento de **nodo_eliminar** que lo podemos obtener con **nodo_anterior**.

Cabe aclarar que tanto para agregar o eliminar en cada una de las funciones se actualiza el tamaño descuerdo a la acción realizada. También en cada caso previo a realizar alguna acción se haga las validaciones correspondientes. 


---

## Respuestas a las preguntas teóricas

<br>

Previo a la explicación de los tipos de TDAs, necesitamos explicar el concepto de nodo. Se trata de una estructura compuesta por dos punteros los cuales uno apunta al elemento que se va almacenar y el otro apunta al próximo nodo.

## **Lista**


Una lista es una colección de elementos ordenados, donde cada uno de ellos tiene una única posición. Las listas pueden ser simplemente enlazada, doblemente enlazada y vector dinámico donde cada elemento puede ser un número, letras, punteros, nodos, etc. También poseen operaciones, como:

+ Crear.
+ Destruir.
+ Insertar en posición *n*.
+ Eliminar en posición *n*.
+ Si esta vaciá.
+ Ver elementos en posición *n*.
+ Longitud.

<br>

### **Simplemente enlazada.**

Esta estructura que utiliza nodos enlazados en una **única** dirección. Ademas no necesita memoria contigua para almacenar todos los nodos, dado que reservar un bloque de memoria para cada nodo y estos se enlazan entre sí mediante punteros. Donde cada uno de ellos apunta al siguiente y el último lo hace a **NULL**. <br>
Veamos el diagrama realizado para nuestra implementación en este TP.

<br>

<div align="center">
    <img width="980px" src="img/Lista.svg">
</div>

Si analizamos la complejidad temporal de cada operación va depender de la posición en la que se realiza. En general, la inserción y la eliminación al inicio de la lista tienen una complejidad *O(1)*, mientras que la inserción y la eliminación en una posición específica tienen una complejidad temporal *O(n)*, ya que se debe recorrer la lista hasta la posición deseada. La obtención del en una posición específica también tiene complejidad *O(n)*, ya que se debe recorrer la lista hasta la posición deseada. La inserción y eliminación al final de la lista tiene complejidad *O(n)* sino se mantiene un puntero al último nodo, en dicho caso sería *O(1)*.

<br>

### **Doblemente enlazada.**

Una lista doblemente enlazada es una estructura de datos lineal similar a la lista simplemente enlazada, pero cada nodo tiene dos punteros, uno que apunta al nodo anterior y otro que apunta al siguiente nodo.
La implementación de este tipo de listas es similar a la anteriormente vista, pero cada nodo contiene un puntero adicional que apunta al nodo anterior. También se necesita un puntero que apunte a la cabeza de la lista y otro que apunte al final de la lista.

<div align="center">
    <img width="750px" src="img/Doblemente.svg">
</div>

La complejidad de cada operación es similar a la lista simplemente enlazada, pero con el doble de punteros, lo que aumenta la complejidad de las operaciones *nodo anterior* o *nodo siguiente*. En general, la inserción y la eliminación al inicio de la lista tienen complejidad *O(1)*, mientras que la inserción y la eliminación en posición específica tienen complejidad *O(n)*, ya que se debe recorrer la lista hasta la posición deseada. La obtención de un elemento en una posición específica también tienen una complejidad temporal *O(n)*, ya que también se debe recorrer la lista hasta la posición deseada. Por ultimo, la inserción y eliminación al final de la lista tienen complejidad *O(1)* si se mantiene un puntero al último nodo.

<br>

### **Vector dinámico.**

Es este tipo de estructura se utiliza un arreglo para almacenar elementos, pero puede cambiar de tamaño de manera dinámica en tiempo de ejecución. El arreglo se aloja en una zona de memoria continua y se accede a los elementos mediante índices. La implementación de dicha estructura consta de un arreglo de tamaño variable y dos variables adicionales, una para el tamaño y otra para la capacidad máxima del vector. Cuando se agrega un elemento al vector y se alcanza la capacidad máxima, se debe re-alojar el arreglo en una zona de memoria más grande y copiar los elementos existentes en el nuevo arreglo. <br> 
La complejidad de cada operación depende del tamaño actual del vector y de la posición de inserción o eliminación. Es por esto que insertar y eliminar al inicio y al final del vector tiene una complejidad *O(n)* ya que se debe desplazar cada elemento del vector. Esto también es igual al momento de querer insertar o eliminar un elemento de posición específica ya que se debe desplazar cada elemento desde la posición deseada hasta el final del vector. Obtener un elemento en una posición específica tiene complejidad *O(1)*, ya que se accede directamente al elemento mediante el índice. 

<br>

## **Pila**

Es una estructura de datos que nos permite almacenar elementos en un orden específico. La **pila** se caracteriza por ser una estructura de tipo **LIFO** (last-in, first-out), lo que significa que el último elemento que se insertó es el primero en salir. <br>
Se puede imaginar como una pila de platos, y en el caso que queremos algún elemento del medio, previamente tenemos que ir sacando los de arriba. 

<div align="center">
    <img width="550px" src="img/Pila.svg">
</div>

<br>

En el gráfico anterior vemos un esquema de una pila donde los elementos son nodos. En el esquemas vemos que el ultimo elemento agregado es el **Elem4** que se encuentra en **Tope**, también conocido como **top of the stack**.

Las dos operaciones fundamentales en una pila son:

+ Push: se agrega un elemento a la cima de la pila.
+ Pop: se retira el elemento superior de la pila.

Además de estas operaciones, también es posible realizar otras, como:

+ Peek (Tope): se obtiene el valor del elemento superior sin retirarlo.
+ isEmpty (Vacía): se verifica si está vacía.
+ Size (Tamaño): se obtiene la cantidad de elementos.

<br>

## **Cola**

Al igual que la pila, una **cola** es una estructura de datos que nos permite almacenar elementos y recuperarlos pero en un orden distinto. En este caso una se caracteriza por ser una estructura **FIFO** (first-in, first-out), lo que significa que el primer elemento que se insertó es el primero en salir.
Podemos pensarlo como fila de personas en un supermercado, donde la primera persona que llega es la primera en ser atendida y las personas que van llegando se van agregando una tras otra.

<div align="center">
    <img width="550px" src="img/Cola.svg">
</div>

<br>

Las operaciones fundamentales son:

+ Enqueue (Encolar): se agrega un elemento al final de la cola.
+ Dequeue (Desencolar): se retira el elemento del principio de la cola.

Tambien puede poseer otras operaciones para realizar, como:

+ Peed (Frente): se obtiene el valor del elemento en la parte delantera sin retirarla.
+ isEmpty (Vacia): se verifica si la cola está vaciá.
+ Size (Tamaño): se obtiene la cantidad de elementos en la cola.
