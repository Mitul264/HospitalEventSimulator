// CLASS: CompleteBloodWork.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The CompleteBloodWork class event
//
//-----------------------------------------

#include "CompleteBloodWork.h"
#include "Patient.h"

CompleteBloodWork::CompleteBloodWork(Patient* p,int timePriority,Staff* technician){
//------------------------------------------------------
// CompleteBloodWork
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient=p;
    this->timePriority=timePriority;
    patient->completeBloodWork=this;
    this->technician=technician;

}

Staff* CompleteBloodWork::getTechnician(){ return technician;} // returns the nurse that completes the assesment
CompleteBloodWork::~CompleteBloodWork() {}
