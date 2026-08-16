// Author:Andrew Lee
// Date: 08/12/2026
// Class: CS210
// Program: main.cpp
// Corner Grocer Program - CS210 Project Three
// Description: Main code of program, that uses GroceryTracker to run all data processes

#include "GroceryTracker.h"
#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

// Print menu options for user
void PrintMenu() {
    cout << "\n----------------------------\n";
    cout << " Corner Grocer - Main Menu\n";
    cout << "-----------------------------\n";
    cout << "1. Look up frequency of an item\n";
    cout << "2. Print frequency of all items\n";
    cout << "3. Print histogram of all items\n";
    cout << "4. Exit program\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    GroceryTracker tracker; // Create GroceryTracker
    string inputFileName = "CS210_Project_Three_Input_File.txt"; // Input file name
    int userChoice = 0; // Variable to store user choice for menu

    // Load data from the input file at program start
    tracker.LoadData(inputFileName);

    // Main menu loop - runs until user enters exit key
    while (true) {
        PrintMenu(); // Displays Menu
        cin >> userChoice;  // Read user menu choice

        // Input Validation for menu
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4.\n"; // Print error message, request input again
            continue; // Restart menu loop
        }

        if (userChoice == 1) { // Option 1: Item Lookup
            string itemName;
            cout << "Enter the item name: "; // Request input from user
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, itemName); // Read entire line to allow multi word items


            int frequency = tracker.GetFrequency(itemName);
            cout << "The item \"" << itemName << "\" appears " << frequency << " time(s).\n"; // Print message with item Frequency
        }
        else if (userChoice == 2) { // Option 2: Print all item/frequency pairs
            tracker.PrintAllFrequencies(); // Call class function to print list
        }
        else if (userChoice == 3) { //Option 3: Print histogram
            tracker.PrintHistogram(); // Call class function to print histogram
        }
        else if (userChoice == 4) { //Option 4: Exit program
            cout << "Exiting program. Goodbye!\n";
            break; // Break loop and end program
        }
        else {
            cout << "Please enter a valid option (1-4).\n"; // If any other number is entered, return error message, request input again
        }
    }

    return 0;
}