#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(255);  // Fondo blanco
}

//--------------------------------------------------------------
void ofApp::update() {
    // Mover burbujas hacia arriba
    for (Bubble* b : bubbles) { //  Itera sobre todas las burbujas almacenadas en el vector bubbles. * marca el puntero
        b->y -= b->speed; //Modifica la coordenada y de cada burbuja. Al restar la velocidad (b->speed), la burbuja sube.
    }

    // Eliminar burbujas que ya no se ven. Despu�s de mover las burbujas, ver si alguna ha salido de la pantalla (b->y < 0).
    for (int i = bubbles.size() - 1; i >= 0; i--) {
        if (bubbles[i]->y < 0) {
            delete bubbles[i];                      // liberar memoria. Libera la memoria de la burbuja que ha salido de la pantalla.
            bubbles.erase(bubbles.begin() + i);     // quitar del arreglo. Elimina la burbuja del vector bubbles.
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (Bubble* b : bubbles) { // Itera sobre todas las burbujas.
        ofSetColor(153, 0, 51);  // mi color favvvvv (rojo vinotinto) :P
        ofDrawCircle(b->x, b->y, 10); // Dibuja un c�rculo de 10 p�xeles en la posici�n (b->x, b->y).
    }

    // Instrucci�n en pantalla
    ofSetColor(0); // cambia color negro
    ofDrawBitmapString("Presiona ESPACIO para crear una burbuja", 20, 20); // texto en pantalla. crear una nueva burbuja.
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { // Se ejecuta cuando se presiona una tecla.
    if (key == ' ') { // Si se presiona la espacio, crea una nueva burbuja.
        Bubble* newBubble = new Bubble(); // aqui crea una burbuja din�mica usando new.
        newBubble->x = ofRandom(ofGetWidth()); //posici�n aleatoria en x
        newBubble->y = ofGetHeight(); // burbuja en parte inferior de la pantalla
        newBubble->speed = ofRandom(1, 3); // velocidad aleatoria (1,3)
        bubbles.push_back(newBubble); //  A�ade la nueva burbuja al vector bubbles.
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}
void ofApp::mouseMoved(int x, int y) {}
void ofApp::mouseDragged(int x, int y, int button) {}
void ofApp::mousePressed(int x, int y, int button) {}
void ofApp::mouseReleased(int x, int y, int button) {}
void ofApp::mouseEntered(int x, int y) {}
void ofApp::mouseExited(int x, int y) {}
void ofApp::windowResized(int w, int h) {}
void ofApp::gotMessage(ofMessage msg) {}
void ofApp::dragEvent(ofDragInfo dragInfo) {}
