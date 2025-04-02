Implementa en ensamblador el siguiente problema. En la posición R0 está almacenada la dirección inicial de una región de memoria. En la posición R1 está almacenado el tamaño de la región de memoria. Almacena un -1 en esa región de memoria.

```asm
@R0  // Dirección inicial
D=M
@R1  // Tamaño
D=M   // (aquí estaba el error: faltaba cargar R1 en D)
(LOOP)
@R1
D=M
@END
D;JEQ
@R0
A=M
M=-1
@R0
M=M+1
@R1
M=M-1
@LOOP
0;JMP
(END)

```

### Código hecho con chatgpt 

```asm

@R0
D=M          // D = dirección inicial (R0)
@addr
M=D          // addr = R0 (posición actual)

@R1
D=M          // D = tamaño de la región (R1)
@count
M=D          // count = R1 (contador de iteraciones)

@END
D;JEQ        // Si count == 0, salta a END (nada que modificar)

(LOOP)
    @addr
    A=M      // Accede a la dirección almacenada en addr
    M=-1     // Guarda -1 en RAM[addr]

    @addr
    M=M+1    // addr = addr + 1 (siguiente posición)

    @count
    M=M-1    // count = count - 1 (disminuye el contador)

    @count
    D=M
    @LOOP
    D;JGT    // Si count > 0, sigue el bucle

(END)
@END
0;JMP        // Detiene el programa
```

#### ¿Qué representa addr?
En ensamblador Hack, no se pueden usar nombres de variables como en lenguajes de alto nivel, pero a menudo usamos nombres simbólicos para mejorar la legibilidad.

- addr representa la posición actual de memoria que estamos modificando.

- Comenzamos en R0 (la dirección inicial).

- Se usa addr para recorrer cada posición hasta alcanzar el tamaño indicado en R1.

#### ¿ Qué representa count?
count representa el número de posiciones que faltan por modificar. En este caso, count = R1, porque R1 almacena el tamaño de la región de memoria. Se usa count para saber cuándo detener el bucle.

- count es una variable que lleva la cuenta de cuántas posiciones quedan por modificar.

- Se decrementa en cada iteración y cuando llega a 0, el programa termina.

- Es equivalente a usar R1, pero count mejora la claridad del código.