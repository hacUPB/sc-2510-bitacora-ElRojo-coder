### Solución

Traduce este programa a lenguaje ensamblador:

 ```asm

@6
D=A
@a
M=D

@9
D=A
@b
M=D

@a
D=M
@b
D=D+M

@c
M=D

@SCREEN
M=D

@END
0;JMP
```
