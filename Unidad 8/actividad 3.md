# Actividad 3

Vas a explorar la necesidad de tener un hilo cuando un programa tiene que hacer una tarea intensiva ligada a la CPU.

Ejecuta el siguiente programa:

ofApp.h:

```cpp
#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    float x = 0;
    float speed = 3;
    float circleSize = 50;

    void setup();
    void draw();
    void mousePressed(int x, int y, int button);
    void heavyComputation();
};
```

ofApp.cpp:

```cpp
#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofSetWindowShape(400, 400);
}

void ofApp::draw() {
    ofBackground(220);
    ofSetColor(0);
    ofDrawCircle(x, ofGetHeight() / 2, circleSize);
    x = fmod(x + speed, ofGetWidth());
}

void ofApp::mousePressed(int x, int y, int button) {
    heavyComputation();
}

void ofApp::heavyComputation() {
    double result = 0;
    for (int j = 0; j < 1000000000; ++j) {
        result += sqrt(j);
    }
    circleSize = ofRandom(20, 70);
    ofLog() << "Circle size: " << circleSize;
}
```

- ¿Qué pasa cuando presionas el mouse?  
El programa se congela.
- ¿Por qué?  
La CPU se sobreexplota por la cantidad de 1) operaciones, 2) cosas que debe escribir en el log.
- Considerando la definición de un hilo, ¿cómo podrías solucionar el problema de que el programa se congele cuando presionas el mouse?  
ofApp.h
```cpp
#pragma once
#include "ofMain.h"

class HeavyCalc : public ofThread {

public:

    float circleSize = 50;

    void threadedFunction() {


        double result = 0;
        for (int j = 0; j < 1000000000; ++j) {
            result += sqrt(j);
        }
        circleSize = ofRandom(20, 70);
        ofLog() << "Circle size: " << circleSize;
    }
};

class ofApp : public ofBaseApp {
public:
    float x = 0;
    float speed = 3;
    bool loading;

    void setup();
    void draw();
    void mousePressed(int x, int y, int button);
    HeavyCalc heavyCalc;
};
```
