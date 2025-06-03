# Solución

### ¿Qué fue lo que incluimos en el archivo .h?

El archivo ofApp.h contiene la declaración de la clase ofApp, que hereda de ofBaseApp. En él, se incluyen:

#### Métodos principales de openFrameworks:

- **setup():** Se ejecuta al inicio.
- **update():** Se ejecuta en cada frame antes de draw().
- **draw():** Dibuja en la ventana.

#### Métodos para manejar eventos del mouse:

- **mouseMoved(int x, int y):** Se activa cuando el mouse se mueve.
- **mousePressed(int x, int y, int button):** Se activa cuando se presiona un botón del mouse.

#### Variables privadas:

 - **vector<ofVec2f> particles:** Almacena posiciones de partículas (coordenadas en 2D).
- **ofColor particleColor:** Almacena el color actual de las partículas.

#### ¿Cómo funciona la aplicación?

Esta aplicación crea un efecto visual en el que:

- Se dibujan círculos en las posiciones donde el usuario mueve el mouse.
- Se almacenan hasta 100 posiciones (cuando se superan, se eliminan las más antiguas).
- Si el usuario hace clic, el color de las partículas cambia aleatoriamente.

#### ¿Qué hace la función mouseMoved?

Cada vez que el usuario mueve el mouse:

- Agrega la posición actual (x, y) al vector particles.
- Si el vector supera los 100 elementos, elimina el primero (particles.erase(particles.begin())), asegurando que solo se dibujen los últimos 100 movimientos.

**Efecto:** Se genera una cola de partículas, creando una especie de "trazo" que sigue el cursor.

#### ¿Qué hace la función mousePressed?

Cada vez que el usuario hace clic:

- Cambia el color de las partículas a un color aleatorio usando ofRandom(255), que genera valores entre 0 y 255 para rojo, verde y azul.

**Efecto:** Al hacer clic, las partículas cambian de color.

#### ¿Qué hace la función setup?
Se ejecuta una vez al inicio:

- Configura el fondo en negro (ofBackground(0)).
- Inicializa el color de las partículas en blanco (particleColor = ofColor::white).

#### ¿Qué hace la función update?

En este caso, no hace nada porque está vacía. Su propósito normalmente sería actualizar la lógica del programa antes de dibujar en pantalla.

#### ¿Qué hace la función draw?

Dibuja todas las partículas almacenadas en particles:

- Recorre el vector particles con un for (for(auto &pos: particles)).
- Configura el color de las partículas (ofSetColor(particleColor)).
- Dibuja círculos en cada posición (x, y) con un radio de 50 píxeles (ofDrawCircle(pos.x, pos.y, 50)).

**Efecto:** Muestra los últimos 100 movimientos del mouse como círculos que cambian de color cuando se hace clic.
