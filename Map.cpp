#include "Map.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Function to split a string by a given delimiter 
std::vector<string> splitString(const string& str, char delimiter) {
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
	std::string line; getline(infile, line); 
	// Read and discard header line 
	// Indices of the columns you want to read 
	vector<int> columnIndices = {0, 1, 2, 3, 4, 6, 7, 8, 10}; 
	while (getline(infile, line)) { 
		vector<string> fields = splitString(line, ','); 
		// Check if there are enough columns in the line 
		if (fields.size() < *std::max_element(columnIndices.begin(), columnIndices.end()) + 1) { 
			cerr << "Error: Not enough columns in line: " << line << endl; 
			continue; 
		} 
		string subject = fields[columnIndices[0]]; 
		string catalog = fields[columnIndices[1]]; 
		string section = fields[columnIndices[2]]; 
		string component = fields[columnIndices[3]]; 
		string session = fields[columnIndices[4]]; 
		int units = std::stoi(fields[columnIndices[5]]); 
		int totEnrl = std::stoi(fields[columnIndices[6]]); 
		int capEnrl = std::stoi(fields[columnIndices[7]]); 
		string instructor = fields[columnIndices[8]]; 
		Schedule item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor); 
		addEntry(item); 
	} 
}







//reads and discards the first record which contains column headers
//reads the data from each row
//creates Schedule object
//calls addEntry
//void Map::initSchedule(ifstream& infile){
//
//	string line;
//	//read and discard header line???????????????????????????????????????
//	getline(infile, line);
//
//	//read and discard the first record
//	while (getline(infile, line)) {
//
//		stringstream ss(line);
//		string subject, catalog, section, component, session, instructor, unitsStr, totalEnrolledStr, enrolledCapacityStr, useless;
//		int units, totalEnrolled, enrolledCapacity;
//
//		getline(ss, subject, ',');
//		getline(ss, catalog, ',');
//		getline(ss, section, ',');
//		getline(ss, component, ',');
//		getline(ss, session, ',');
//		getline(ss, useless, ',');
//		getline(ss, unitsStr, ',');
//		getline(ss, totalEnrolledStr, ',');
//		getline(ss, enrolledCapacityStr, ',');
//		getline(ss, useless, ',');
//		getline(ss, instructor, ',');
//		
//		// Convert the string values to integers 
//		units = std::stoi(unitsStr); 
//		totalEnrolled = std::stoi(totalEnrolledStr);
//		enrolledCapacity = std::stoi(enrolledCapacityStr);
//
//
//		/*ss >> units;
//		ss.ignore(1, ',');
//		ss >> totalEnrolled;
//		ss.ignore(1, ',');
//		ss >> enrolledCapacity;
//		ss.ignore(1, ',');
//		getline(ss, instructor, ',');*/
//
//		//create the Schedule object with the parsed values
//		Schedule entry(subject, catalog, section, component, session, units, totalEnrolled, enrolledCapacity);
//		addEntry(entry);
//
//	}
//}

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
