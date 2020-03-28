#ifndef STACK_H_
#define STACK_H_

#include <iostream>
using namespace std;

class Stack {

    struct Card {
        string name;
        string type;
        int atk;
        int def;
    };

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