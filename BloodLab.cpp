// CLASS: BloodLab.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The BloodLab station
//
//-----------------------------------------

#include "BloodLab.h"
#include "Hospital.h"
#include "Staff.h"



BloodLab::BloodLab(Hospital *hosp,int numStaff,int bloodT) {
// BloodLab
//
// PURPOSE:    Constructor
// PARAMETERS:
//    int numStaff-the number of staff in that unit
//    int bloodT- the time taken by one patient in the blood unit
//------------------------------------------------------
    numPatients=0;
    timeActive=0;
    timeWaiting=0;
    this->numStaff=numStaff;
    staffMaker(staff);
    bloodTime=bloodT;
    hospital=hosp;
}



void BloodLab::report(){
    //------------------------------------------------------
    // report
    //
    // PURPOSE:    completes and prints the report to standard output
    //------------------------------------------------------

    if(numPatients!=0){
        printf("\nBlood Work    %3d       %4d      %3.2f      %4d       %3.2f",numPatients,timeActive,timeActive/(numPatients*1.0),timeWaiting,timeWaiting/(numPatients*1.0));

    }else{

        printf("\nBlood Work    0       0      0      0      0");
    }
}

Staff* BloodLab::staffCheck(){
    return Station::staffCheck(staff);
}


BloodLab::~BloodLab() {
    for(int i=0;i<numStaff;i++){    // destruct all the staff
        delete staff[i];
    }
}