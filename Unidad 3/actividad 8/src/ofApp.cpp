#include "ofApp.h"

// Definición del objeto global
Sphere globalSphere(300, 300, 30);

// Implementación del constructor de Sphere
Sphere::Sphere(float x, float y, float radius) : x(x), y(y), radius(radius) {
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Sphere::draw() const {
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}

void ofApp::setup() {
    ofBackground(0);
}

void ofApp::update() {
}

void ofApp::draw() {
    // Dibujar objeto en memoria global
    globalSphere.draw();

    // Dibujar objetos en el heap
    for (Sphere* s : heapSpheres) {
        s->draw();
    }

    // Dibujar objeto en stack
    createObjectInStack();
}

void ofApp::keyPressed(int key) {
    if (key == 'h') {
        Sphere* s = new Sphere(ofRandomWidth(), ofRandomHeight(), 30);
        heapSpheres.push_back(s);
    }
}

void ofApp::createObjectInStack() {
    Sphere sphereStack(400, 400, 30);
    sphereStack.draw();
}

void ofApp::exit() {
    for (Sphere* s : heapSpheres) {
        delete s;
    }
    heapSpheres.clear();
}
