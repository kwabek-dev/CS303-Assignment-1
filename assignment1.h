#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

#include <utility>
#include <stdexcept>

const int MAX_SIZE = 1000;

// Function prototypes
int findNumber(int arr[], int size, int num);
std::pair<int, int> modifyValue(int arr[], int size, int index, int newValue);
void addNumber(int arr[], int &size, int num);
void removeNumber(int arr[], int &size, int index);

#endif // ASSIGNMENT1_H
