```c++
if ( (D - 7) == 0) goto a la instrucción en ROM[69]
```
```asm
@7  
D=A   
D=M-D 
@69  
D;JEQ 
```