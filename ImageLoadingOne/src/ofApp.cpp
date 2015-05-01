#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    art.loadImage("Spot01_13.jpg");
    art.setImageType(OF_IMAGE_GRAYSCALE);
    
//    STD.loadMovie("Save The Date-HD.mp4");
//    STD.setLoopState(OF_LOOP_NORMAL);
//    STD.play();

    ofBackground(255,255,255);
    ofSetCircleResolution(100);
    Balls.setup();
    CCPix1.setup();
//    CCPix2.setup();
    


}

//--------------------------------------------------------------
void ofApp::update(){
//    STD.update();
    Balls.update();
    CCPix1.update();
//    CCPix2.update(); //I have no idea why I cant succesfully use CCPix2 in this project. If I un-comment all of the 'CCPix2 related' code it Fails.
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetRectMode (OF_RECTMODE_CENTER);
    Balls.draw(); // draw everything in this object to the screen
  
    ofImage screen;
    screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight()); //capture the screen in real time

    ofClear(0,0,0); //clear it
    ofBackground(255); //white background
    int gridsize = ofMap(mouseX, 0, ofGetWidth(),5,50);
    
    for (int i=0; i<screen.width; i+=gridsize){
        for (int j=0; j< screen.height; j+=gridsize){
            ofColor myColor = screen.getColor(i,j); //get the color of every 10 pixels
            float brightness = myColor.getBrightness(); // get the brightness of the color
            float length = ofMap(brightness,0,255,1,12);
            if (brightness >=0 && brightness < 40){
                colorvar = ofColor :: darkTurquoise;
            } else if (brightness >= 40 && brightness < 69 ){
                colorvar = ofColor :: cornflowerBlue;
            } else if (brightness >= 69 && brightness <= 70 ){
                colorvar = ofColor :: coral;
            } else if (brightness > 70 && brightness <=120){
                colorvar = ofColor :: aqua;
            } else if (brightness > 120 && brightness <=200){
                colorvar = ofColor :: cyan;
            } else if (brightness > 200 && brightness <215){
                colorvar = ofColor :: lawnGreen;
            } else if (brightness > 215 && brightness <255){
                colorvar = ofColor :: yellow;
                } else if (brightness == 255){
                colorvar = ofColor :: pink;
                    
        }
            float angle = ofMap(brightness,0,255,0, 0); //90 degrees
            float size = ofMap(brightness,0,255, gridsize, 5);
            ofPushMatrix();
            ofTranslate (i,j);
            ofRotateZ(angle);
            if (brightness >= 50){
            CCPix1.draw(size, colorvar);
            } else if (brightness <50) {
            CCPix1.draw(size, colorvar);
            }
            ofPopMatrix();
        }
    }
    



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
