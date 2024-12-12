// Map Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This is the client program for managing schedule records using the Map class. 
// The program reads schedule data from a file, initializes the schedule, and provides
// a menu for the user to print the schedule, find records by subject or instructor, and more.
//
//
// Programmer:Aslihan Aria Celik

#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Schedule.h"

using namespace std;
int main()
{
    Map mySchedule;

    //open the schedule file
    ifstream infile("STEM-Summer 2022 Schedule of Classes as of 05-02-22.csv");
    if (!infile) {
        cerr << "Unable to open file";
        return 1;
    }

    //initalize the schedule from the file
    mySchedule.initSchedule(infile);
    infile.close();

    int choice;

    do {
        //Display menu options to the user
        cout << "Menu:\n"; 
        cout << "1. Print Schedule\n"; 
        cout << "2. Find by Subject\n"; 
        cout << "3. Find by Subject and Catalog\n"; 
        cout << "4. Find by Instructor\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice;
        string subject, lastName;
        int catalog;

        // Execute the appropriate action based on user choice
        switch (choice) { 
            case 1: 
                mySchedule.print(); 
                break; 
            case 2:  
                cout << "Enter Subject: ";
                cin >> subject; 
                mySchedule.findBySubject(subject); 
                break;
            case 3: 
                cout << "Enter Subject: "; 
                cin >> subject; 
                cout << "Enter Catalog: "; 
                cin >> catalog; 
                mySchedule.findBySubjectCatalog(subject, catalog); 
                break; 
            case 4: 
                cout << "Enter Instructor's Last Name: "; 
                cin >> lastName; 
                mySchedule.findInstructor(lastName); 
                break; 
        }

    } while (choice != 5); //repeat until user chooses to exit

    return 0;
}
