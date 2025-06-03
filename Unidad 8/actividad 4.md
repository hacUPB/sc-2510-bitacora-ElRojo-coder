

# Actividad 4

Vas a solucionar el problema de la actividad anterior usando hilos.

Para solucionar el problema de la actividad anterior, vas a crear un hilo. Observa el siguiente código:

ofApp.h:

```cpp
#pragma once
#include "ofMain.h"
#include "ofThread.h"

class ofApp : public ofBaseApp, public ofThread {
public:
    float x = 0;
    float speed = 3;
    float circleSize = 50;

    void setup();
    void draw();
    void mousePressed(int x, int y, int button);
    void heavyComputation();
    void startHeavyComputation();
    void threadedFunction() override;
    void exit();
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
    lock();
    ofDrawCircle(x, ofGetHeight() / 2, circleSize);
    unlock();
    x = fmod(x + speed, ofGetWidth());
}

void ofApp::mousePressed(int x, int y, int button) {
    if (!isThreadRunning()) {
        ofLog() << "Starting thread";
        startThread();
    }
    else {
        ofLog() << "Thread is already running";
    }
}

void ofApp::threadedFunction() {
    heavyComputation();
    ofLog() << "Thread ends";
}

void ofApp::heavyComputation() {
    double result = 0;
    for (int j = 0; j < 1000000000; ++j) {
        result += sqrt(j);
    }
    lock();
    ofSeedRandom();
    circleSize = ofRandom(20, 70);
    unlock();
    ofLog() << "Circle size: " << circleSize;
}

void ofApp::exit() {
    if (isThreadRunning()) {
        stopThread();
        waitForThread();
    }
}
```

- ¿Qué pasa cuando presionas el mouse?  
Genera 1 condicional que analiza si hay un Thread ejecutandose, en caso de que no inicia un thread y lo registra en la consola, en caso de que si registra en la consola que ya hay un thread en ejecucion. El thread que ejecuta permite ejecutar el metodo `heavyComputation` en simultaneo de que el aplicativo sigue ejecutandose.
- ¿Por qué?  
El condicional existe para evitar colapsar el sistema generando una infinidad de threads complejos, limitandolo a solamente 1. `heavyComputation` primero genera una tarea pesada para dar un motivo al programa de utilizar un Thread para manejarlo, y tras realizarla, randomiza el tamaño del circulo que se dibuja en el void `draw()`.
- ¿Qué hace el hilo?  
El hilo ejecuta la funcion `heavyComputation` y tras completar esa funcion envia una notificacion de completacion por consola.
- ¿Por qué el programa no se congela cuando presionas el mouse?  
Ya que la tarea de `heavyComputation` ya no se procesa al interior del thread `main` del programa, sino que se ejecuta en el thread agregado.
- ¿Qué pasa si presionas el mouse varias veces?  
El programa revisa el condicional, y segun este, respondera denegando la capacidad de agregar mas threads si ya hay uno en proceso.
- ¿Por qué?  
Para no abusar de los recursos de la CPU y, en consecuencia, de arriesgar un posible crash.
- ¿Qué pasa si presionas el mouse varias veces y rápido?  
Simplemente tirara el mismo mensaje de que ya hay un thread en progreso si es asi.
- ¿Por qué?  
Otra vez, no abusar de la capacidad de la CPU.
- Para qué se están usando las funciones lock y unlock?  
Para prevenir el acceso del thread principal a memoria, esto lo hace para evitar que mutiples threads esten intentando acceder a la memoria en simultaneo. En este caso lo que haria es, durante el breve momento en que esta bloqueado, cambiar el valor de `ofSeedRandom()` y `circleSize`, ambas variables, y bloquea el acceso a este para evitar que `draw()` se ejecute por tan solo un momento, y tan pronto se hace el cambio se vuelve a desbloquear. El `void draw()` tiene esta misma funcionalidad, de forma que al momento de interactuar con las variables del circulo, esto no se haga al mismo tiempo.
- ¿Qué está pasando en la función exit?  
Ejecuta 2 funciones de la clase `ofThread`, siendo estas co-dependientes. Primero se da la orden de detener el proceso mediante la linea de codigo `stopThread`, que desde la clase `ofThread` da la orden de establecer el `ThreadRunning` a un valor **false**. Su ultima linea de codigo `waitForThread()` le indica al programa que verifique que el proceso, efectivamente, se detuvo (este metodo es preferible para funciones que contienen un loop-while).
