// CLASS: Staff.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: Holds the staff object (nurse,doctor and technicians)
//
//-----------------------------------------

#include "Staff.h"


    Staff::Staff(){ available= true;} // constructor

    bool Staff::IsAvailable() { return available; }

    void Staff::meet() {/* simulates the meeting of patient and technician*/}

    void Staff::setAvailability(bool avail){available=avail;}  // sets the staff free
