```asm
i = 1
sum = 0
sum = sum + i
i = i + 1
```

#### ¿Qué hace el programa?

- Inicializa i en 1.
- Inicializa sum en 0.
- Suma el valor de i a sum y almacena el resultado en sum.
-Incrementa i en 1.

#### ¿En qué parte de la memoria RAM están i y sum?

Las variables i y sum se almacenan en la RAM a partir de la dirección 16.

- Las variables de usuario comienzan desde la dirección RAM-16 y se asignan en orden de aparición en el código.

Como i y sum son variables no predefinidas recibirán las primeras direcciones disponibles:
- i en RAM[16]
- sum en RAM[17]

#### Optimizado en dos instrucciones

```asm
@i
M=M+1
```