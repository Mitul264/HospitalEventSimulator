// CLASS: StartTreatment.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The StartTreatment class event
//
//-----------------------------------------


#include "Event.h"
#pragma once


class StartTreatment:public Event{
    int arrivalTime;
public:
    StartTreatment(Patient* p,int arrivalTime);
    int getUnitArrivalTime() final;   // gets patients unit arrival time
    ~StartTreatment()final;

};
