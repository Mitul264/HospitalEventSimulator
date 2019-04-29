// CLASS: StartXray
//
// Author: Mitul patel, 7851781
//
// REMARKS: The StartXray class event
//
//-----------------------------------------


#include "Event.h"
#pragma once


class StartXray:public Event{

private:
    int arrivalTime;    // arrival time to blood test lab

public:
    StartXray(Patient* p,int arrivalT);
    int getUnitArrivalTime() final;   // gets patients unit arrival time
    ~StartXray()final;

};

