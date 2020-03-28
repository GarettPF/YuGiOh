#ifndef STACK_H_
#define STACK_H_

#include "game.h"

class Stack {
    private:
        struct SNode {
            Card card;
            SNode *below;
        };

        SNode *top;
        int numItems;
    
    public:
        Stack();
        ~Stack();

        void push(Card);
        void pop(Card &);

        int count() const {
            return numItems;
        }
        bool isEmpty() const {
            return 0 == count();
        }

        void clear();

};


#endif