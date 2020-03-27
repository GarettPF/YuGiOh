#ifndef QUEUE_H
#define QUEUE_H

#include "game.h"

class Queue {

	private:
		struct QueueNode {
			Card card;
			QueueNode *next;
		};

		QueueNode *first;
		QueueNode *last;
	
	public:
		Queue();
		~Queue();

		void enqueue(Card *card);
		void dequeue(Card *card);

		int count() const {
			return 0;
		};
		bool isEmpty() const {
			return 0 == count();
		}
};


#endif