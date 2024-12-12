#pragma once

#include <iostream>
#include <string>

using namespace std;

/*
* This class encapsulates details about a schedule item such as subject, catalog number, section, 
* component, session, units, total enrollment, enrollment capacity, and instructor. It also provides 
* methods to generate a unique key for the item, compare schedule items, and print the item details. 
*/

class Schedule {
private:
	string subject;
	int catalog;
	string section;
	string component;
	string session;
	int units;
	int totalEnrolled;
	int enrollCapacity;
	string instructor;

public:

	//constructor

	Schedule(string = "", int = 0, string = "", string = "", string = "", int = 0, int = 0, int = 0, string = "");

	//Getters

	//generate unique key for the Schedule item 
	string getKey() const;

	string getSubject() const {return subject;}

	int getCatalog() const { return catalog;}

	string getSection() const { return section; }

	string getComponent() const { return component; }

	string getSession() const { return session; }

	int getUnits() const { return units; }

	int getTotalEnrolled() const { return totalEnrolled; }

	int getEnrollCapacity() const { return enrollCapacity; }

	string getInstructor() const { return instructor; }


	//operator overloads

	//overloading == operator

	bool operator ==(const Schedule&) const;

	//Overloading the != operator

	bool operator !=(const Schedule&) const;

	//Overloading the >= operator

	bool operator >=(const Schedule&) const;

	//print function 

	void print() const;



};