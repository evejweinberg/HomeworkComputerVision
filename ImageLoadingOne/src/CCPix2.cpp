#include "CCPix2.h"
#include "Balls.h"

//-----------------------------------------------------------------------
void CCPix2::setup(){

    
}



//-----------------------------------------------------------------------
void CCPix2::update(){
    
}





//-----------------------------------------------------------------------
void CCPix2::draw(int size, ofColor colorvarB){
    //    ofSetRectMode (OF_RECTMODE_CENTER);
    
    
    ofSetColor(colorvarB);
    ofCircle(0,0,size,size);
    blendMode = OF_BLENDMODE_MULTIPLY;
    ofSetColor(100,100,100,50);
    ofCircle(0,0,size/2,size/2);
    ofSetColor(100,100,100,50);
    ofCircle(0,0,size/4,size/4);
}
