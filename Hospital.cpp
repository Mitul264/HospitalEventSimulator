// CLASS: Hospital.cpp
//
// Author: Mitul patel, 7851781
//
// REMARKS: The Hospital class
//
//-----------------------------------------

#include "BloodLab.h"
#include "Patient.h"
#include "Admissions.h"
#include "StartBloodWork.h"
#include "StartXray.h"
#include "StartTreatment.h"
#include "CompleteAssesment.h"
#include "CompleteBloodWork.h"
#include "CompleteXray.h"
#include "Discharge.h"
#include "Arrival.h"
#include "Queue.h"
#include "Staff.h"
#include "A2Const.hpp"
#include "Hospital.h"
#include "XRay.h"
#include "Treatment.h"
#include "StartAssesment.h"
#include <stdio.h>
#include <cstring>

using namespace std;


Hospital::Hospital(string fileName,int numNurses,int numBloodStaff,int numXrayStaff,int numDoc,int bloodTime,int xRayTime){
    // Hospital
    //
    // PURPOSE:    Constructor
    //------------------------------------------------------

    bloodLab=new BloodLab(this,numBloodStaff,bloodTime);
    xRay=new XRay(this,numXrayStaff,xRayTime);
    treatment=new Treatment(this,numDoc);
    admissions=new Admissions(this,numNurses);
    this->fileName=fileName;
    currTime=0;
    admissionsQueue=new Queue();
    bloodQueue=new Queue();
    xrayQueue=new Queue();; // the queue for xray patients
    treatmentQueue=new Queue();; // the queue for treatment patients
    eventsQ=new Queue(); // the queue for events
}

Patient* Hospital::nextPatient() {
    //------------------------------------------------------
    // nextPatient
    //
    // PURPOSE:    returns the next patient in the hospital
    // RETURNS:  Patient* - the next patient from hospital
    //
    //------------------------------------------------------

    int assesmentTime;
    int patientPriority;
    int arrivalTime;
    int treatmentTime;
    bool bloodTest=false;   // if the patient needs a blood test
    bool xrayTest=false;    // if the patient needs an xRay tesy

    Patient *retValue=NULL;
    char* ptr;
    char* lineC;

    if(!readFromFile.eof()){    // if we havent reacched the end of file

        getline(readFromFile,line); // get the line from the file



            while (!line.empty()) {


                if (line.at(0) != '#') {
                    break;
                } else {

                    getline(readFromFile, line); // get the line from the file
                }
            }

            if(!line.empty()) {


                lineC = (char *) line.c_str();
                ptr = strtok(lineC, " ");

                if (ptr) {
                    arrivalTime = atoi(ptr); // convert the next value to int arrivalTime
                    ptr = strtok(NULL, " ");

                    if (ptr) {
                        assesmentTime = atoi(ptr); // convert the next value to int assesment time
                        ptr = strtok(NULL, " ");

                        if (ptr) {
                            patientPriority = atoi(ptr); // convert the next value to int patient priorirty
                            ptr = strtok(NULL, " ");

                            if (ptr) {


                                if (ptr[0] == 'B') {    // if bloodtest needed
                                    bloodTest = true;
                                }
                                if (ptr[1] == 'X') {   // if xray needed
                                    xrayTest = true;
                                }
                                ptr = strtok(NULL, " ");

                                if (ptr) {    // the treatment time
                                    treatmentTime = atoi(ptr); // convert the next value to int

                                    // new patient created here
                                    retValue = new Patient(this, arrivalTime, bloodTest, xrayTest, treatmentTime,
                                                           patientPriority, assesmentTime);

                                }
                            }
                        }
                    }
                }
            }else{
                readFromFile.close();       // close the file

            }


    }else{
        readFromFile.close();       // close the file
    }

    return retValue;

}

void Hospital::run(){
    //------------------------------------------------------
    // run
    //
    // PURPOSE: runs the simulation process
    //
    //------------------------------------------------------


    const char* name=fileName.c_str();
    readFromFile.open(name);

    if(readFromFile.is_open()){ // open file

        startAdmissions();

    }else{  // if the file is not existing
        cout << "File not Found. Run again...\n";
    }

}

Hospital::~Hospital() {
    delete admissions;
    delete bloodLab;
    delete xRay;
    delete treatment;
}






/*###############ADMISSIONS METHODS#######################*/



