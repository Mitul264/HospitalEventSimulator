// CLASS: Arrival
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Arrival class event
//
//-----------------------------------------

#include "Arrival.h"
#include "Patient.h"

Arrival::Arrival(Patient* p,int timePriority){
//------------------------------------------------------
// Arrival
//
// PURPOSE:    Constructot
// PARAMETERS:
//    Patient *P-the patient in the event
//    timePriority-the time priority of the event
//------------------------------------------------------
patient=p;
patient->arrival=this;
this->timePriority=timePriority;
patient->arrival=this;
}

Arrival::~Arrival() {}

