#ifndef STACK_H_
#define STACK_H_

#include "game.h"

class Stack {
    private:
        struct StackNode {
            Card card;
            StackNode *below;
        };

        StackNode *top;
    
    public:
        Stack();
        ~Stack();

        void push(Card *card);
        void pop(Card *card);

};


#endif