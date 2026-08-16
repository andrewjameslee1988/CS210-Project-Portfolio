// Author:Andrew Lee
// Date: 08/12/2026
// Class: CS210
// Program: GroceryTracker.cpp
// Description: Implements functions of the GroceryTracker class

#include "GroceryTracker.h" // Header that declares this Class
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

static string Trim(const string& s) {
    size_t start = 0;
    size_t end = s.size();

    // Moves starting position of line beyond any leading whitespace
    while (start < end && std::isspace(static_cast<unsigned char>(s[start]))) {
        ++start;
    }

    //Move ending position of line beyond any trailing whitespace
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
        --end;
    }
    // Return the substring without whitespace
    return s.substr(start, end - start);
}

// Converts string to lowercase for case-insensitive
static string ToLower(const string& s) {
    string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return result;
}

        // Attempts to open an input file, read data lines, and enters data in the frequency map 
        void GroceryTracker::LoadData(const string& filename) {
        ifstream inFile(filename); //Opens input file to read
        string rawItem; //Store lines in variable temporarily

        // Check if file has opened successfully
        if (!inFile.is_open()) {
            cout << "Error: Could not open input file: " << filename << endl; // Print error message if unable to open file
            return; //Exits if file was not opened successfully
        }

        // Read each line in file until reaching the end of file
        while (getline(inFile, rawItem)) { // Read full line into rawItem
            string item = ToLower(Trim(rawItem));

            // Skip empty lines
            if (!item.empty()) {
                itemFrequency[item]++; // Increment the count for the item
            }
        }

        inFile.close(); // Close input file when done

        // Creates a backup file of data after it is loaded to map
        WriteBackupFile("frequency.dat");
    }

    // Option 1: When called - Return count of item searched for
    int GroceryTracker::GetFrequency(const string& itemName) const {
        string key = ToLower(Trim(itemName));

        if (key.empty()) {
            return 0;
        }

        // Attempt to find key in map
        auto it = itemFrequency.find(key);
        if (it != itemFrequency.end()) {
            return it->second; //if key is found return its frequency
        }
        else {
            return 0; // If key is not found, return 0
        }
    }

    // Option 2: Print all items and their frequency
    void GroceryTracker::PrintAllFrequencies() const {
        cout << "\nItem Frequencies:\n";
        cout << "-----------------\n";

        // Cycle through map in ascending order, print each pair
        for (auto const& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Option 3. Print histogram of item/frequency using asterisks
    void GroceryTracker::PrintHistogram() const {
        cout << "\nItem Frequency Histogram:\n";
        cout << "-------------------------\n";

        for (const auto& pair : itemFrequency) {
            cout << pair.first << " "; // Print item name and a space

            // Print one asterisk per frequency count
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }

            cout << endl; //create a new line after each row in histogram
        }
    }

    // Writes backup file of map contents
    void GroceryTracker::WriteBackupFile(const string & backupFilename) const {
        ofstream outFile(backupFilename); // Opens output file to write

        if (!outFile.is_open()) { // Check if file opened correctly
            cout << "Error: Could not create backup file: " << backupFilename << endl; // Print error message if file not opened Correctly
            return; // Exit if file was not created
        }

        // Write each item and its frequency to output file
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }

        outFile.close(); // Close backup file when done
    }