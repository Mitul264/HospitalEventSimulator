// CLASS: StartBloodWork.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The StartBloodWork class event
//
//-----------------------------------------

#pragma once


#include "Event.h"

class StartBloodWork:public Event{

private:
    int arrivalTime;    // arrival time to blood test lab
public:
    StartBloodWork(Patient* p,int arrivalT);
    int getArrivalUnitTime();
    int getUnitArrivalTime() final;   // gets patients unit arrival time
    ~StartBloodWork()final;
};
