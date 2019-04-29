// CLASS: Queue.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The data structure
//
//-----------------------------------------



#include <cstddef>
#include "Node.h"
#pragma once


class Queue {

private:
    Node *top;  // top of the queue where most priority item is stored.
    void insertHelper(Node* prev,Node* next,Data* data);    // helps insert the item

public:

    Queue();                    // the Queue constructor
    void enqueue(Data *data);   // Ordered inserts the item depending on the priority
    Data *dequeue();    // removes item from queue and returns a pointer to the data value
    Data *peek();       // peeks at the most priority item of the queue
    bool isEmpty();     // returns true if its empty or else returns false
    ~Queue();


};
