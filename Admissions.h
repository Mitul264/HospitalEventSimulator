// CLASS: Admissions.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Admissions station
//
//-----------------------------------------

#pragma once
class Hospital;
class Patient;
#include "Station.h"


class Admissions:public Station{

private:
    Hospital *hospital; // the hospital of the station
    Staff* staff[];    // the doctors in the class

public:
    Admissions(Hospital *h,int numStaff);   // constructor
    void report()override;              // report
    ~Admissions()final;
    Staff* staffCheck();

};