#include "Map.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

vector<string> Map::splitString(const string& str, char delimiter) {
	vector<string> tokens; string token; 
	bool inQuotes = false; 
	for (char ch : str) {
		if (ch == '"') {
			inQuotes = !inQuotes; // Toggle the inQuotes flag when encountering a quote character 
		}
		else if (ch == delimiter && !inQuotes) {
			tokens.push_back(token);
			token.clear();
		}
		else {
			token += ch;
		}
	} tokens.push_back(token); // Add the last token return
	return tokens;
}



void Map::initSchedule(ifstream& infile) {
	string line; 
	
	// Read and discard header line
	getline(infile, line); 
	 
	while (getline(infile, line)) { 
		vector<string> fields = splitString(line, ','); 

		string subject = fields[0];
		int catalog = stoi(fields[1]);  //turn into integer
		string section = fields[2];
		string component = fields[3];
		string session = fields[4];
		int units = stoi(fields[6]);
		int totalEnrolled = stoi(fields[7]);
		int enrolledCapacity = stoi(fields[8]);
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

	// Assuming all rows have the same number of columns 
	vector<string> headers = {"Subject", "Catalog", "Section", "Component", "Session", "Units", "TotEnrl", "CapEnrl", "Instructor"}; 
	// Print headers with fixed width 
	for (const string& header : headers) { 
		cout << left << setw(12) << header; 
	}
	cout << "\n";
}


//Print all records
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
void Map::findBySubjectCatalog(const string subject, const int catalog){
	printHeader();
	for (auto& pair : records) {
		string keyToFind = subject + "_" + to_string(catalog);
		if (pair.first.find(keyToFind) != string::npos) { 
			pair.second.print(); 
		}
	}



}

//finds and prints all the records given the instructor's last name
void Map::findInstructor(const string lastName){
	printHeader();
	for (auto& pair : records) {
		if (pair.second.getInstructor().find(lastName) != string::npos) {
			pair.second.print();
		}
	}
}
