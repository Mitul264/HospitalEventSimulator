// CLASS: StartXray
//
// Author: Mitul patel, 7851781
//
// REMARKS: The StartXray class event
//
//-----------------------------------------

#include "StartXray.h"
#include "Patient.h"

StartXray::StartXray(Patient *p,int arrivalT) {
    //------------------------------------------------------
// Arrival
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient=p;
    timePriority=arrivalT;
    arrivalTime=arrivalT;
    patient->startXray=this;
}

int StartXray::getUnitArrivalTime() { return arrivalTime;}
StartXray::~StartXray() {}