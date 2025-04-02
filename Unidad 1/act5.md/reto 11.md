Considera el siguiente programa:

```asm
i = 1000
LOOP:
if (i == 0) goto CONT
i = i - 1
goto LOOP
CONT:
````


La traducción a lenguaje ensamblador del programa anterior es:

```asm
// i = 1000
@1000
D=A
@i
M=D
(LOOP)
// if (i == 0) goto CONT
@i
D=M
@CONT
D;JEQ
// i = i - 1
@i
M=M-1
// goto LOOP
@LOOP
0;JMP
(CONT)

```

### ¿Qué hace el programa?

Se genera un bucle de una cuenta regresiva desde 1000 hasta 0.

- Inicializa i = 1000.

Entonces:

- Si i == 0, salta a CONT y finaliza el bucle.
- Si i > 0, decrementa i y vuelve a LOOP.

### ¿En qué memoria está almacenada la variable i? ¿En qué dirección de esa memoria?

- i es una variable definida por el usuario, por lo que se almacena en la RAM.
- Las variables de usuario se almacenan desde la dirección RAM[16] en adelante.
- Como i es la primera variable declarada, se asigna a la dirección RAM[16].

#### ¿En qué parte de la memoria está almacenado el comentario //i = 1000?

Los comentarios no se almacenan en memoria, ya que son ignorados por el ensamblador. Sirven únicamente como referencia para los programadores y estos no afectan la ejecución del código.

#### ¿Cuál es la primera instrucción del programa anterior? ¿En qué memoria y en qué dirección de memoria está almacenada esa instrucción?

La primera instrucción es:
```asm
@1000
```

Esta instrucción carga el valor 1000 en el registro D. las instrucciones se almacenan en la ROM (memoria de solo lectura) y la primera instrucción está en ROM[0].

#### ¿Qué son LOOP y CONT?

Son etiquetas utilizadas para marcar direcciones en el código. No ocupan espacio en la RAM, pero el ensamblador las traduce a direcciones de la ROM.

- El LOOP marca el inicio del bucle.
- El COOT marca la salida del bucle.

#### ¿Cuál es la diferencia entre los símbolos i y CONT?

i es una variable que almacena un valor númerico en la RAM, mientras que CONT es una instrucción de dirección donde el programa puede saltar. El CONT es una etiqueta del ROM.