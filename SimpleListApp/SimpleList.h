#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

class SimpleList
{
private:
	Node* _head, * _tail;
public:
	/// <summary>
	/// custom exception that signals the end of list reached for dequeue purposes
	/// </summary>
	struct EOL : exception {
		const char* what() const throw() {
			return "Empty List";
		}
	};

	SimpleList() {
		_head = _tail = NULL;
	}
	virtual ~SimpleList();

	void queueItem(int value);
	int deQueueItem();
	void displayList();
};

