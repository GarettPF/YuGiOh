#include "Stack.h"

Stack::Stack() {
    top = nullptr;
    numItems = 0;
}

Stack::~Stack() {
    Card value;

    while (!isEmpty()) {
        pop(value);
    }
}

void Stack::push(Card card) {
    SNode *newNode = new SNode;
    newNode->card.name = card.name;
    newNode->card.type = card.type;
    newNode->card.atk = card.atk;
    newNode->card.def = card.def;
    newNode->below = nullptr;

    if (isEmpty()) {
        top = newNode;
    } else {
        newNode->below = top;
        top = newNode;
    }
    numItems++;
}

void Stack::pop(Card &card) {
    SNode *temp = nullptr;

    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        card = top->card;

        temp = top;

        top = top->below;

        delete temp;
    }
    numItems--;
}

void Stack::clear() {
    Card value;

    while (!isEmpty()) {
        pop(value);
    }

}