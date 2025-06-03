#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(18, 112, 60); 
    particleColor = ofColor::white;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    for (auto& pos : particles) {
        ofSetColor(particleColor, 150); // 150 es la opacidad (0 = transparente, 255 = s�lido)
        ofDrawCircle(pos.x, pos.y, ofRandom(10, 50)); // Tama�o aleatorio entre 10 y 50 p�xeles
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    particles.push_back(ofVec2f(x, y));
    if (particles.size() > 15) { // Cambia el n�mero de particulas, de 100 a 10
        particles.erase(particles.begin());
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    particleColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}
