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

/*
 * A basic class that is controlled
 * by either the local or remove player
 */
class Ship
{
    ofVec2f pos;       // position
    ofColor col;       // colour
    float speed = 5;   // movement speed
    bool ai = false;   // whether it is acting autonomously
    
    std::mutex mutex;  // this is controlled by several threads so we need a mutex

public:
    
    /*
     *   The constructor just takes the position as a parameter
     */
    Ship(int x, int y);
    
    /*
     *  get the current position
     */
    ofVec2f getPos()
    {
        // lock the mutex for all operations
        // that change the position
        std::lock_guard<std::mutex> guard(mutex);
        
        return pos;
    }
    
    /*
     *  set the current position
     */
    void setPoint(float x, float y){
        // lock the mutex for all operations
        // that change the position
        std::lock_guard<std::mutex> guard(mutex);
        
        pos.set(x,y);
    }
    
    
    /*
     *  start autonomous "AI" behaviour
     */
    void startAI(){
        ai = true;
    }
    
    /*
     *  draw the ship
     */
    void display();
    
    /*
     *  movement commands
     */
    void up(){
        // lock the mutex for all operations
        // that change the position
        std::lock_guard<std::mutex> guard(mutex);
        
        pos.y -= speed;
    }
    void down(){
        // lock the mutex for all operations
        // that change the position
        std::lock_guard<std::mutex> guard(mutex);
        
        pos.y += speed;
    }
    void left(){
        // lock the mutex for all operations
        // that change the position
        std::lock_guard<std::mutex> guard(mutex);
        
        pos.x -= speed;
    }
    void right(){
        // lock the mutex for all operations
        // that change the position
        std::lock_guard<std::mutex> guard(mutex);
        
        pos.x += speed;
    }
};

#endif /* Ship_hpp */
