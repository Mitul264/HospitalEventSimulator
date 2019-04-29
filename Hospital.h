// CLASS: Hospital.h
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Hospital class
//
//-----------------------------------------



#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
#define CONST 5

class Admissions;
class BloodLab;
class XRay;
class Treatment;
class Patient;
class Staff;
class Queue;

using namespace std;


class Hospital{

private:

    string line;       // the linne read as input
    string fileName;        // the string file name
    ifstream readFromFile;     // will be used to read from file
    string str[CONST];     // global variable
    Admissions* admissions;     // the admissions station
    BloodLab* bloodLab;     // the blood lab station
    XRay* xRay;         // the xray station
    Treatment* treatment;   // the treatment station
    int currTime;   // the current time on the time clock
    Queue *admissionsQueue; // the queue for admission patients
    Queue *bloodQueue; // the queue for blood patients
    Queue *xrayQueue; // the queue for xray patients
    Queue *treatmentQueue; // the queue for treatment patients
    Queue *eventsQ; // the queue for events



public:

    Hospital(string filename,int numNurses,int numBloodStaff,int numXrayStaff,int numDoc,int bloodTime,int xRayTime);  // constructor
    Patient *nextPatient();     // the next patient


    // from admissions
    void startAdmissions();     // starts admissions
    void arrival(Patient *p);   // patients arrival
    void startAssesment(Patient *p,Staff* nurse);
    void completeAssesment(Patient *patient2,Staff* nurse);  // processes complete assesment

    // getters for stations
    Admissions* getAdmissions();
    BloodLab* getBloodLab();
    XRay* getXray();
    Treatment* getTreatment();
    void run();
    ~Hospital();

    // methods for the BloodLab
    void newPatientBloodLab(Patient *patient);
    void bloodTest(Patient *patient,Staff* technician);
    void startBloodWork(Patient *patient,Staff* technician);


        // methods for treatment
    void newPatientTreatment(Patient *patient);
    void treatmentTest(Patient *patient,Staff* doctor);
    void startXrayWork(Patient *patient,Staff* technician);

    // methods for xray
    void newPatientXray(Patient *patient);
    void xrayTest(Patient *patient,Staff* technician);
    void startTreatmentWork(Patient *patient,Staff* technician);


    };
