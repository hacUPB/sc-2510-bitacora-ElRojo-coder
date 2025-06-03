## Solución
### Escribe un programa en lenguaje ensamblador que sume los primeros 100 números naturales.
```
int i = 1;
int sum = 0;
While (i <= 100){
   sum += i;
   i++;
}
```
### ¿Cómo están implementadas las variables i y sum?
Se declaran como variables enteras (int), lo que significa que se almacenan en memoria con suficiente espacio para representar números enteros.
```
int i = 1;
int sum = 0;
```
i se inicializa con el valor 1 y se usa como contador en el ciclo while.
sum se inicializa en 0 y acumula la suma de los números del 1 al 100.
### ¿En qué direcciones de memoria están estas variables?
La dirección de memoria de una variable depende de cómo el sistema operativo y el compilador organizan la memoria. Se puede obtener con el operador & en C++:
```
cout << &i << endl;
cout << &sum << endl;
```
Esto imprimirá las direcciones de memoria donde i y sum están almacenadas.
### ¿Cómo está implementado el ciclo while?
El ciclo while ejecuta su bloque de código mientras la condición (i <= 100) sea verdadera.
```
while (i <= 100) {
    sum += i;  // Acumula el valor de i en sum
    i++;       // Incrementa i en 1
}
```
Se evalúa la condición i <= 100.
Si es verdadera, se ejecutan las instrucciones dentro del bloque.
Se incrementa i y se repite el proceso hasta que i sea mayor que 100.
¿Cómo se implementa la variable i?
Se declara como un entero (int i = 1;).
Se usa como contador en el ciclo while, aumentando en cada iteración (i++).
### ¿En qué parte de la memoria se almacena la variable i?
Como i es una variable local (declarada dentro de una función, como main()), se almacena en la pila (stack) de memoria.

Después de todo lo que has hecho, ¿Qué es entonces una variable?
Una variable es un espacio en la memoria del computador con un nombre asignado que almacena un valor que puede cambiar durante la ejecución del programa.

### ¿Qué es la dirección de una variable?
Es la ubicación en la memoria donde la variable está almacenada. Se obtiene con el operador & en C++. Ejemplo:
```
cout << &i;  // Muestra la dirección de memoria de i
```
### ¿Qué es el contenido de una variable?
Es el valor almacenado en la dirección de memoria de la variable. Se accede directamente con su nombre o indirectamente con punteros. Ejemplo:

```
cout << i;  // Muestra el valor almacenado en i
```
