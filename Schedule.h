#pragma once

#include <iostream>
#include <string>

using namespace std;

class Schedule {
private:
	string subject;
	string catalog;
	string section;
	string component;
	string session;
	int units;
	int totalEnrolled;
	int enrollCapacity;
	string instructor;

public:

	//constructor

	Schedule(string = "", string = "", string = "", string = "", string = "", int = 0, int = 0, int = 0, string = "");

	//Getters

	//generate unique key for the Schedule item 
	string getKey() const;

	string getSubject() const {return subject;}

	string getCatalog() const { return catalog;}

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

	void print();



};