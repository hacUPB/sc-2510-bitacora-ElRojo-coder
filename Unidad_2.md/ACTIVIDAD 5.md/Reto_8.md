# Solución

### `int *pvar;`

- Declara un puntero pvar que puede almacenar la dirección de una variable de tipo int.
- En este punto, pvar no apunta a ninguna dirección válida (puede contener basura si no se inicializa).

### `pvar = var;`
- Esto es un error si var no es una dirección de memoria.
- Si var es una variable entera, entonces pvar = var; intentará asignar un valor entero a un puntero, lo que causará un error de tipo.
- Si var es un puntero, entonces pvar copiará la dirección almacenada en var.

### `var2 = *pvar;`

- `*pvar` obtiene el valor almacenado en la dirección a la que apunta pvar.
- Luego, este valor se asigna a var2.
- Si pvar no ha sido inicializado correctamente con una dirección válida, puede provocar un error de segmentación (segfault).

### `pvar = &var3;`

- Asigna a pvar la dirección de memoria de var3.
- Ahora pvar apunta a var3, por lo que *pvar permitirá acceder y modificar el valor de var3.
