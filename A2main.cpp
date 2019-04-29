/*
 * A2main.cpp
 * COMP 2150 Object Orientation
 * (C) Computer Science, University of Manitoba
 *
 * Main function for Assignment 2
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "A2Const.hpp"
#include "Hospital.h"
#include "Station.h"
#include "Admissions.h"
#include "BloodLab.h"
#include "XRay.h"
#include "Treatment.h"

using namespace std;

int main(int argc, char *argv[]){


    ifstream steam;
    cout << "Simulation begins...\n";

    cout<<"Please enter file name and press enter:";
    string filename;
    cin>>filename;
    Hospital* hosp=new Hospital(filename,A2Const::numAssessmentNurses,A2Const::numBloodTech,A2Const::numXRayTech,A2Const::numDoctors,A2Const::bloodWorkTime,A2Const::XRayTime);
    hosp->run();        // run
    hosp->getAdmissions()->report();        // print the admissions report
    hosp->getBloodLab()->report();      // blood lab report
    hosp->getXray()->report();          // xray report
    hosp->getTreatment()->report();     // treatment report

    cout << "\n...Simulation complete.\n\n";
    cout << "\nEnd of processing.\n";
    return 0;

}// main
