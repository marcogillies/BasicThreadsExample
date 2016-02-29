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
    
    udpConnection.Create();
    udpConnection.Bind(port);
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
        //std::cout << message << std::endl;;
        istringstream iss(message);
        float x, y;
        iss >> x >> y;
        shipToSet.setPoint(x, y);
        
        std::this_thread::sleep_for (std::chrono::milliseconds(300));
    }
}