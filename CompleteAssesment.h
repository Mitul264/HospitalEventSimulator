// CLASS: CompleteAssesment.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The complete assesment class
//
//-----------------------------------------



#include "Event.h"
#pragma once


class CompleteAssesment:public Event{
private:
    Staff* nurse;       // the nurse that complete assesment
public:
    CompleteAssesment(Patient* p,int timePriority,Staff* staff);
    Staff* getNurse();      // returns the nurse that completes the assesment
    ~CompleteAssesment() final;
};

