// CLASS: StartTreatment.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The StartTreatment class event
//
//-----------------------------------------

#include "StartTreatment.h"
#include "Patient.h"

StartTreatment::StartTreatment(Patient* p,int arrivalTime){
//------------------------------------------------------
// StartTreatment
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient=p;
    this->arrivalTime=arrivalTime;
    timePriority=arrivalTime;
    patient->startTreatment=this;

}

int StartTreatment::getUnitArrivalTime() { return arrivalTime;}
StartTreatment::~StartTreatment() {}