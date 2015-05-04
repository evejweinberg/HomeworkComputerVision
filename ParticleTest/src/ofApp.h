#pragma once

#include "ofMain.h"
#include "particle.h"
#include "spring.h"

class ofApp : public ofBaseApp{

	public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage Head;
    ofImage Ring;
    ofImage GeneralDuties;
    ofImage PullEverything;
    
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    ofColor purple;
    
    ofPoint circlePos1, circlePos2, circlePos3, circlePos4, circlePos5, circlePos6, circlePos7;
    
    // let's make a vector of them
    vector <particle> particles;
    vector <spring> springs;
    
    ofPoint CirclePos[7];
		
};
