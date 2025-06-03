
# Actividad 2

Vas a leer la sección del material de openframeworks, por ahora, solo la sección llamado: What’s a thread and when to use it. Luego de leer, Responde estas preguntas:

- ¿Qué es un hilo?  
Se refiere a un proceso cuya ejecucion **no depende del programa principal**, es decir, que puede ejecutarse en simultaneo del resto.
- ¿Cuándo se usa?  
Generalmente se usa en el caso de necesitar ejecutar una tarea que envuelva alguno de los componentes mas lentos del programa, como **la memoria**, o el **HD**.
- Trata de inferior esto: ¿A qué se puede referir el concepto de tarea ligada a la CPU y a la entrada/salida (E/S)?  
Se podria referir a: Las tareas ligadas a la CPU requieren que la maquina compiladora este la mayor parte del tiempo realizando operaciones, calculos matematicos, procesando algoritmos u ordenando arreglos. Las tereas ligadas a entrada/salida podrian referirse a tareas que hacen que la CPU este solicitando y recibiendo informacion de otros componentes constantemente.  
- ¿Cuál es la relación entre operaciones ligadas a la CPU y los hilos?  
Si hay muchos procesos conectados al uso de la CPU esto puede llevar a que algunos de estos no reciban el tiempo que requieren para ejecutarse, problema que puede solucionarse mediante el uso de hilos, de forma que multiples procesos mas pequeños se esten ejecutando simultaneamente.  
- ¿Cuál es la relación entre operaciones ligadas a la E/S y los hilos?  
En caso de ejecutarse una funcion bloqueante, la maquina tendra que quedarse esperando a que esta se complete para poder continuar, proceso que se puede evitar en su totalidad mediante el uso de hilos, generando un sistema de notificacion, de forma que tan pronto se finalice el proceso la CPU regrese de estar realizando otros procesos y continue en la parte del codigo siguiente.
