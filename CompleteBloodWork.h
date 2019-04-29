// CLASS: CompleteBloodWork.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The CompleteBloodWork class event
//
//-----------------------------------------


#include "Event.h"
#pragma once


class CompleteBloodWork:public Event{

private:
    Staff* technician;      // technician performing this task

public:
    CompleteBloodWork(Patient* p,int timePriority,Staff* technician);
    ~CompleteBloodWork() final;
    Staff* getTechnician();
};