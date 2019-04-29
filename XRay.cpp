// CLASS: XRay.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The XRay station
//
//-----------------------------------------

#include "XRay.h"
#include "CompleteXray.h"
#include "Queue.h"
#include "Staff.h"
#include "Hospital.h"
#include "StartXray.h"
#include "Patient.h"
#include "Treatment.h"

XRay::XRay(Hospital *hosp,int numStaff,int xrayT) {
// XRay
//
// PURPOSE:    Constructor
// PARAMETERS:
//    int numStaff-the number of staff in that unit
//------------------------------------------------------
    numPatients=0;
    timeActive=0;
    timeWaiting=0;
    this->numStaff=numStaff;
    staffMaker(staff);
    hospital=hosp;
}



void XRay::report(){
    //------------------------------------------------------
    // report
    //
    // PURPOSE:    completes and prints the report to standard output
    //------------------------------------------------------

    if(numPatients!=0){
        printf("\nXRay          %3d       %4d      %3.2f      %4d      %3.2f",numPatients,timeActive,timeActive/(numPatients*1.0),timeWaiting,timeWaiting/(numPatients*1.0));

    }else{

        printf("\nXRay          0       0      0      0      0");
    }

}

Staff* XRay::staffCheck(){ return Station::staffCheck(staff);}

XRay::~XRay() {

    for(int i=0;i<numStaff;i++){    // destruct all the staff
        delete staff[i];
    }
}