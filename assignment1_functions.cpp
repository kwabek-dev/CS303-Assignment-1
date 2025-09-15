#include "assignment1.h"
#include <stdexcept>
#include <utility>
#include <iostream>

int findNumber(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

std::pair<int, int> modifyValue(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range!");
    int oldValue = arr[index];
    arr[index] = newValue;
    return std::make_pair(oldValue, newValue);
}

void addNumber(int arr[], int &size, int num) {
    if (size >= MAX_SIZE)
        throw std::overflow_error("Array is full, cannot add new number!");
    arr[size] = num;
    size++;
}

void removeNumber(int arr[], int &size, int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Invalid index. Cannot remove." << std::endl;
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}