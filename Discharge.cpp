// CLASS: discharge
//
// Author: Mitul patel, 7851781
//
// REMARKS: The discharge class event
//
//-----------------------------------------

#include "Discharge.h"
#include "Patient.h"

Discharge::Discharge(Patient* p,int timePriority,Staff* technician){
//------------------------------------------------------
// Discharge
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
    patient=p;
    this->timePriority=timePriority;
    patient->discharge=this;
    this->technician=technician;

}

void Discharge::discharge() {
    //------------------------------------------------------
    // discharge
    //
    // PURPOSE:    performs discharge of  the patient
    //------------------------------------------------------

    //delete patient;
}

Staff* Discharge::getTechnician(){ return technician;} // returns the nurse that completes the assesment
Discharge::~Discharge() {}  // delete this

