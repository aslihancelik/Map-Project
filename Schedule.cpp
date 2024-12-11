
#include "Schedule.h"

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

}

//Overloading the >= operator

bool Schedule::operator >=(const Schedule& other) const {

}

//print function 

void Schedule::print() {

}