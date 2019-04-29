// CLASS: StartAssesment.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The start assesment class
//
//-----------------------------------------


#include "Event.h"
#pragma once


class StartAssesment:public Event{

public:
    StartAssesment(Patient* p,int timePriority);
    ~StartAssesment()final;
};
