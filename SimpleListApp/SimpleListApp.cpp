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

    s1.queueItem(100);
    s1.queueItem(200);
    s1.queueItem(300);
    cout << s1.deQueueItem() << endl; // dequeue 100
    s1.displayList();
}