//
//  Sender.cpp
//  OnlineGame
//
//  Created by Marco Gillies on 29/02/2016.
//
//

#include "Sender.hpp"


Sender::Sender(Ship &s):shipToSend(s)
{
    
    
}


void Sender::start(string host, int port)
{
    std::cout << host << " " << port << std::endl;
    
    // create a UDP connnection and connect on
    // the host (network address) and port
    udpConnection.Create();
    udpConnection.Connect(host.c_str(),port);
    
    // since it is running in its own thread does not need to be nonblocking
    //udpConnection.SetNonBlocking(true);
    
    // start a thread
    // we are running a lambda function that calls the run method of this class
    thread = std::thread( [this] { this->run(); });
    // detach to thead, which says we aren't waiting for it to end
    thread.detach();
}

void Sender::run()
{
    // since this is a thread it can run an infinite loop
    while (true){
        // get the position of the ship
        ofVec2f pos =shipToSend.getPos();
        
        // construct the message
        std::string message;
        message = message + std::to_string(pos.x) + " " + std::to_string(pos.y);
        
        // send the message via the UDP connection
        udpConnection.Send(message.c_str(), message.length());
        
        // sleep for a bit to avoid sending too many packets
        std::this_thread::sleep_for (std::chrono::milliseconds(300));
    }
}