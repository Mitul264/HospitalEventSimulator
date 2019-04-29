// CLASS: discharge.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The discharge class event
//
//-----------------------------------------

#include "Event.h"
#pragma once


class Discharge:public Event{

private:
    Staff* technician;      // technician performing this task


public:
    Discharge(Patient* p,int timePriority,Staff* technician);
    void discharge();               // performs discharge of the patient
    ~Discharge()final;
    Staff* getTechnician();


};
