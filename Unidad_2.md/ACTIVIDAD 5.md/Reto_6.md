# Solución

Ahora vas a usar un puntero para leer la posición de memoria a la que este apunta, es decir, vas a leer por medio del puntero la variable cuya dirección está almacenada en él.

```cpp
#include <iostream>

int main() {
    int a = 10;   // Declaración e inicialización de la variable a
    int b = 5;    // Declaración e inicialización de la variable b
    int *p;       // Declaración del puntero p

    p = &a;       // p almacena la dirección de a
    b = *p;       // b obtiene el valor almacenado en la dirección que apunta p (es decir, el valor de a)

    std::cout << "Valor de a: " << a << std::endl;
    std::cout << "Valor de b: " << b << std::endl;
    std::cout << "Dirección de a: " << &a << std::endl;
    std::cout << "Dirección almacenada en p: " << p << std::endl;
    std::cout << "Valor al que apunta p: " << *p << std::endl;

    return 0;
}
```

### Explicación paso a paso

1. Declaración de las variables a y b

- `a = 10;`
- `b = 5;`

2. Declaración del puntero p

- `int *p;` → `p` es un puntero que almacenará la dirección de una variable de tipo int.

3. Asignación de la dirección de a a p

- `p = &a;` → Ahora p apunta a a, es decir, almacena su dirección de memoria.

4. Lectura del valor de a a través de p y asignación a b

- `b = *p;`
- `*p` accede al valor almacenado en la dirección que contiene p (es decir, a).
- Como a = 10, entonces b = 10.

### Salida esperada

```cpp
Valor de a: 10
Valor de b: 10
Dirección de a: 0x61ff08   (Ejemplo, la dirección real depende de la ejecución)
Dirección almacenada en p: 0x61ff08
Valor al que apunta p: 10
```
En este caso b = *p; hace que el valor de b cambie de 5 a 10 porque p apunta a la la variable a y con *p a la derecha del igual estás leyendo el contenido de la variable apuntada.
