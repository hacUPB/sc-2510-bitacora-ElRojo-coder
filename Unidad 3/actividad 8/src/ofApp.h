#pragma once
#include "ofMain.h"
#include <vector>

// Clase Sphere
class Sphere {
public:
    Sphere(float x, float y, float radius);
    void draw() const;

    float x, y;
    float radius;
    ofColor color;
};

// Clase principal de la aplicación
class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void exit();

private:
    std::vector<Sphere*> heapSpheres; // Objetos en el heap
    void createObjectInStack();
};

// Declaración del objeto global (debe definirse en ofApp.cpp)
extern Sphere globalSphere;
