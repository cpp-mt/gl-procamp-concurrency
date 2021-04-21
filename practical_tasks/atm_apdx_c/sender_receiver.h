#pragma once
#include "msg_queue.h"
#include "dispatcher.h"

namespace messaging
{
    class sender {
        queue *q;
    public:
        sender():
            q(nullptr)
        {}
        explicit sender(queue*q_):
            q(q_)
        {}
        template<typename Message> 
        void send(Message const& msg) {
            if(q) {
                q->push(msg);
            }
        }
    };

    class receiver
    {
        queue q;
    public:
        operator sender() {
            return sender(&q);
        }
        dispatcher wait() {
            return dispatcher(&q);
        }
    };
}


