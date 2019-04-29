// CLASS: Event.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The abstract class event
//
//-----------------------------------------

#include "Event.h"
#include "Patient.h"

int Event::getPatientPriority(){ return patient->getPatientPriority();}  // gets the patients priority
int Event::getArrivalTime(){ return patient->getArrivalTime();}// gets patient arrival time
Patient* Event::getPatient() { return patient;}    // returns the patient
int Event::getUnitArrivalTime(){ return timePriority;}   // gets patients unit arrival time
Event::~Event() {}
