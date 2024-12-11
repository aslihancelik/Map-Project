#include "Map.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Function to split a string by a given delimiter 
vector<string> splitString(const string& str, char delimiter) {
	vector<string> tokens;
	string token;
	for (char ch : str) {
		if (ch == delimiter) {
			tokens.push_back(token);
			token.clear();
		}
		else {
			token += ch;
		}
	} tokens.push_back(token); // Add the last token return
	return tokens;
}



void Map::initSchedule(std::ifstream& infile) {
	string line; 
	
	// Read and discard header line
	getline(infile, line); 
	 
	while (getline(infile, line)) { 
		vector<string> fields = splitString(line, ','); 

		string subject = fields[0];
		string catalog = fields[1];
		string section = fields[2];
		string component = fields[3];
		string session = fields[4];
		int units = std::stoi(fields[6]);
		int totalEnrolled = std::stoi(fields[7]);
		int enrolledCapacity = std::stoi(fields[8]);
		string instructor = fields[10];
		Schedule entry(subject, catalog, section, component, session, units, totalEnrolled, enrolledCapacity, instructor);
		addEntry(entry);
	} 
}


//inserts the object into the map
void Map::addEntry(const Schedule& entry){
	records[entry.getKey()] = entry;
}


void Map::printHeader() const {
	cout << "Subject\tCatalog\tSection\tComponent\tSession\tUnits\tTotEnrl\tCapEnrl\tInstructor\n";
}


//Print all records????????????????????????????????????????????????????????????????????????????????
void Map::print() const{
	printHeader();
	for (const auto& pair : records) {
		pair.second.print();
	}

}

//finds and prints all the records with a target subject
void Map::findBySubject(const string& subject) const{
	printHeader();
	//implicit iterator traverses the map through range-based loop
	for (const auto& pair : records) {
		if(pair.second.getSubject() == subject){
			pair.second.print();
		}
	}

}

//finds and prints all the records with a target subject and catalog number
void Map::findBySubjectCatalog(const string subject, const string catalog){
	printHeader();
	for (auto& pair : records) {
		if (pair.first == subject + "_" + catalog) {
			pair.second.print();
		}
	}

}

//finds and prints all the records given the instructor's last name
void Map::findInstructor(const string lastName){
	printHeader();
	for (auto& pair : records) {
		if (pair.second.getInstructor().find(lastName) == string::npos) {
			pair.second.print();
		}
	}
}
