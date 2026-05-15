#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countLinesNotStartingWithA() {
    ifstream fin("STORY.txt"); // Open the file for reading
    string line;
    int count = 0;

    if (!fin) {
        cout << "Error: Could not open STORY.txt" << endl;
        return;
    }

    // Read the file line by line
    while (getline(fin, line)) {
        // Check if the line is not empty and the first character is not 'A'
        if (!line.empty() && line[0] != 'A') {
            count++;
        }
    }

    cout << "Number of lines not starting with 'A': " << count << endl;

    fin.close(); // Always close the file
}

int main() {
    // Note: Ensure STORY.TXT exists in the same directory before running
    countLinesNotStartingWithA();
    return 0;
}