// CLASS: Treatment
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Treatment station
//
//-----------------------------------------

#include "Treatment.h"
#include "Hospital.h"



Treatment::Treatment(Hospital *hospital,int numStaff) {
// Treatment
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
    this->hospital=hospital;


}


void Treatment::report(){
    //------------------------------------------------------
    // report
    //
    // PURPOSE:    completes and prints the report to standard output
    //------------------------------------------------------

    if(numPatients!=0){
        printf("\nTreatment     %3d       %4d      %3.2f      %4d      %3.2f",numPatients,timeActive,timeActive/(numPatients*1.0),timeWaiting,timeWaiting/(numPatients*1.0));

    }else{

        printf("\nTreatment     0       0      0      0      0");
    }

}

Staff* Treatment::staffCheck(){ return Station::staffCheck(staff);}


Treatment::~Treatment() {

    for(int i=0;i<numStaff;i++){    // destruct all the staff
        delete staff[i];
    }
}
