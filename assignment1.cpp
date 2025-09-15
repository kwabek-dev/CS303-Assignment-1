#include "assignment1.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;
int main() {
    int arr[1000];
    int size = 0;

    // ====== Reading from file ======
    ifstream inputFile("A1input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    while (inputFile >> arr[size] && size < 1000) {
        size++;
    }
    inputFile.close();

    cout << "Array loaded with " << size << " elements." << endl;

    int choice;
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Find a number\n";
        cout << "2. Modify a value\n";
        cout << "3. Add a number\n";
        cout << "4. Remove a number\n";
        cout << "5. Display array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Find number
                int numToFind;
                cout << "Enter number to find: ";
                cin >> numToFind;
                int index = findNumber(arr, size, numToFind);
                if (index != -1)
                    cout << numToFind << " found at index " << index << endl;
                else
                    cout << numToFind << " not found in array." << endl;
                break;
            }
            case 2: { // Modify value
                int indexToModify, newValue;
                cout << "Enter index to modify: ";
                cin >> indexToModify;
                cout << "Enter new value: ";
                cin >> newValue;
                try {
                    auto result = modifyValue(arr, size, indexToModify, newValue);
                    cout << "Modified index " << indexToModify 
                         << ": old value = " << result.first 
                         << ", new value = " << result.second << endl;
                } catch (out_of_range &e) {
                    cerr << "Exception: " << e.what() << endl;
                }
                break;
            }
            case 3: { // Add number
                int newNum;
                cout << "Enter number to add: ";
                cin >> newNum;
                try {
                    addNumber(arr, size, newNum);
                    cout << "Added " << newNum << " to array. New size = " << size << endl;
                } catch (overflow_error &e) {
                    cerr << "Exception: " << e.what() << endl;
                }
                break;
            }
            case 4: { // Remove number
                int indexToRemove;
                cout << "Enter index to remove: ";
                cin >> indexToRemove;
                removeNumber(arr, size, indexToRemove);
                cout << "New size = " << size << endl;
                break;
            }
            case 5: { // Display array
                cout << "Current Array: ";
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
