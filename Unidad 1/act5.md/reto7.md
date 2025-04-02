Si el valor almacenado en la posición 100 de la RAM es menor a 100 salta a la posición 20 de la ROM.
```asm
@100
D=M
D = D - A
@20
D;JLT
```