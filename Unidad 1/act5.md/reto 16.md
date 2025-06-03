Implementa en lenguaje ensamblador el siguiente programa:

```c++
int[] arr = new int[10];
int sum = 0;
for (int j = 0; j < 10; j++) {
    sum = sum + arr[j];
}
```
#### lenguaje ensamblador

```asm
@arr  // Dirección base
D=A

@sum  // Inicializar sum
M=0
@j  // j=0
M=0

(LOOP)
@j
D=M
@10
D=D-A
@END
D;JGE

@arr
A=D+M
D=M
@sum
M=D+M

@j
M=M+1

@LOOP
0;JMP

(END)

```
#### ¿Qué hace este programa?

Este programa:

- Declara un arreglo de 10 enteros (arr).
- Inicializa sum en 0.
- Recorre el arreglo sumando cada elemento a sum.

#### ¿Cuál es la dirección base de arr en la memoria RAM?

Almacena variables en RAM a partir de la dirección 16.

- arr es un arreglo, por lo que su primera posición en RAM es RAM[16].
- arr[0] estará en RAM[16], arr[1] en RAM[17], ..., arr[9] en RAM[25].

#### ¿Cuál es la dirección base de sum en la memoria RAM y por qué?

Después de arr[9] (que termina en RAM[25]), la siguiente variable es sum, así que:

- sum se almacena en RAM[26]. Asigna variables en orden de declaración después de la memoria del arreglo.

#### ¿Cuál es la dirección base de j en la memoria RAM y por qué?

j es la última variable en declararse y se almacena después de sum, en RAM[27].