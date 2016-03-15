//
//  Ship.cpp
//  OnlineGame
//
//  Created by Marco Gillies on 29/02/2016.
//
//

#include "Ship.hpp"

Ship::Ship(int x, int y): pos(x, y)
{
    col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ship::display()
{
    // lock the mutex for all operations
    // that change the position
    std::lock_guard<std::mutex> guard(mutex);
    
    // the "AI" code, really not worthy of the name
    if(ai){
        pos.x += 1;
    }
    
    // drawing code
    ofSetColor(col);
    ofFill();
    ofCircle(pos.x, pos.y, 20);
}