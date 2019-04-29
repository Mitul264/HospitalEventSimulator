// CLASS: Patient.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The patient in the hospital
//
//-----------------------------------------

#include "Patient.h"

int Patient::numPatients=1;     // the static int that holds patient number..

Patient::Patient(Hospital *h, int arrivalTm, bool bloodTst, bool XrayTest, int treatMentTm,
                 int priorityP, int assesmentT) {
    //------------------------------------------------------
    // Patient
    //
    // PURPOSE:    Constructor
    // PARAMETERS:
    //     int arrivalTm- the arrival time of patient in the hospital
    //     bool bloodTst- if patient needs a bloodtest
    //     bool XrayTest-if the patient needs an Xray
    //     int treatMentTm- the patients treatment time
    //     int priorityP-patients priority
    //------------------------------------------------------
    arrivalTime=arrivalTm;
    bloodTest=bloodTst;
    xRayTest=XrayTest;
    treatmentTime=treatMentTm;
    priority=priorityP;
    timePriority=arrivalTm;
    hospital=h;
    assesmentTime=assesmentT;
    this->patientNo=numPatients++;
}

Patient::~Patient() {
    //------------------------------------------------------
    // ~Patient
    //
    // PURPOSE:    destructor
    //------------------------------------------------------

    delete arrival;
    delete startAssesment;

    if(startBloodWork){
        delete startBloodWork;
        delete completeBloodWork;

    }

    if(startXray){
        delete startXray;
        delete completeXray;

    }
    delete startTreatment;
    delete completeAssesment;
    delete discharge;
}


// the getters
int Patient::getPatientPriority (){ return priority;} // returns the patients priority
int Patient::getArrivalTime(){ return arrivalTime;}  // returns the patients arrival time
int Patient::getAssesmentTime() { return assesmentTime;} // asesment time
bool Patient::getBloodTest() { return bloodTest;}
bool Patient::getXrayTest() { return xRayTest;}
int Patient::getTreatmentTime() { return treatmentTime;}
int Patient::getPatientNo() { return patientNo;}




