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
    
    udpConnection.Create();
    udpConnection.Connect(host.c_str(),port);
    //udpConnection.SetNonBlocking(true);
    
    
    thread = std::thread( [this] { this->run(); });
    thread.detach();
}

void Sender::run()
{
    while (true){
        ofVec2f pos =shipToSend.getPos();
        std::string message;
        message = message + std::to_string(pos.x) + " " + std::to_string(pos.y);
        udpConnection.Send(message.c_str(), message.length());
        //std::cout << shipToSend.getPos() << std::endl;;
        
        std::this_thread::sleep_for (std::chrono::milliseconds(300));
    }
}