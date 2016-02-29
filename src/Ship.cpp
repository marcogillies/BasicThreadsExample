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
    ofSetColor(col);
    ofFill();
    ofCircle(pos.x, pos.y, 20);
}