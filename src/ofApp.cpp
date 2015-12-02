#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    pressed = true;
    ofSetWindowPosition( 2881, 0 );
    ofSetWindowShape(1920,1080);
    ofToggleFullscreen();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);

    //fft.setup(pow(2.0, 12.0));
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    for (int i = 0; i < num; i++) {
        particles[i].position = ofVec2f(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //fft.update();
    mesh.clear();
    
    for (int i = 0; i < num; i++) {
        particles[i].addAttractionForce(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 1000, 1.0);
        
        particles[i].update();
        particles[i].throughOffWalls();
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    mesh.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        for (int i = 0; i < num; i++) {
            particles[i].position = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());
        }
    }
    if (key == 'd') {
        for (int i = 0; i < num; i++) {
            particles[i].position = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        }
    }
    if (key == 'f') {
        for (int i = 0; i < num; i++) {
            particles[i].position = ofVec2f(ofRandom(1000), ofRandom(ofGetWindowHeight()));
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
