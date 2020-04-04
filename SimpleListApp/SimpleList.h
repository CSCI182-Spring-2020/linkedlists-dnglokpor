#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

class SimpleList
{
private:
	Node* _head, * _tail;
public:
	SimpleList() {
		_head = _tail = NULL;
	}
	virtual ~SimpleList();

	void queueItem(int value);
	int deQueueItem();
	void displayList();
};

