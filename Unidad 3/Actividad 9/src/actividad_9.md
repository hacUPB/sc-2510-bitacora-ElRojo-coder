# Solución

## ¿Qué sucede cuando presionas la tecla "f"?

Cuando se presiona la tecla **"f"**, el programa elimina el último objeto almacenado en el **heap** dentro del vector `heapObjects`.

## Análisis del código

```cpp
if(!heapObjects.empty()) {
    delete heapObjects.back();  // Libera la memoria del último objeto en el heap
    heapObjects.pop_back();     // Elimina el puntero del vector
}
```

Este fragmento de código verifica si el vector `heapObjects` **no está vacío** antes de intentar eliminar un elemento.

### Explicación de líneas

1. **`delete heapObjects.back();`**
   - `heapObjects.back()` obtiene un **puntero** al último objeto almacenado en el vector.
   - `delete` libera la memoria del objeto en el **heap**, evitando una fuga de memoria.

2. **`heapObjects.pop_back();`**
   - Después de liberar la memoria, `pop_back()` **elimina el puntero del vector**.
   - Esto evita que el vector siga apuntando a una dirección de memoria inválida.


### ¿Qué sucede si no se usa `delete` antes de `pop_back()`?

Si solo se ejecutara:
```cpp
heapObjects.pop_back();
```
- El puntero sería eliminado del vector, pero la memoria en el **heap** seguiría ocupada.
- Esto causaría una **fuga de memoria**, ya que nunca se liberaría la memoria reservada previamente.

### ¿Qué sucede si se usa `delete` pero no `pop_back()`?

Si solo se ejecutara:
```cpp
delete heapObjects.back();
```
- Se liberaría la memoria del último objeto en el heap, pero el puntero seguiría almacenado en el vector.
- Intentar acceder a ese puntero después de eliminarlo podría causar errores de acceso a memoria inválida.

## Conclusiones

- Cuando se presiona la tecla **"f"**, el programa elimina correctamente el último objeto en el **heap**.
- Primero se **libera la memoria** con `delete` y luego se **elimina el puntero** del vector con `pop_back()`.
- Este enfoque previene **fugas de memoria** y errores por acceso a memoria ya liberada.


