¿Qué hace este programa?

- En qué posición de la memoria está `var1`, `var2` y `var3`? ¿Por qué en esas posiciones?

```asm
@var1
D = M
@var2
D = D + M
@var3
M = D
```

- Suma var1 y var2 y almacena el resultado en var3.

- var1, var2, y var3 se almacenan en la RAM a partir de la posición 16, ya que las variables comienzan desde esa dirección.