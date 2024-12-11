#include "Map.h"
#include <fstream>
#include <sstream>

//reads and discards the first record which contains column headers
//reads the data from each row
//creates Schedule object
//calls addEntry
void Map::initSchedule(ifstream& infile){

	string line;
	//read and discard header line???????????????????????????????????????
	getline(infile, line);

	//read and discard the first record
	while (getline(infile, line)) {

		stringstream ss(line);
		string subject, catalog, section, component, session, instructor;
		int units, totalEnrolled, enrolledCapacity;

		getline(ss, subject, ',');
		getline(ss, catalog, ',');
		getline(ss, section, ',');
		getline(ss, component, ',');
		getline(ss, session, ',');
		ss >> units;
		ss.ignore(1, ',');
		ss >> totalEnrolled;
		ss.ignore(1, ',');
		ss >> enrolledCapacity;
		ss.ignore(1, ',');
		getline(ss, instructor, ',');

		//create the Schedule object with the parsed values
		Schedule entry(subject, catalog, section, component, session, units, totalEnrolled, enrolledCapacity);
		addEntry(entry);

	}
}

//inserts the object into the map
void Map::addEntry(const Schedule& entry){
	records[entry.getKey()] = entry;
}


void Map::print(){}

//finds and prints all the records with a target subject
void Map::find(string){}

//finds and prints all the records with a target subject and catalog number
void Map::find(string, int){}

//finds and prints all the records given the instructor's last name
void Map::find(string){}
