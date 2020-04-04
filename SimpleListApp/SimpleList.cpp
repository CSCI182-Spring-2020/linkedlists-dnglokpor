#include "SimpleList.h"
// constructor
SimpleList::~SimpleList()
{
	
	Node* currentNode = _head; // gets the head of the current list
	while (_head != NULL) {
		currentNode = _head;
		_head = _head->_next;
		delete currentNode;
	}

}

// QUEUE MANAGEMENT
// append an item to the list
void SimpleList::queueItem(int value)
{
	Node* newNode = new Node();
	newNode->_data = value; // setting the data
	newNode->_next = NULL; // initialize the next
	if (_head == NULL) {
		_head = _tail = newNode;
	}
	else{
		_tail->_next = newNode; // link new node
		_tail = newNode; // move tail to last item
	}
	cout << "Queued Item: " << value << endl;
}

// insert item in the list sorting by priority
void SimpleList::queueItem(int value, Node::Priority priority) {
	Node* itNode = _head;
	Node* newNode = new Node();

	newNode->_data = value;
	newNode->_priority = priority;
	newNode->_next = NULL;

	if (_head == NULL) { // case of empty list
		_head = _tail = newNode;
	}
	else { // one or more elements
	   // #havePriority will be true when #newNode have higher priority than the next node.
	   // check for absolute comparison so the new item is inserted after other items of same
	   // priority.
		bool havePriority = _head->_priority < newNode->_priority;

		// loops through list and stops when #havePriority is true to insert or end of list
		// if #newNode have higher priority than #_head, the loop will be skipped.
		while (itNode->_next != NULL && !havePriority)
		{
			havePriority = itNode->_next->_priority < newNode->_priority;
			if (!havePriority)
				itNode = itNode->_next;
		}

		// insertion in the list
		if (itNode == _head) {
			if (_head->_priority < newNode->_priority) {
				// insert before #_head
				newNode->_next = _head;
				_head = newNode;
			}
			else {
				// insert after #_head
				newNode->_next = _head->_next;
				_head->_next = newNode;
				if (itNode == _tail) // list was a singleton
					_tail = newNode; // adjust #_tail
			}
		}
		else if (itNode == _tail) { // new item has lowest priority
		   // insert after #_tail
			_tail->_next = newNode;
			_tail = newNode;
		}
		else { // we can just insert after the last Node checked #pNode
			newNode->_next = itNode->_next;
			itNode->_next = newNode;
		}

	}
	cout << "Queued Item: " << "[" << priority << "] " << value << endl;
}

// pull item of the list from the head
int SimpleList::deQueueItem()
{
	
	Node* tempNode;
	int tempData;

	if (_head == NULL) {
		return -1;
	}
	else {
		tempNode = _head;
		_head = _head->_next; // moving head
		if (_head == NULL) {
			// there was only one object in the list
			_tail = NULL; // clear tail
		}
	}
	tempData = tempNode->_data;
	delete tempNode;
	cout << "Dequeued Item: " << tempData << endl;

	return tempData;
}

// display all items of the list from #_head to #_tail
void SimpleList::displayList()
{
	Node* itNode = _head; // starts at head
	if (itNode == NULL) {
		cout << "Empty list." << endl;
	}
	else {
		int i = 0;
		while (itNode != NULL) { // while we are on a valid list
			cout << "Item no." << ++i << " " << itNode->_data << endl;
			itNode = itNode->_next;
		}
	}
}

