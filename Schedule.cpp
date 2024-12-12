
#include "Schedule.h"
#include <iomanip>

//constructor

Schedule::Schedule(string subject, string catalog, string section, string component, string session, int units, int totalEnrolled, int enrollCapacity, string instructor) {
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

//generate unique key for the Schedule item 
string Schedule::getKey() const {
	return subject + "_" + catalog + "_" + section;
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
//?????????????????????????????????????????????????????????????????????????????????????
bool Schedule::operator >=(const Schedule& other) const {
	return this->getKey() >= other.getKey();
}

//print function 

void Schedule::print() const{
	/*cout << setw(12) << this->subject << "\t" << this->catalog << "\t" << this->section << "\t"
         << this->component << "\t" << this->session << "\t" << this->units << "\t" 
         << this->totalEnrolled << "\t" << this->enrollCapacity << "\t" << this->instructor << endl;*/

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