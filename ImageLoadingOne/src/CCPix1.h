//
//  CCPix1.h
//  ImageLoadingOne
//
//  Created by Eve Weinberg on 4/29/15.
//
//

#ifndef __ImageLoadingOne__CCPix1__
#define __ImageLoadingOne__CCPix1__

#include "ofMain.h"

#include <stdio.h>







class CCPix1 {
    
public:
    void setup();
    void update();
    void draw(int size, ofColor colorvarB);
    
    
    ofPoint centerx;
    ofPoint centery;
    ofColor color;
    ofImage cloud;
    
    
    float pct;
    
};


#endif /* defined(__ImageLoadingOne__Balls__) */
