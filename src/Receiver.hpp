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

/*
 * a class that gets the position of a ship from a remote client over the network
 */
class Receiver
{
    Ship &shipToSet;    // the ship whose position we are getting
    std::thread thread;  // a thread for this to run in
    
    ofxUDPManager udpConnection;  // a network connection to listen on

public:
    
    /*
     * takes a reference to the ship we are sending
     */
    Receiver(Ship &s);
    
    /*
     *  starts the network thread
     *
     *  parameters are the host (IP address or domain name)
     *  and the network port number
     *
     */
    void start(int port);
    
    /*
     *  this is the function that is run in the thread
     *  It does all the actually receiving
     */
    void run();
};


#endif /* Receiver_hpp */
