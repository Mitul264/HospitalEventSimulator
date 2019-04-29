// CLASS: XRay.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The XRay station
//
//-----------------------------------------

#pragma once
#include "Station.h"
class Hospital;
class Patient;
class StartXray;



class XRay:public Station{

private:
    Hospital *hospital;
    Staff* staff[];    // the doctors in the class

public:
    XRay(Hospital *hosp,int numStaff,int bloodT);
    void report()override;   // the interpratation of function from parent class
    ~XRay()final;
    Staff* staffCheck();


};
