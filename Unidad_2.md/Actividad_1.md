Solución
1. ¿Qué es la entrada-salida mapeada a memoria?
La entrada-salida (I/O) mapeada a memoria es un mecanismo en el que los dispositivos de entrada y salida, como una pantalla o un teclado, están directamente vinculados a ubicaciones específicas de la memoria RAM. En lugar de usar instrucciones especiales para interactuar con los dispositivos, el procesador puede leer y escribir en estas direcciones de memoria como si fueran variables normales.

2.¿Cómo se implementa en la plataforma Hack?
En la plataforma Hack, la entrada y salida se manejan mediante dos regiones de la memoria RAM:

Pantalla: La memoria comienza en la dirección 16384 (0x4000). Cada bit en esta área representa un píxel en una pantalla de 512x256 píxeles. Un bit en 1 representa un píxel negro, y un bit en 0 representa un píxel blanco.
Teclado: Se encuentra en la dirección 24576 (0x6000). Cuando una tecla es presionada, se almacena su código ASCII en esta dirección. Si ninguna tecla está presionada, el valor en esta dirección es 0.
3. Inventa un programa que haga uso de la entrada-salida mapeada a memoria.

``` ASM
@SCREEN   // Dirección base de la pantalla
D=A
@addr     // Guarda en una variable temporal
M=D

(LOOP)
@KBD      // Lee el teclado
D=M
@DRAW
D;JNE     // Si alguna tecla está presionada, ir a DRAW
@CLEAR
0;JMP     // Si no, ir a CLEAR

(DRAW)
@addr
D=M
@32
D=D+A     // Avanza una fila en la pantalla
@addr
M=D
A=D
M=-1      // Pinta 16 píxeles en negro
@LOOP
0;JMP     // Repetir

(CLEAR)
@addr
D=M
@32
D=D+A
@addr
M=D
A=D
M=0       // Borra 16 píxeles
@LOOP
0;JMP
```
4. Explora cómo funciona el programa utilizando el simulador.
Cuando se presiona una tecla, el programa pinta un bloque negro en la pantalla.
Si no se detecta ninguna tecla presionada, la pantalla se limpia.
El programa opera en un ciclo continuo, revisando constantemente el estado del teclado y actualizando la memoria de la pantalla según corresponda.
