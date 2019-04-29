// CLASS: Station.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Station class that holds the four stations
//
//-----------------------------------------

#pragma once
#include <stddef.h>
class Staff;
class Queue;



class Station{

protected:
    int numPatients;    // the number of patients that went through the station
    int numStaff;     // the number of nurses
    int timeWaiting;    // total time patients spent waiting in the station
    int timeActive;           // the total time the station was active

public:

    virtual void report()=0;      // pure virtual method that takes report of every value
    Staff* staffCheck(Staff* staff[]);  // checks to see if staff is free
    void staffMaker(Staff* staff[]);    // makes the staff
    void incrementPatient();                // increments number of patients in the station
    void incrementTimeActive(int time); // increments the active time in the station
    void incrementTimeWaiting(int time);    // // increments the wait time in the station
    virtual ~Station()=0;   // pure virtual destructor
};



