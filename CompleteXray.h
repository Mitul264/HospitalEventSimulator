// CLASS: CompleteXray.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The complete Xray class event
//
//-----------------------------------------



#include "Event.h"
#pragma once


class CompleteXray:public Event{
private:
    Staff* technician;      // technician performing this task

public:
    CompleteXray(Patient* p,int timePriority,Staff* technician);
    ~CompleteXray() final;
    Staff* getTechnician();

};