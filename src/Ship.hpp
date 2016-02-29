//
//  Ship.hpp
//  OnlineGame
//
//  Created by Marco Gillies on 29/02/2016.
//
//

#ifndef Ship_hpp
#define Ship_hpp

#include "ofMain.h"

#include <stdio.h>

class Ship
{
    ofVec2f pos;
    ofColor col;
    float speed = 5;

public:
    
    Ship(int x, int y);
    
    ofVec2f getPos()
    {
        return pos;
    }
    
    void setPoint(float x, float y){
        pos.set(x,y);
    }
    
    void display();
    
    void up(){
        pos.y -= speed;
    }
    void down(){
        pos.y += speed;
    }
    void left(){
        pos.x -= speed;
    }
    void right(){
        pos.x += speed;
    }
};

#endif /* Ship_hpp */
