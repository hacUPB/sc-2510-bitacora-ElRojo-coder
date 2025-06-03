# Actividad 1

### **1. Diferencia entre *programa* y *proceso***  
- **Programa**:  
  - Es un **archivo ejecutable** (por ej., `chrome.exe`, `main.py`) almacenado en disco.  
  - Contiene código binario, datos estáticos y metadatos (pero no se ejecuta por sí solo).  
- **Proceso**:  
  - Es una **instancia en ejecución** de un programa, cargado en memoria RAM.  
  - Tiene su propio espacio de direcciones, recursos (CPU, memoria, archivos abiertos) y estado (registros, stack, heap).  

**Ejemplo**:  
- El navegador Chrome es un *programa*.  
- Cada pestaña abierta es un *proceso* independiente.  

---

### **2. ¿Múltiples procesos ejecutando el mismo programa?**  
**¡Sí!** Puedes tener varios procesos corriendo el mismo programa. Cada uno tendrá:  
- Su propia memoria y recursos.  
- Estados independientes (ej., diferentes inputs o datos).  

**Ejemplo**:  
- Abrir 3 terminales ejecutando `/usr/bin/python3`: cada una es un proceso distinto.  

---

### **3. ¿Para qué sirve el *stack* de un proceso?**  
- Almacena:  
  - **Variables locales** de funciones.  
  - **Llamadas a funciones** (call stack): dirección de retorno, argumentos.  
  - Datos temporales (ej., resultados intermedios).  
- **Características**:  
  - Crece y se reduce automáticamente (LIFO: Last-In-First-Out).  
  - Tamaño fijo (si se llena, ocurre un *stack overflow*).  

---

### **4. ¿Para qué sirve el *heap* de un proceso?**  
- Almacena:  
  - **Memoria dinámica** (reservada con `malloc()`, `new`, etc.).  
  - Estructuras de datos grandes o de tamaño variable (ej., listas, objetos).  
- **Características**:  
  - Asignación/liberación manual (o con recolectores de basura).  
  - Fragmentación posible.  

**Ejemplo**:  
```c
int *arr = malloc(100 * sizeof(int)); // Se almacena en el heap.
```

---

### **5. ¿Qué es la *zona de texto* (text segment) de un proceso?**  
- Parte de la memoria que almacena:  
  - **Código máquina** del programa (instrucciones ejecutables).  
  - Es de **solo lectura** (para evitar modificaciones accidentales).  

**Ejemplo**:  
- Las funciones `main()`, `setup()`, `draw()` de tu programa están aquí.  

---

### **6. ¿Dónde se almacenan las variables globales *inicializadas*?**  
- En el **segmento de datos inicializados** (`data segment`).  
- Ejemplo:  
  ```c
  int x = 42;  // Variable global inicializada → data segment.
  ```

### **7. ¿Dónde se almacenan las variables globales *no inicializadas*?**  
- En el **segmento BSS** (Block Started by Symbol).  
- Se inicializan a `0`/`NULL` automáticamente.  
- Ejemplo:  
  ```c
  int y;  // Variable global no inicializada → BSS.
  ```

---

### **8. Estados posibles de un proceso**  
Los estados varían según el SO, pero en general:  
1. **Nuevo (New)**: Recién creado.  
2. **Listo (Ready)**: Esperando asignación de CPU.  
3. **En ejecución (Running)**: Usando la CPU.  
4. **Bloqueado/Espera (Waiting)**: Esperando un recurso (ej., I/O).  
5. **Terminado (Terminated)**: Finalizó su ejecución.  

**En sistemas Unix/Linux**:  
- Se añaden estados como:  
  - **Zombie**: Proceso terminado pero aún en la tabla de procesos.  
  - **Detenido (Stopped)**: Pausado por una señal (ej., `SIGSTOP`).  

**Diagrama típico**:  
```
New → Ready ↔ Running → Terminated  
          ↓      ↑  
          Waiting  
```

---

### **Resumen visual de la memoria de un proceso**  
```
+-------------------+  
|       Stack       | (Variables locales, LIFO)  
+-------------------+  
|        ↓          |  
|                   |  
|        ↑          |  
+-------------------+  
|       Heap        | (Memoria dinámica)  
+-------------------+  
|       BSS         | (Variables globales no init)  
+-------------------+  
|       Data        | (Variables globales init)  
+-------------------+  
|       Text        | (Código ejecutable)  
+-------------------+  
```
