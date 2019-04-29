// CLASS: Station.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Station class that holds the four stations
//
//-----------------------------------------

#include "Station.h"
#include "Staff.h"

Staff* Station::staffCheck(Staff* staff[]){

    Staff* retValue=NULL;
    for(int i=0;i<numStaff;i++){

        if(staff[i]->IsAvailable()){
            retValue=staff[i];
            break;
        }
    }
    return retValue;
}

void Station::staffMaker(Staff* staff[]){
    //------------------------------------------------------
    // staffMaker
    //
    // PURPOSE:    adds staff to the station as necessary
    // PARAMETERS:
    //    int numStaff-the number of staff to add
    //
    //------------------------------------------------------

    for(int i=0;i<numStaff;i++){

        staff[i]=new Staff();
    }
}

void Station::incrementPatient(){numPatients++;}
void Station::incrementTimeActive(int time){timeActive+=time;}
void Station::incrementTimeWaiting(int time){timeWaiting+=time;}
Station::~Station() {}
