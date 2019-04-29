// CLASS: StartBloodWork.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The StartBloodWork class event
//
//-----------------------------------------

#include "StartBloodWork.h"
#include "Patient.h"

StartBloodWork::StartBloodWork(Patient* p,int arrivalT){
//------------------------------------------------------
// StartBloodWork
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient=p;
    timePriority=arrivalT;
    arrivalTime=arrivalT;
    patient->startBloodWork=this;
}

int StartBloodWork::getUnitArrivalTime() { return arrivalTime;}
StartBloodWork::~StartBloodWork() {}