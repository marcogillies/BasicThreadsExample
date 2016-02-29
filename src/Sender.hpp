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

/*
 * a class that sends the position of a ship over the network
 */
class Sender
{
    Ship &shipToSend;    // the ship whose position we are sending
    std::thread thread;  // a thread for this to run in
    
    ofxUDPManager udpConnection;  // a network connection to send on
public:
    /*
     * takes a reference to the ship we are sending
     */
    Sender(Ship &s);
    
    /* 
     *  starts the network thread
     *
     *  parameters are the host (IP address or domain name)
     *  and the network port number
     *
     */
    void start(string host, int port);      
    
    /*
     *  this is the function that is run in the thread
     *  It does all the actually sending
     */
    void run();
};

#endif /* Sender_hpp */
