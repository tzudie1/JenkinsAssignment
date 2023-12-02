#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	
	// Check if the user provided a filename on the command line
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <filename>" << endl;
		return 1;
	}
	
	// Open the XML file
	ifstream file(argv[1]);
	if (!file.is_open()) {
		cout << "Error: Could not open file " << argv[1] << endl;
		return 1;
	}

	// Read the XML file line by line
	string line;
	while (getline(file, line)) {
		// Find the start and end tags
		int start = line.find("<title>");
		int end = line.find("</title>");
		if (start != -1 && end != -1) {
			// Extract the text between the tags
			string text = line.substr(start + 7, end - start - 7);
			// Print the text
			cout << text << endl;
		}
	}

	// Close the XML file
	file.close();
	return 0;
}
