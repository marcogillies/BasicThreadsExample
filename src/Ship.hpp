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
    bool ai = false;
    
    std::mutex mutex;

public:
    
    Ship(int x, int y);
    
    ofVec2f getPos()
    {
        std::lock_guard<std::mutex> guard(mutex);
        return pos;
    }
    
    void setPoint(float x, float y){
        std::lock_guard<std::mutex> guard(mutex);
        pos.set(x,y);
    }
    
    void startAI(){
        ai = true;
    }
    
    void display();
    
    void up(){
        std::lock_guard<std::mutex> guard(mutex);
        pos.y -= speed;
    }
    void down(){
        std::lock_guard<std::mutex> guard(mutex);
        pos.y += speed;
    }
    void left(){
        std::lock_guard<std::mutex> guard(mutex);
        pos.x -= speed;
    }
    void right(){
        std::lock_guard<std::mutex> guard(mutex);
        pos.x += speed;
    }
};

#endif /* Ship_hpp */
