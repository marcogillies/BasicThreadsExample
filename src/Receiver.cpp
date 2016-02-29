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
    
    udpConnection.Create();
    udpConnection.Bind(11999);
    //udpConnection.SetNonBlocking(true);
    
    
    thread = std::thread( [this] { this->run(); });
    thread.detach();
}


void Receiver::run()
{
    while (true){
        char udpMessage[100000];
        udpConnection.Receive(udpMessage,100000);
        string message=udpMessage;
        std::cout << message << std::endl;;
    }
}