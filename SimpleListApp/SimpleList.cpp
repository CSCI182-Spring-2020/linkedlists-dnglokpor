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

// pull the first element of the list
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

// display all elements of the list from #_head to #_tail
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

