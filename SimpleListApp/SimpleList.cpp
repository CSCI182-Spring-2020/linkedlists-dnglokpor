#include "SimpleList.h"

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

// STACK MANAGEMENT

void SimpleList::push(int value)
{
	Node* newNode = new Node();
	newNode->_data = value; // setting the data
	newNode->_next = NULL; // initialize the next
	if (_head == NULL) {
		_head = _tail = newNode;
	}
	else {
		_tail->_next = newNode; // push at the end
		_tail = newNode; // move the tail to new node
	}
	cout << "Pushed Item: " << value << endl;
}

int SimpleList::pop()
{

	Node* tempNode;
	int tempData;

	if (_head == NULL) {
		return -1;
	}
	else {
		tempNode = _tail; // save node to-be-popped node
		if (_head->_next == NULL) { // last element of stack
			_head = _tail = NULL; // set stack empty
		}
		else {
			_tail = _head; // start from the head
			while (_tail->_next != tempNode) {
				_tail = _tail->_next; // trace back to node before tempNode
			}
			_tail->_next = NULL; // sever to-be-popped node from list
		}
	}
	tempData = tempNode->_data; // retrieve data
	delete tempNode; //  delete popped node
	cout << "popped Item: " << tempData << endl;

	return tempData;
}

void SimpleList::displayList()
{
	Node* itNode = _head; // starts at head
	if (itNode == NULL) {
		cout << "Empty list." << endl;
	}
	else {
		while (itNode != NULL) { // while we are on a valid list
			cout << itNode->_data << endl;
			itNode = itNode->_next;
		}
	}
}