void Hospital::startAdmissions() {
    //------------------------------------------------------
    // startAdmission
    //
    // PURPOSE:    starts the admissions station and lets in patients
    //------------------------------------------------------

    Arrival *arrivalEvent;    // stores if current event is an arrival
    CompleteAssesment *completeAssesment1; // stores if current event is an startassesment
    CompleteBloodWork *completeBloodWork1;
    CompleteXray *completeXray1;
    Discharge *discharge1;
    Data *data;


    Patient *patient = nextPatient();   // gets the patient to the blood lab


    if (patient) {   // if we have at least one patient

        arrivalEvent = new Arrival(patient, patient->getArrivalTime());

        arrival(patient);    // lets process arrival of that patient

        while (!eventsQ->isEmpty()) {  // while the events queue is not empty

            data = eventsQ->dequeue();

            if (dynamic_cast<Arrival *>(data)) {   // if its an instance of arrival

                arrivalEvent = dynamic_cast<Arrival *>(data);
                arrival(arrivalEvent->getPatient());     // processing the arrival event

            } else if (dynamic_cast<CompleteAssesment *>(data)) {   // if the event is a complete assesment

                completeAssesment1 = dynamic_cast<CompleteAssesment *>(data);
                completeAssesment(completeAssesment1->getPatient(),completeAssesment1->getNurse());   // processes the complete assesment event
                
            } else if (dynamic_cast<CompleteBloodWork *>(data)) {   // if the event is a complete blood test

                completeBloodWork1 = dynamic_cast<CompleteBloodWork *>(data);
                bloodTest(completeBloodWork1->getPatient(),completeBloodWork1->getTechnician());
                
            }else if (dynamic_cast<CompleteXray *>(data)) {   // if the event is a complete Xray test

                completeXray1 = dynamic_cast<CompleteXray *>(data);
                xrayTest(completeXray1->getPatient(),completeXray1->getTechnician());
                
            }else if (dynamic_cast<Discharge *>(data)) {   // if the event is a complete Xray test

                discharge1 = dynamic_cast<Discharge *>(data);
                treatmentTest(discharge1->getPatient(),discharge1->getTechnician());
            }
        }
    }
}


void Hospital::arrival(Patient *patient) {
    //------------------------------------------------------
    // arrival
    //
    // PURPOSE:    processes arrival if patient
    // PARAMETERS:
    //      Patient *patient- the patient that has arrived.
    //      Arrival *arrival- the arrival event to be processed
    //
    //------------------------------------------------------

    Patient* newPatient;
    Arrival* newArrival;

    currTime=patient->getArrivalTime();        // sets current time to patients arrival time
    admissions->incrementPatient();             // increment patients in admissions

    Staff* nurse=admissions->staffCheck();                   // nurse pointer

    if(nurse!=NULL){

        cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" arrives in ED. Assessment nurse is free; (patient assessment begins).\n";
        nurse->setAvailability(false);
        startAssesment(patient,nurse);  // start assesment right away

    }else{

        cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" arrives in ED. Assessment nurses busy; (patient is queued).\n";
        admissionsQueue->enqueue(patient);

    }

    newPatient=nextPatient();     // gets a new patient

    if(newPatient!=NULL){   // if not reached EOF

        newArrival=new Arrival(newPatient,newPatient->getArrivalTime());
        eventsQ->enqueue(newArrival);
        newPatient->arrival=newArrival;     // new patients arrival
    }

}


void Hospital::startAssesment(Patient *patient,Staff* nurse) {
    //------------------------------------------------------
    // startAssesment
    //
    // PURPOSE:    processes start assesment of the patient
    // PARAMETERS:
    //      Patient *p- the patient that needs to be assesed.
    //
    //------------------------------------------------------

    CompleteAssesment *completeAssesment1;  // points temporaryly

    cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" begins assessment of length "<<patient->getAssesmentTime()<<"\n";
    StartAssesment *startAssesment1=new StartAssesment(patient,currTime);
    patient->startAssesment=startAssesment1;
    
    admissions->incrementTimeWaiting(currTime-patient->getArrivalTime());   // increment curr wait time
    admissions->incrementTimeActive(patient->getAssesmentTime());       // increment the active time
    
    nurse->meet();          // simulates meets patient(just a dummy)

    completeAssesment1=new CompleteAssesment(patient,patient->getAssesmentTime()+currTime,nurse);
    patient->completeAssesment=completeAssesment1;

    // schedules a end assesment event
    eventsQ->enqueue(completeAssesment1);

}


