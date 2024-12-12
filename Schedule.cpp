/*
* This class encapsulates details about a schedule item such as subject, catalog number, section,
* component, session, units, total enrollment, enrollment capacity, and instructor. It also provides
* methods to generate a unique key for the item, compare schedule items, and print the item details.
*/

#include "Schedule.h"
#include <iomanip>

//constructor

Schedule::Schedule(string subject, int catalog, string section, string component, string session, int units, int totalEnrolled, int enrollCapacity, string instructor) {
	this->subject = subject;
	this->catalog = catalog;
	this->section = section;
	this->component = component;
	this->session = session;
	this->units = units;
	this->totalEnrolled = totalEnrolled;
	this->enrollCapacity = enrollCapacity;
	this->instructor = instructor;
}

// generate unique key for the Schedule item 
// Combines the subject, catalog, and section to generate a unique key.
string Schedule::getKey() const {
	return subject + "_" + to_string(catalog) + "_" + section;
}

//operator overloads

//overloading == operator

bool Schedule::operator ==(const Schedule& other) const {
	return this->getKey() == other.getKey();
}

//Overloading the != operator

bool Schedule::operator !=(const Schedule& other) const {
	return this->getKey() != other.getKey();
}

//Overloading the >= operator

bool Schedule::operator >=(const Schedule& other) const {
	return this->getKey() >= other.getKey();
}

//print function 
// to print a row of data
void Schedule::print() const{

	cout << left << setw(12) << this->subject 
		 << left << setw(12) << this->catalog 
		 << left << setw(12) << this->section 
		 << left << setw(12) << this->component 
		 << left << setw(12) << this->session 
		 << left << setw(12) << this->units 
		 << left << setw(12) << this->totalEnrolled 
		 << left << setw(12) << this->enrollCapacity 
		 << left << setw(12) << this->instructor 
		 << endl;
}