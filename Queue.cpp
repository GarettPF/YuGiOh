#include "Queue.h"

Queue::Queue() {
    first = NULL;
    last = NULL;
}

Queue::~Queue() {
    free(first);
    free(last);
}

void Queue::enqueue(Card *card) {
    
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode*));
    newNode->card.name = card->name;
    newNode->card.type = card->type;
    newNode->card.atk = card->atk;
    newNode->card.def = card->def;
    newNode->next = NULL;

    if (isEmpty()) {
        first = newNode;
    } else if (first->next == NULL) {

    }

}