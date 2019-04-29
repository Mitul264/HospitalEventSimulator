// CLASS: BloodLab.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The BloodLab station
//
//-----------------------------------------

#pragma once
#include "Station.h"
class Hospital;
class Patient;

class BloodLab:public Station{

private:
    int bloodTime;
    Hospital *hospital; // the hospital of the station
    Staff* staff[];    // the doctors in the class

public:
    BloodLab(Hospital *hosp,int numStaff,int bloodT);
    void report()override;              // the interpratation of function from parent class
    ~BloodLab()final;
    Staff* staffCheck();

};

