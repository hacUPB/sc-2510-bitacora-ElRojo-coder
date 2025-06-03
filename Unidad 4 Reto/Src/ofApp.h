#pragma once
#include "ofMain.h"

// Estructura para representar una burbuja
struct Bubble { //  Define una estructura llamada Bubble para representar una burbuja.
    float x, y, speed; 
    /*float x: La coordenada x de la burbuja (horizontal).

      float y: La coordenada y de la burbuja (vertical).

      float speed: La velocidad con la que sube la burbuja.*/
};

class ofApp : public ofBaseApp {
public:
    void setup(); // setup(): Se ejecuta al principio, solo una vez, para inicializar la aplicaci�n.
    void update(); // update(): Se llama cada frame, y es donde actualizamos el estado de los objetos (como mover las burbujas).
    void draw(); // draw(): Se llama cada frame para dibujar los objetos en la pantalla.

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    std::vector<Bubble*> bubbles;  // Cola de burbujas (punteros). 

    /*Un vector din�mico de punteros a Bubble. Esto permite almacenar m�ltiples burbujas, cada una creada din�micamente con new (lo veremos en ofApp.cpp). 
    El vector act�a como una lista que crece seg�n sea necesario.*/
};
