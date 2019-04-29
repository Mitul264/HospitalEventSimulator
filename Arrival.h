// CLASS: Arrival.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Arrival class event
//
//-----------------------------------------

#pragma once
#include "Event.h"

class Arrival:public Event{

public:
    Arrival(Patient* p,int timePriority);
    ~Arrival()final;

};

