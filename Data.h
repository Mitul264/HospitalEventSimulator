// CLASS: Data.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The data type
//
//-----------------------------------------

#pragma once
class Hospital;

class Data{

public:
    Hospital* hospital; // the hospital they are in
    int timePriority;   // the time priority of the event or patient. its public as its nothing to hide

    virtual int getPatientPriority()=0;           // gets the patients priority and helps make class abstract
    virtual int getArrivalTime()=0;   // gets patient arrival time to hospital helps make class abstract
    virtual int getUnitArrivalTime();   // gets patients unit arrival time
    virtual ~Data();

};


