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
    
    // stack form FILO
    s1.push(200); // pushed 300
    s1.push(300); // pushed 300
    cout << s1.pop() << endl; // popped 300
    cout << s1.pop() << endl; // popped 200
    
    // emptied s1

    s1.queueItem(100);
    s1.queueItem(200);
    s1.push(300);
    s1.push(400);
    s1.displayList();
    
}