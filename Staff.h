// CLASS: Staff.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: Holds the staff object (nurse,doctor and technicians)
//
//-----------------------------------------

#pragma once

class Staff {

private:
    bool available;  // if the staff is available

public:

    Staff();
    bool IsAvailable();
    void meet();
    void setAvailability(bool avail);
};
