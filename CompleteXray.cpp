// CLASS: CompleteXray.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The complete Xray class event
//
//-----------------------------------------

#include "CompleteXray.h"
#include "Patient.h"

CompleteXray::CompleteXray(Patient* p,int timePriority,Staff* technician){
//------------------------------------------------------
// CompleteXray
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient=p;
    this->timePriority=timePriority;
    patient->completeXray=this;
    this->technician=technician;

}

CompleteXray::~CompleteXray() {}
Staff* CompleteXray::getTechnician(){ return technician;} // returns the nurse that completes the assesment
