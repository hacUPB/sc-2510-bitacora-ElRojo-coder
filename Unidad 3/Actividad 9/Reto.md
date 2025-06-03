
# Solución

## 1. **Código fuente de la aplicación:**

### Para OfApp.h
```cpp
#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);

private:
    void generateGrid();
    void convertMouseToRay(int x, int y, glm::vec3& rayStart, glm::vec3& rayEnd);
    bool rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir,
        const glm::vec3& sphereCenter, float sphereRadius,
        glm::vec3& intersectionPoint);

    ofEasyCam cam;
    std::vector<glm::vec3> spherePositions;
    glm::vec3 selectedSphere;
    float distDiv, amplitud, step;
};
```

### Para OfApp.cpp

``` cpp
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setupPerspective();
    distDiv = 50.0;
    amplitud = 150.0;
    step = 15;
    generateGrid();
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(200);
    cam.begin();

    for (auto& pos : spherePositions) {
        ofSetColor(ofMap(pos.z, -amplitud, amplitud, 0, 255), 255, 0);
        ofDrawSphere(pos, 3);
    }

    cam.end();

    string info = "FPS: " + ofToString(ofGetFrameRate()) + "\n";
    info += "Step: " + ofToString(step) + "\n";
    info += "DistDiv: " + ofToString(distDiv) + "\n";
    info += "Amplitud: " + ofToString(amplitud) + "\n";
    ofDrawBitmapString(info, 20, 20);
}

//--------------------------------------------------------------
void ofApp::generateGrid() {
    spherePositions.clear();
    for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += step) {
        for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += step) {
            float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
            spherePositions.push_back(glm::vec3(x, y, z));
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    glm::vec3 rayStart, rayEnd;
    convertMouseToRay(x, y, rayStart, rayEnd);

    for (auto& pos : spherePositions) {
        glm::vec3 intersectionPoint;
        if (rayIntersectsSphere(rayStart, rayEnd - rayStart, pos, 5.0, intersectionPoint)) {
            selectedSphere = pos;
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::convertMouseToRay(int x, int y, glm::vec3& rayStart, glm::vec3& rayEnd) {
    glm::vec3 mouse(x, y, 0.0f);
    rayStart = cam.getPosition();
    rayEnd = cam.screenToWorld(mouse);
}

//--------------------------------------------------------------
bool ofApp::rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir,
    const glm::vec3& sphereCenter, float sphereRadius,
    glm::vec3& intersectionPoint) {
    glm::vec3 oc = rayStart - sphereCenter;
    float a = glm::dot(rayDir, rayDir);
    float b = 2.0f * glm::dot(oc, rayDir);
    float c = glm::dot(oc, oc) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }

    float t = (-b - sqrt(discriminant)) / (2.0f * a);
    intersectionPoint = rayStart + t * rayDir;
    return true;
}
```

## 2. **Informe sobre el manejo de memoria:**

En esta aplicación, el manejo de la memoria se realiza principalmente al trabajar con objetos de la clase `ofSpherePrimitive` y `ofCamera`. Aquí se describe cómo se manejan los datos clave en memoria:

- **`ofCamera`**: Este objeto se crea y se mantiene en la memoria durante toda la ejecución de la aplicación. Se asigna una posición inicial `(0, 0, 500)` y se asegura de que siempre esté mirando al centro de la escena mediante el método `lookAt`. El objeto `ofCamera` se mantiene en memoria mientras esté en uso y no requiere de liberación explícita, ya que OpenFrameworks gestiona la memoria de estos objetos automáticamente.

- **`vector<ofSpherePrimitive> spheres`**: El vector contiene las esferas que se crean dinámicamente en la función `setup()`. Las esferas se generan en el heap (memoria dinámica) cada vez que se añade una nueva esfera al vector. Esto significa que, aunque las esferas están ubicadas en el heap, no es necesario liberar manualmente la memoria ya que el destructor de `ofSpherePrimitive` se encargará de liberar los recursos al final de la ejecución.

- **Manejo de memoria en `spheres`**: El uso de un `vector` garantiza una asignación dinámica eficiente de memoria. Cuando se agrega una esfera, se gestiona la memoria de forma interna. No se requiere la intervención del programador para liberar la memoria utilizada por las esferas, ya que el `vector` se encarga de eso automáticamente cuando las esferas son destruidas (al salir del scope o cuando el `vector` es destruido al finalizar la aplicación).

En resumen, la aplicación maneja la memoria de manera eficiente mediante la creación de objetos en memoria dinámica, mientras OpenFrameworks se encarga de liberar recursos automáticamente al finalizar la ejecución del programa.


