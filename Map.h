#pragma once
#include <map>
#include <iterator>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include "Schedule.h"

using namespace std;

/*
* This class manages and processes schedule records using a map. 
* The Map class provides functionalities to initialize, add, find, and print 
* schedule records. It uses a map to store the records with unique keys. 
*/


class Map {
private:
	map<string,Schedule> records;
public:
	//Splits the string by the delimiter
	vector<string> splitString(const std::string& str, char delimiter);

	//Reads and discards the first record which contains column headers
	//Reads the data from each row
	//Creates Schedule object
	//Calls addEntry
	void initSchedule(ifstream& );

	//Inserts the object into the map
	void addEntry(const Schedule&);

	//Prints the header for the schedule table to the console.
	void printHeader() const;

	//Prints all the schedule records in the map to the console.
	void print() const;

	//Finds and prints all the records with a target subject
	//It searches for records where the subject matches the given string.
	void findBySubject(const string&) const;

	//Finds and prints all the records with a target subject and catalog number
	void findBySubjectCatalog(const string, const int);

	//Finds and prints all the records given the instructor's last name
	void findInstructor(string);


};