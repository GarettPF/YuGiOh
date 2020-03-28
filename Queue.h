#ifndef QUEUE_H
#define QUEUE_H

#include "game.h"

class Queue {

	private:
		struct QNode {
			Card card;
			QNode *next;
		};

		QNode *front;
		QNode *rear;

		int numItems;
	
	public:
		Queue();
		~Queue();

		void enqueue(Card);
		void dequeue(Card &);

		int count() const {
			return numItems;
		};
		bool isEmpty() const {
			return 0 == count();
		}

		void clear();
};


#endif