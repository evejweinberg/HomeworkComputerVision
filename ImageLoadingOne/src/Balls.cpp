//
//  Balls.cpp
//  ImageLoadingOne
//
//  Created by Eve Weinberg on 4/28/15.
//
//

#include "Balls.h"


//-----------------------------------------------------------------------
void Balls::setup(){

aStart.set(ofGetWidth()/2,ofGetHeight()+500);
bEnd.set(ofGetWidth()/2, -1200);
pct = 0;
    
    cloud.loadImage("cloud.png");
    
}



//-----------------------------------------------------------------------
void Balls::update(){

  
    pct += 0.001;   // ie: pct = pct + 0.005
    
    if (pct > 1){
        pct = 0;
    }
}





//-----------------------------------------------------------------------
void Balls::draw(){
    
    
    for (int k = 0; k < 30; k ++) {
    for (int j = 0; j < 30; j ++) {
        ofSetColor(20);
        cloud.draw(50*ofGetElapsedTimef()*j,300*k,214,91);
    }
        
    }
    
    float x,y;
    ofPoint(0,0);
    ofPoint(ofGetWidth(),ofGetHeight());
    
    
    float pctShaped =  powf(pct, .5);     //pct * pct;      ///powf(pct, 2);
    ofPoint mixPt = (1.0-pctShaped) * aStart + pctShaped * bEnd;
    ofSetColor(80);
    ofCircle(mixPt, 450);
    
    ofSetColor(50);
    ofCircle(mixPt, 350);
    
    ofSetColor(20);
    ofCircle(mixPt, 100);
    
    ofSetColor(30);
    ofCircle(mixPt, 50);
    
//    for (int i = 0; i < 20; i ++) {
//        
//        ofSetColor(30);
//        ofCircle(300*i, ofGetElapsedTimef()*i*20, 20);
//        ofSetColor(70);
//        ofCircle(200*i, ofGetElapsedTimef()*i*20, 10);
//
//    }
    
    
}