void Hospital::completeAssesment(Patient *patient2,Staff* nurse) {
    //------------------------------------------------------
    // completeAssesment
    //
    // PURPOSE:    completes assesment of the patient
    // PARAMETERS:
    //      CompleteAssesment* - this is the event to be processed by this method
    //------------------------------------------------------

    Patient *patient;   // used to temporaryly store a patient

    currTime=patient2->completeAssesment->timePriority; // curr time is complete assesment time


        cout<<"Time\t"<<currTime<<": Patient\t"<<patient2->getPatientNo()<<" completes assessment, assigned priority of "<<patient2->getPatientPriority();
        if (patient2->getBloodTest()) {   // send to blood lab

            newPatientBloodLab(patient2);


        } else if (patient2->getXrayTest()) {  // send to the xRay lab

            newPatientXray(patient2);


        } else {  // send for treatment

            newPatientTreatment(patient2);

        }

        if (!admissionsQueue->isEmpty()) {  // if there are still patients in the admission area

            nurse->setAvailability(false);
            patient = dynamic_cast<Patient *>(admissionsQueue->dequeue());    // remove patient from queue

            if (patient != NULL) {
                startAssesment(patient, nurse);  // start assesment right away
            }

        } else {

            nurse->setAvailability(true);   // set the nurse free.. as she is now free..

        }


}






/*###############BloodLab METHODS#######################*/






void Hospital::newPatientBloodLab(Patient *patient) {
    //------------------------------------------------------
    // newPatientBloodLab
    //
    // PURPOSE:    adds patient to the lab
    // PARAMETERS:
    //    Patient *patient-the patient to be added to the blood lab
    //
    //------------------------------------------------------

    Staff *staff1=bloodLab->staffCheck();
    patient->bloodLabArrivalTime=currTime;

    if(staff1!=NULL){ // if a nurse if free

        cout<<", scheduled for blood work.\n";
        startBloodWork(patient,staff1);         // starts blood work immidiately


    }else{  // add the patient to the queue

        cout<<", Queued for blood work.\n";
        patient->timePriority=currTime;
        bloodQueue->enqueue(patient);

    }
    
    bloodLab->incrementPatient();       // increment patient
}

void Hospital::startBloodWork(Patient *patient,Staff* technician){
    //------------------------------------------------------
    // startBloodWork
    //
    // PURPOSE:    starts blood work and schedules a finish blood work event
    // PARAMETERS:
    //    Patient *patient-the patient to be performing blood work
    //    Staff* nurse- the nurse for the blood work
    //
    //------------------------------------------------------

    technician->setAvailability(false); // technician is busy

    StartBloodWork *startBloodWork1=new StartBloodWork(patient,currTime);   // start blood work    // the result will be pointed to
    patient->startBloodWork=startBloodWork1;

    cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" begins blood Work.\n";

    bloodLab->incrementTimeWaiting(currTime-patient->bloodLabArrivalTime); // increment time waiting
    bloodLab->incrementTimeActive(A2Const::bloodWorkTime);      // bloodwork time

    technician->meet(); // dummy, just simulates the meeting

    CompleteBloodWork *finishTest=new CompleteBloodWork(patient,currTime+A2Const::bloodWorkTime,technician); // completes bloodWork
    eventsQ->enqueue(finishTest);   // add the event to the queue

}


void Hospital::bloodTest(Patient *patient,Staff* technician) {
    //------------------------------------------------------
    // bloodTest
    //
    // PURPOSE:    bloodTest of the patients in the patients queue
    //
    //------------------------------------------------------

    Patient *patientNew;    // points at a patient object temporaryly

    currTime=patient->completeBloodWork->timePriority;   // increment current time

    cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" completes BloodWork";
    if(patient->getXrayTest()){ // if patient still has an xraytest to complete

        newPatientXray(patient);

    }else{

        newPatientTreatment(patient);  // sent for treatment
    }



    if(!bloodQueue->isEmpty()){  // keep calling the patients

        patientNew= dynamic_cast<Patient*>(bloodQueue->dequeue());   // cast it

        if(patientNew!=NULL) {
            startBloodWork(patientNew, technician);
        }

    }else{
        technician->setAvailability(true);
    }

}





/*###############Xray METHODS#######################*/





void Hospital::newPatientXray(Patient *patient) {
    //------------------------------------------------------
    // newPatientXray
    //
    // PURPOSE:    adds patient to the lab
    // PARAMETERS:
    //    Patient *patient-the patient to be added to the Xray lab
    //
    //------------------------------------------------------

    Staff *staff1=xRay->staffCheck();

    patient->xrayArrivalTime=currTime;
    if(staff1!=NULL){ // if a nurse if free

        cout<<", scheduled for XRay.\n";
        startXrayWork(patient,staff1);         // starts blood work immidiately

    }else{  // add the patient to the queue

        cout<<", Queued for XRay.\n";
        patient->timePriority=currTime;
        xrayQueue->enqueue(patient);
    }

    xRay->incrementPatient();       // increment patient

}



