//
// Created by locate on 2020/8/3.
//

#include "message.hpp"


Message::Message()
{
    _loop=true;
    _thread=std::make_shared<std::thread>(&Message::make,this);
}

Message::~Message()
{
    _loop= false;
}

std::string Message::RandMessage()
{
    std::string str{};
    int sim{};
    sim=rand()%3;
    if(sim==0)
    {
        str="Message0";
    }
    if(sim==1)
    {
        str="Message1";
    }
    if(sim==2)
    {
        str="Message2";
    }
    return str;
}

void Message::make()
{
    std::string sendStr{};
    while(_loop)
    {
        sendStr=RandMessage();
        SendMessage(sendStr);
    }
}

void Message::SendMessage(std::string &str)
{

    {
        locker.lock();
        if(buff.size()<20)
        {
            buff.push_back(str);
        }
//        std::cout<<buff.at(0)<<std::endl;
        locker.unlock();
    }
}

void Message::ReceiveMessage()
{
    while(_loop)
    {
        locker.lock();
        if(!buff.empty())
        {
            std::cout<<"(INFO): "<<buff.at(0)<<std::endl;
            buff.pop_front();
        }
        locker.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

