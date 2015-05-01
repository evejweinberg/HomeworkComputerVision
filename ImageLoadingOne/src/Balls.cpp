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
    
    videoGrabber.initGrabber(640,480);
    colorImg.allocate(videoGrabber.width, videoGrabber.height);
    grayImage.allocate(videoGrabber.width, videoGrabber.height);


aStart.set(ofGetWidth()/2,ofGetHeight()+500);
bEnd.set(ofGetWidth()/2, -1200);
pct = 0;
    
    cloud.loadImage("cloud.png");
    HI.loadImage("HI.png");
    
    


}

//-----------------------------------------------------------------------
void Balls::update(){

    pct += 0.001;   // ie: pct = pct + 0.005
    
    if (pct > 1){
        pct = 0;
    }
    
    
    videoGrabber.update();
    
    bool bNewFrame = false;
    unsigned char * pixels;
    
    pixels = videoGrabber.getPixels();
    bNewFrame = videoGrabber.isFrameNew();
    
    if (bNewFrame){
        colorImg.setFromPixels(pixels, videoGrabber.width, videoGrabber.height);
        
        grayImage = colorImg;
        grayImage.mirror(false, true);
    

}
}

//-----------------------------------------------------------------------
void Balls::draw(){
    int rows;
    
    if (rows >299){
        rows = 0;
    }
    
    for (int k = 0; k < 10; k ++) {
    for (int j = 0; j < 2300; j ++) {
        ofSetColor(0);
        if (j % 2 == 0){
        cloud.draw((70*ofGetElapsedTimef())+(j*500)-4300,600*k,214,91);
        } else {
            ofSetColor(69);
           HI.draw((70*ofGetElapsedTimef())+(j*500)-4300,600*k+300,200,200);
        }
    }
    }
    
    
    float x,y;
    ofPoint(0,0);
    ofPoint(ofGetWidth(),ofGetHeight());
    
    
    float pctShaped =  powf(pct, .5);     //pct * pct;      ///powf(pct, 2);
    ofPoint mixPt = (1.0-pctShaped) * aStart + pctShaped * bEnd;
//    ofSetColor(0);
//    ofCircle(mixPt, 450);
//    
//    ofSetColor(50);
//    ofCircle(mixPt, 350);
//    
//    ofSetColor(100);
//    ofCircle(mixPt, 200);
//    
//    ofSetColor(220);
//    ofCircle(mixPt, 100);
    
    ofSetColor(245);
    ofRect(ofGetWidth()/2,ofGetHeight()/2, 720+80, 720*.75+80);
    
    ofSetHexColor(0xffffff);
    ofSetRectMode (OF_RECTMODE_CENTER);
    grayImage.draw(ofGetWidth()/2,ofGetHeight()/2, 720, 720*.75);
    
    IplImage* eig = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    IplImage* temp = cvCreateImage( cvGetSize(grayImage.getCvImage()), 32, 1 );
    
    cvReleaseImage( &eig );
    cvReleaseImage( &temp );
    
    grayImage.draw(ofGetWidth()/2,ofGetHeight()/2, 640, 480);
    
    
    
    
    
}
