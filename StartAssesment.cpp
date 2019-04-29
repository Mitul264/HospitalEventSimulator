// CLASS: StartAssesment.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The start assesment class
//
//-----------------------------------------

#include "StartAssesment.h"
#include "Patient.h"

StartAssesment::StartAssesment(Patient* p,int timePriority){
//------------------------------------------------------
// StartAssesment
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient=p;
    this->timePriority=timePriority;
    patient->startAssesment=this;

}
StartAssesment::~StartAssesment() {}