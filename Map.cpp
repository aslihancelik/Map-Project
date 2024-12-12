/*
* This is the implementation file for the map class which is a container class.
* This class manages and processes schedule records using a map.
* The Map class provides functionalities to initialize, add, find, and print
* schedule records. It uses a map to store the records with unique keys.
*/


#include "Map.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Splits the input string by the given delimiter and returns a vector of substrings.
vector<string> Map::splitString(const string& str, char delimiter) {
	vector<string> tokens; 
	string token; 
	bool inQuotes = false; 

	// Loop through each character in the input string
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


// Initializes the schedule from a file by reading and discarding the first record 
// (which contains column headers), and then reading the data from each row to create 
// Schedule objects and add them to the map.
void Map::initSchedule(ifstream& infile) {
	string line; 
	
	// Read and discard header line
	getline(infile, line); 
	 
	while (getline(infile, line)) { 
		vector<string> fields = splitString(line, ','); 

		string subject = fields[0];
		int catalog = stoi(fields[1]);  //convert to integer
		string section = fields[2];
		string component = fields[3];
		string session = fields[4];
		int units = stoi(fields[6]);
		int totalEnrolled = stoi(fields[7]);
		int enrolledCapacity = stoi(fields[8]);
		string instructor = fields[10];

		// Create a Schedule object and add it to the map
		Schedule entry(subject, catalog, section, component, session, units, totalEnrolled, enrolledCapacity, instructor);
		addEntry(entry);
	} 
}


// Inserts a Schedule object into the map using the object's key.
void Map::addEntry(const Schedule& entry){
	records[entry.getKey()] = entry;
}

// Prints the header for the schedule table to the console.
void Map::printHeader() const {

	vector<string> headers = {"Subject", "Catalog", "Section", "Component", "Session", "Units", "TotEnrl", "CapEnrl", "Instructor"}; 
	// Print headers with fixed width 
	for (const string& header : headers) { 
		cout << left << setw(12) << header; 
	}
	cout << "\n";
}


// Prints all the schedule records in the map to the console.
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

// Finds and prints all records with an instructor's last name that matches the given string.
void Map::findInstructor(const string lastName){
	printHeader();
	for (auto& pair : records) {
		if (pair.second.getInstructor().find(lastName) != string::npos) {
			pair.second.print();
		}
	}
}
