// CLASS: Admissions.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Admissions station
//
//-----------------------------------------

#include "Admissions.h"
#include "Staff.h"
#include "Hospital.h"



Admissions::Admissions(Hospital *h,int numStaff) {
// Admissions
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
    hospital=h;

}

void Admissions::report(){
    //------------------------------------------------------
    // report
    //
    // PURPOSE:    completes and prints the report to standard output
    //------------------------------------------------------

    cout << "\n\n ...Simulation complete.  Final Summary:\n";
    cout << "\n               Total       Service Time          Wait Time";
    cout << "\n  Station     patients    Total   Average      Total   Average ";


    if(numPatients!=0){
        printf("\nAssessment    %3d       %4d      %3.2f      %4d       %3.2f",numPatients,timeActive,timeActive/(numPatients*1.0),timeWaiting,timeWaiting/(numPatients*1.0));

    }else{

        printf("\nAssessment    0       0      0      0      0");
    }

}

Staff* Admissions::staffCheck(){ return Station::staffCheck(staff);}

Admissions::~Admissions(){

    for(int i=0;i<numStaff;i++){    // destruct all the staff
        delete staff[i];
    }

}