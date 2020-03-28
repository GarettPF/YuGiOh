#include "Queue.h"

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(Card card) {
    
    QNode *newNode = new QNode;
    newNode->card.name = card.name;
    newNode->card.type = card.type;
    newNode->card.atk = card.atk;
    newNode->card.def = card.def;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

void Queue::dequeue(Card &card) {
    QNode *temp = nullptr;

    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        card = front->card;

        temp = front;

        front = front->next;

        delete temp;

        numItems--;
    }
}

void Queue::clear() {
    Card value;

    while (!isEmpty()) {
        dequeue(value);
    }

}