// CLASS: Node.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The node class
//
//-----------------------------------------


#include "Data.h"
#pragma once

class Node{

private:
    Node *next;     // the node it points to next
    Data *data;     // the previous node it points to
public:

    Node(Data* data,Node* next); // constructor

    // getters and setters
    Node* getNext();
    Data* getData();
    void setNext(Node* node);


};

