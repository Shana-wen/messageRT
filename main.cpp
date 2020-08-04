/*
 * @: 2020/8/4
 * @: 子线程发消息，主线程接受消息
 * @：wen
 * */

#include "message.hpp"

int main()
{
    Message news;
    news.ReceiveMessage();
    return 0;
}
