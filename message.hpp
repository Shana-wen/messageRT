//
// Created by locate on 2020/8/3.
//

#ifndef MESSAGERT_MESSAGE_HPP
#define MESSAGERT_MESSAGE_HPP

#include <iostream>
#include <mutex>
#include <string>
#include <deque>
#include <thread>


class Message{
public:
    Message();
    ~Message();
    void make();
    std::string RandMessage();
    void SendMessage(std::string &str);
    void ReceiveMessage();

private:
    std::shared_ptr<std::thread> _thread;
    std::mutex locker;
    std::deque<std::string> buff;
    bool _loop{};
};

#endif //MESSAGERT_MESSAGE_HPP
