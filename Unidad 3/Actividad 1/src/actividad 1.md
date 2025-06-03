# Solución

### ¿Cuál es el resultado que se obtiene al ejecutar este programa?

La ventana de la aplicación tendrá un fondo negro.

- Un círculo blanco de radio 20 píxeles seguirá la posición del cursor del mouse en tiempo real.
- No hay rastro del círculo en posiciones anteriores, ya que cada cuadro se borra y redibuja con el nuevo fondo negro.

Es básicamente un pincel dinámico que sigue el cursor sin dejar huella.

### Análisis del código

- **setup():** Se llama una vez al inicio y establece el fondo en negro (ofBackground(0)).
- **update():** Se ejecuta en cada frame, pero en este caso no realiza ninguna acción.
- **draw():** Se ejecuta en cada frame, establece el color de dibujo en blanco (ofSetColor(255)) y dibuja un círculo con radio 20 píxeles en la posición actual del cursor (ofGetMouseX(), ofGetMouseY()).






