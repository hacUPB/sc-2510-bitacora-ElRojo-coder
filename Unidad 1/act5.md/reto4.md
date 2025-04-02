Lee lo que hay en la posición 100 de la RAM, resta 15 y guarda el resultado en la posición 100 de la RAM

```asm
@15   
D=A   
@100  
D=M-D 
@100  
M=D   
```