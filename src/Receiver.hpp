//
//  Receiver.hpp
//  OnlineGame
//
//  Created by Marco Gillies on 29/02/2016.
//
//

#ifndef Receiver_hpp
#define Receiver_hpp

#include <stdio.h>
#include <thread>

#include "Ship.hpp"
#include "ofxNetwork.h"

class Receiver
{
    Ship &shipToSet;
    std::thread thread;
    
    ofxUDPManager udpConnection;
public:
    
    Receiver(Ship &s);
    
    void run();
};


#endif /* Receiver_hpp */
