// CLASS: Patient.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The patient in the hospital
//
//-----------------------------------------

#pragma once
#include "Data.h"


class Patient:public Data{



private:

    // stores the patients information
    int arrivalTime;
    int assesmentTime;
    bool bloodTest;
    bool xRayTest;
    int treatmentTime;
    Hospital* hospital; // the hospital they are in
    int priority;
    int patientNo;      // patient number
    static int numPatients;     // the static int that gives unique patient numbers



public:
    Patient(Hospital *h,int arrivalTm,bool bloodTst,bool XrayTest,int treatMentTm,int priorityP,int assesmentT);

    // stores the events of patients

    // LETS LEAVE THEM PUBLIC FOR NOW
    Data* arrival;
    Data* startAssesment;
    Data* startBloodWork;
    Data* startXray;
    Data* startTreatment;
    Data* completeBloodWork;
    Data* completeAssesment;
    Data* completeXray;
    Data* discharge;

    int xrayArrivalTime;
    int bloodLabArrivalTime;
    int treatmentArrivalTime;


    int getPatientPriority()override;  // returns the patients priority
    int getArrivalTime()override;      // returns arrivval time of patient to hosp
    int getAssesmentTime();         // gives initial assesement time
    bool getBloodTest();            // returns true if patient needs blood test
    bool getXrayTest();             // returns true if patient needs xRay
    int getTreatmentTime();         // returns the treatment time
    int getPatientNo();
    ~Patient();

};


