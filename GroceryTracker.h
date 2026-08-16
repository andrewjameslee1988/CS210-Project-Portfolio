// Author:Andrew Lee
// Date: 08/12/2026
// Class: CS210
// Program: GroceryTracker.h
// Header file for GroceryTracker class
// Description: Defines the GroceryTracker class and (public / private) members

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

// Class declaration of GroceryTracker
class GroceryTracker {
private:
    map<string, int> itemFrequency;
    // Store each item as a string which serves as a key, and frequency of that item as an integer value.

public:
    // Load the data from the input file and creates the map with data gathered
    void LoadData(const string& filename);

    // Returns the frequency of a specific item on the list
    int GetFrequency(const string& itemName) const;

    // Prints all items and the frequency they appear on the list
    void PrintAllFrequencies() const;

    // Prints a text based histogram using asterisks to represent the frequncy an items occurs
    void PrintHistogram() const;

    // This writes a backup file of the current item frequencies
    void WriteBackupFile(const string& backupFilename) const;
};

#endif //GROCERYTRACKER_H