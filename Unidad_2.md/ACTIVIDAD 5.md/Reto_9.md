# Solución

Considera que el punto de entrada del siguiente programa es la función main, es decir, el programa inicia llamando la función main. Vas a proponer una posible traducción a lenguaje ensamblador de la función suma, cómo llamar a suma y cómo regresar a `std::cout << "El valor de c es: " << c << std::endl;` una vez suma termine.

## En C++

```cpp
#include <iostream>

int suma(int a, int b) {
   int var = a + b;
   return var;
}


int main() {
   int c = suma(6, 9);
   std::cout << "El valor de c es: " << c << std::endl;
   return 0;
}
```

## En lenguaje ensamblador

```
// Sección de la función suma(a, b)
(SUMA)
    @ARG     // ARG[0] = a
    D=M
    @ARG+1   // ARG[1] = b
    D=D+M    // D = a + b
    @var
    M=D      // var = a + b

    @var
    D=M      // D = var
    @RETURN  // Retorno a main
    0;JMP

// Punto de entrada al programa (main)
(MAIN)
    // Pasar argumentos a la función suma (a = 6, b = 9)
    @6
    D=A
    @ARG
    M=D      // ARG[0] = 6

    @9
    D=A
    @ARG+1
    M=D      // ARG[1] = 9

    @SUMA    // Llamar a la función suma
    0;JMP

(RETURN)
    @var
    D=M      // D = resultado de suma
    @c
    M=D      // c = resultado de suma

    // Simular std::cout << "El valor de c es: " << c << std::endl;
    @MSG
    D=A
    @SCREEN
    M=D      // Muestra mensaje en pantalla

    // Bucle infinito para detener el programa
(END)
    @END
    0;JMP

// Mensaje para simular impresión en pantalla
(MSG)
    @ElValorDeC
    M="El valor de c es: "
```

## Explicación paso a paso

1. Implementación de la función `suma(a, b)`
   - `ARG[0]` almacena `a` y `ARG[1]` almacena `b`.
   - Se suman ambos valores y se almacena en `var`.
   - Se regresa el resultado en `D` y se salta a `RETURN` para volver a `main`.

2. Llamada a la función `suma(6, 9)`
   - Se almacenan los valores `6` y `9` en `ARG[0]` y `ARG[1]` respectivamente.
   - Se salta a la etiqueta `SUMA` para ejecutar la función.

3. Regreso a `main` y almacenamiento del resultado en `c`
   - Se almacena el valor devuelto en `c`.

4. Simulación de la salida `std::cout << ...`
   - En Hack no hay impresión de texto directamente, pero se puede almacenar en memoria para simular una salida en pantalla.

## Salida esperada en memoria

| Dirección | Variable     | Valor |
|-----------|--------------|-------|
| `0x0010`  | `ARG[0] (a)` | `6`   |
| `0x0011`  | `ARG[1] (b)` | `9`   |
| `0x0012`  | `var`        | `15`  |
| `0x0013`  | `c`          | `15`  |