void Hospital::startXrayWork(Patient *patient,Staff* technician){
    //------------------------------------------------------
    // startxrayWork
    //
    // PURPOSE:    starts blood work and schedules a finish xray work event
    // PARAMETERS:
    //    Patient *patient-the patient to be performing xray work
    //    Staff* technician- the nurse for the xray work
    //
    //------------------------------------------------------

    StartXray *startXray1=new StartXray(patient,currTime);   // start blood work    // the result will be pointed to
    patient->startXray=startXray1;

    cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" begins XRay.\n";

    technician->setAvailability(false); // technician is busy

    xRay->incrementTimeWaiting(currTime-patient->xrayArrivalTime); // increment time waiting
    xRay->incrementTimeActive(A2Const::XRayTime);      // Xray time

    technician->meet(); // dummy, just simulates the meeting

    CompleteXray *finishTest=new CompleteXray(patient,currTime+A2Const::XRayTime,technician); // completes Xray
    eventsQ->enqueue(finishTest);   // add the event to the queue

}




void Hospital::xrayTest(Patient *patient,Staff* technician) {
    //------------------------------------------------------
    // xrayTest
    //
    // PURPOSE:    xrayTest of the patients in the patients queue
    //      Patient *patient-the patient to be performing xray work
    //      Staff* technician- the nurse for the xray work
    //
    //------------------------------------------------------

    Patient *patientNew;    // points at a patient object temporaryly

    currTime=patient->completeXray->timePriority;   // increment current time
    cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" completes XRay";


    newPatientTreatment(patient);  // sent for treatment

    if(!xrayQueue->isEmpty()){  // keep calling the patients

        patientNew= dynamic_cast<Patient*>(xrayQueue->dequeue());   // cast it

        if(patientNew!=NULL) {
            startXrayWork(patientNew, technician);
        }

    }else{
        technician->setAvailability(true);
    }


}





/*###############Treatment METHODS#######################*/




void Hospital::newPatientTreatment(Patient *patient) {
    //------------------------------------------------------
    // newPatientTreatment
    //
    // PURPOSE:    adds patient to the lab
    // PARAMETERS:
    //    Patient *patient-the patient to be added to the Xray lab
    //
    //-----------------------------------------------------

    Staff *staff1=treatment->staffCheck();  // check if staff is free

    patient->treatmentArrivalTime=currTime;
    if(staff1!=NULL){ // if a nurse if free

        cout<<", scheduled for Treatment.\n";
        startTreatmentWork(patient,staff1);         // starts blood work immidiately

    }else{  // add the patient to the queue

        cout<<", Queued for Treatment.\n";
        patient->timePriority=currTime;
        treatmentQueue->enqueue(patient);
    }

    treatment->incrementPatient();       // increment patient


}


void Hospital::startTreatmentWork(Patient *patient,Staff* technician){
    //------------------------------------------------------
    // startBloodWork
    //
    // PURPOSE:    starts blood work and schedules a finish blood work event
    // PARAMETERS:
    //    Patient *patient-the patient to be performing blood work
    //    Staff* nurse- the nurse for the blood work
    //
    //------------------------------------------------------

    StartTreatment *startTreatment1=new StartTreatment(patient,currTime);   // start blood work    // the result will be pointed to
    patient->startTreatment=startTreatment1;

    cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" begins Treatment of length "<<patient->getTreatmentTime()<<"\n";

    technician->setAvailability(false); // technician is busy

    treatment->incrementTimeWaiting(currTime-patient->treatmentArrivalTime); // increment time waiting
    treatment->incrementTimeActive(patient->getTreatmentTime());      // Treatment time

    technician->meet(); // dummy, just simulates the meeting

    Discharge *finishTest=new Discharge(patient,currTime+patient->getTreatmentTime(),technician); // completes Treatment
    eventsQ->enqueue(finishTest);   // add the event to the queue
}



void Hospital::treatmentTest(Patient *patient,Staff* doctor) {
    //------------------------------------------------------
    // treatment
    //
    // PURPOSE:    Xraytest of the patients in the patients queue
    //
    //------------------------------------------------------

    Patient *patientNew;    // points at a patient object temporaryly

    currTime=patient->discharge->timePriority;   // increment current time

    cout<<"Time\t"<<currTime<<": Patient\t"<<patient->getPatientNo()<<" Discharged at time "<<currTime<<"\n";


    //delete patient;     // patient is deleted

    if(!treatmentQueue->isEmpty()){  // keep calling the patients

        patientNew= dynamic_cast<Patient*>(treatmentQueue->dequeue());   // cast it

        if(patientNew!=NULL) {
            startTreatmentWork(patientNew, doctor);
        }

    }else{
        doctor->setAvailability(true);
    }

}



// getters
Admissions* Hospital::getAdmissions(){ return admissions;}
BloodLab* Hospital::getBloodLab(){ return bloodLab;}
XRay* Hospital::getXray(){ return xRay;}
Treatment* Hospital::getTreatment(){ return treatment;}


