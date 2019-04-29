// CLASS: Queue.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The data structure
//
//-----------------------------------------


#include "Queue.h"
#include "Arrival.h"
#include "CompleteAssesment.h"

Queue::Queue() {
    //------------------------------------------------------
    // Queue
    //
    // PURPOSE:    Constructor
    //
    //------------------------------------------------------
    top=NULL;   // the nodes are initially null

}



void Queue::insertHelper(Node* prev,Node* next,Data* data){
    //------------------------------------------------------
    // insertHelper
    //
    // PURPOSE:    helps in the insertion process
    // PARAMETERS:
    //     Node* prev- the prev node pointer
    //     Node* next-the next node pointer
    //     Data data-  the data to be inserted into the queue
    //------------------------------------------------------


    if(prev==NULL){ // if the item being inserted is the biggest item ever

        top=new Node(data,top);     // insert at the beginning

    }else{  // if the item being inserted is in the middle

        prev->setNext(new Node(data,next));     // add item in the middle
    }
}



Data* Queue::dequeue(){
    //------------------------------------------------------
    // dequeue
    //
    // PURPOSE:    removes item from the queue
    //
    // Returns: Data* - a pointer to the data value in the node
    //------------------------------------------------------
    Data* retValue=NULL;

    if(top!=NULL) {

        retValue=top->getData();

        //Node *tempNode = top;            // point the node temporaryly to top
        top = top->getNext();           // change pointers for dequeue

        //delete tempNode;            // delete the node value
    }

    return retValue;    // return the data value
}


Data* Queue::peek(){ return top->getData();}   // peeks onto the queue
bool Queue::isEmpty() { return top==NULL;}      // returns true if empty


void Queue::enqueue(Data *data){
    //------------------------------------------------------
    // enqueue
    //
    // PURPOSE: adds the data item depending on the priority
    // PARAMETERS:
    //     Data *data- the data value to insert into the queue
    //THIS ENQUEUE METHOD STRICTLY INSERTS DEPENDING ON THE TIME PRIORITY, PATIENT PRIORITY AND ARRIVAL TIME*/
    //------------------------------------------------------



    if(top==NULL){  // if the queue is empty

        top=new Node(data,NULL);    // add new item to queues top

    }else{  // the queue has some items inside

        Node* next=top;
        Node* prev=NULL;

        // loop until time priority is smaller than current node. it will drop out if its greaterThan or equalTo
        while(next!=NULL&&data->timePriority>next->getData()->timePriority){

            prev=next;
            next=next->getNext();

        }




            if (next == NULL) {//just insert it because there is no item smaller than or equal to this item priority
                prev->setNext(new Node(data, NULL));     // add to end of queue(smallest item)

            } else {//there are items smaller than or equal to the priority of this item

                // if there are no items that are equal to the time priority of this item then insert at current posn
                if (data->timePriority != next->getData()->timePriority) {

                    insertHelper(prev, next, data);

                } else { // if the next item equals to the time priority of this item

                    // loop until patient time priority== current time priority AND patient priority<current priority
                    while (next != NULL && (data->timePriority == next->getData()->timePriority) &&
                           (data->getPatientPriority() < next->getData()->getPatientPriority())) {

                        prev = next;
                        next = next->getNext();

                    }

                    // if there are no items that are equal to the patient priority of this item then insert at current posn
                    if (next == NULL || ((data->timePriority == next->getData()->timePriority) &&
                                         (data->getPatientPriority() != next->getData()->getPatientPriority()))) {

                        insertHelper(prev, next, data);   // helps insert the item

                    } else { // if the next item equals to the time priority and patient priority of this item

                        // loop until patient time priority== current time priority AND patient priority==current priority AND patient arrival time<current arrival time
                        while (next != NULL && (data->timePriority == next->getData()->timePriority) &&
                               (data->getPatientPriority() == next->getData()->getPatientPriority()) &&
                               (data->getArrivalTime() > next->getData()->getArrivalTime())) {

                            prev = next;
                            next = next->getNext();

                        }

                        // at this point even if timepriority,patientpriority and arrival time is the same, then we have to insert anyway

                        insertHelper(prev, next, data);

                    }
                }
            }

    }
}

Queue::~Queue() {}      // empty destructor...

