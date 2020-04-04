/*
CSCI 182 - Assignment due 3/9
SimpleListApp.cpp
Linked list class with queue and stack properties

Delwys Glokpor
v1.0 3/8/2020
*/

#include <iostream>
#include "SimpleList.h"

using namespace std;

int main()
{
    SimpleList s1;
    
    // priority type queue
    s1.queueItem(100, Node::HIGH);
    s1.queueItem(200, Node::LOW);
    s1.queueItem(300, Node::MEDIUM);
    s1.queueItem(400, Node::MEDIUM);
    s1.queueItem(500, Node::HIGH);
    s1.queueItem(600, Node::LOW);
    s1.queueItem(700, Node::MEDIUM);

    s1.displayList();
    
}