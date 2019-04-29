// CLASS: Treatment
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Treatment station
//
//-----------------------------------------

#pragma once
#include "Station.h"
class Patient;
class Hospital;

class Treatment:public Station{

private:
    Hospital *hospital; // the treatment hospital
    Staff* staff[];    // the doctors in the class

public:
    Treatment(Hospital *hospital,int numStaff);
    void report()override;              // the interpratation of function from parent class
    ~Treatment()final;
    Staff* staffCheck();

};
