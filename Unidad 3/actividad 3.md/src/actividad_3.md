# Solución

| Función                      | Propósito                                                                          |
|------------------------------|------------------------------------------------------------------------------------|
| `setup()`                    | Inicializa el fondo en negro y el color de las partículas en blanco.               |
| `update()`                   | No hace nada en esta versión.                                                      |
| `draw()`                     | Dibuja los últimos 100 movimientos del mouse como círculos de color.               |
| `mouseMoved(x, y)`           | Agrega la posición del mouse al vector y elimina la más antigua si hay más de 100. |
| `mousePressed(x, y, button)` | Cambia el color de las partículas a un color aleatorio.                            |

### Experimentos realizados

##### En Setup():

 - **ofBackground(15, 120, 34):** Cambiar el color en RGB, Red: 15 , Green: 120 , Blue: 34

##### En Draw():

- **ofSetColor(particleColor, 150):** 150 es la opacidad (0 = transparente, 255 = sólido)
- **ofDrawCircle(pos.x, pos.y, ofRandom(10, 50)):** Define un tamaño aleatorio entre 10 y 50 píxeles
