Implementa en ensamblador:

```cpp
if R0 >= 0 then R1 = 1
else R1 = –1

(LOOP)
goto LOOP
```

```asm

@R0
D=M         // D = RAM[R0]
@NEGATIVE
D;JLT       // Si D < 0, salta a NEGATIVE
@R1
M=1         // Si no saltó, R1 = 1
@LOOP
0;JMP       // Salta a LOOP (bucle infinito)

(NEGATIVE)
@R1
M=-1        // Si R0 < 0, R1 = -1

(LOOP)
@LOOP
0;JMP       // Bucle infinito

```