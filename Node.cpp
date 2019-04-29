// CLASS: Node.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The node class
//
//-----------------------------------------

#include "Node.h"

Node::Node(Data* data,Node* next){

    //------------------------------------------------------
    // Node
    //
    // PURPOSE:    constructor
    // PARAMETERS:
    //    Data* data- the data item
    //    Node* next- the next item
    //------------------------------------------------------

    this->data=data;
    this->next=next;
}


// getters and setters for the node class

Node* Node::getNext(){ return next;}
Data* Node::getData(){ return data;}
void Node::setNext(Node* node){next=node;}


