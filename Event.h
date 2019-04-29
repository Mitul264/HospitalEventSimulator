// CLASS: Event.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The abstract class event
//
//-----------------------------------------


#pragma once
#include "Data.h"
class Staff;
class Patient;

class Event:public Data{

protected:
    Patient* patient;    // the patient associated with this event
public:
    int getPatientPriority()final;
    int getArrivalTime()final;
    Patient* getPatient();          // returns the patient in this event
    int getUnitArrivalTime()override;   // gets patients unit arrival time
    virtual ~Event()=0;




};
