//
//  Sender.hpp
//  OnlineGame
//
//  Created by Marco Gillies on 29/02/2016.
//
//

#ifndef Sender_hpp
#define Sender_hpp

#include <stdio.h>
#include <thread>

#include "Ship.hpp"
#include "ofxNetwork.h"

class Sender
{
    Ship &shipToSend;
    std::thread thread;
    
    ofxUDPManager udpConnection;
public:
    
    Sender(Ship &s);
    
    void start(string host, int port);
    
    void run();
};

#endif /* Sender_hpp */
