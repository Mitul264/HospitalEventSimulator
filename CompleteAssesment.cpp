// CLASS: CompleteAssesment
//
// Author: Mitul patel, 7851781
//
// REMARKS: The complete assesment class
//
//-----------------------------------------

#include "CompleteAssesment.h"
#include "Patient.h"

CompleteAssesment::CompleteAssesment(Patient* p,int timePriority, Staff* staff) {
//------------------------------------------------------
// CompleteAssesment
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient = p;
    this->timePriority = timePriority;
    nurse=staff;
    patient->completeAssesment=this;
}

CompleteAssesment::~CompleteAssesment() {}

Staff* CompleteAssesment::getNurse(){ return nurse;} // returns the nurse that completes the assesment