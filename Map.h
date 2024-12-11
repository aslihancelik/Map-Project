#pragma once
#include <map>
#include <iterator>
#include <utility>
#include <iostream>
#include <string>
#include "Schedule.h"

using namespace std;

class Map {
private:
	map<string,Schedule> records;
public:

	//reads and discards the first record which contains column headers
	//reads the data from each row
	//creates Schedule object
	//calls addEntry
	void initSchedule(ifstream& );

	//inserts the object into the map
	void addEntry(const Schedule&);

	void print();

	//finds and prints all the records with a target subject
	void find(string);

	//finds and prints all the records with a target subject and catalog number
	void find(string, int);

	//finds and prints all the records given the instructor's last name
	void find(string);


};