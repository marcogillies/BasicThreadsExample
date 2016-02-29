//
//  Receiver.cpp
//  OnlineGame
//
//  Created by Marco Gillies on 29/02/2016.
//
//

#include "Receiver.hpp"

Receiver::Receiver(Ship &s):shipToSet(s)
{
    
}

void Receiver::start(int port)
{
    std::cout << port << std::endl;
    
    
    // create a UDP connnection and bind to the port
    udpConnection.Create();
    udpConnection.Bind(port);
    
    // since it is running in its own thread does not need to be nonblocking
    //udpConnection.SetNonBlocking(true);
    
    
    // start a thread
    // we are running a lambda function that calls the run method of this class
    thread = std::thread( [this] { this->run(); });
    // detach to thead, which says we aren't waiting for it to end
    thread.detach();
}


void Receiver::run()
{
    // since this is a thread it can run an infinite loop
    while (true){
        // get data from the network and turn it into a string
        char udpMessage[100000];
        udpConnection.Receive(udpMessage,100000);
        string message=udpMessage;
        
        // use a istringstream to parse it into 2 ints
        istringstream iss(message);
        float x, y;
        iss >> x >> y;
        
        // set the position
        shipToSet.setPoint(x, y);
    }
}