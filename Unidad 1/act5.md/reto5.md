Suma el contenido de la posición 0 de la RAM, el contenido de la posición 1 de la RAM y con la constante 69. Guarda el resultado en la posición 2 de la RAM

```asm
@69
D=A  
@0   
D=D+M 
@1   
D=D+M 
@2 
M=D  
```