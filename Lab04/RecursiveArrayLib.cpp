//
// Created by Dylan Shane on 9/5/17.
//
#include <cstdlib>
#include <iostream>
#include <math.h>

int genRandInt(int min, int max, int* numLinesRun){
    *numLinesRun += 3;
    if (min > max){
        int temp = min;
        min = max;
        max = temp;
        *numLinesRun += 4;
        return arc4random()%(max - min + 1) + min;
    }
    *numLinesRun += 1;
    return arc4random()%(max - min + 1) + min;

}

int* genRandArray(int size, int min, int max, int* numLinesRun){
    int *array = new int[size];
    *numLinesRun += 5;
    if (min > max){
        int temp = max;
        max = min;
        min = temp;
        *numLinesRun += 4;
    }
    for (int i = 0; i < size; i++){
        array[i] = genRandInt(min, max, numLinesRun);
        *numLinesRun += 4;
    }
    return array;
    }

int* genShuffledArray(int size, int* numLinesRun){
    if (size < 1){
        *numLinesRun += 1;
        return nullptr;
    }
    int *array = new int[size];
    *numLinesRun += 4;
    for (int i = 0; i < size; i++){
        array[i] = i + 1;
        *numLinesRun += 4;
    }
    for (int i = 0; i < size; i++){
        int randIdx = genRandInt(0, size - 1, numLinesRun);
        int temp = array[randIdx];
        array[randIdx] = array[i];
        array[i] = temp;
        *numLinesRun += 7;
    }
    return array;
    }

//tail recursion
std::string toString(const int* const arrayPtr, const int size, const int totalSize) {
    //std::string newString = "{";
    if (size == 0) {
        return "}";
    }
    if (size == 1) {
        return std::to_string(arrayPtr[0]) + "}";
    }
    std::string newString = std::to_string(arrayPtr[0]) + ", " + toString(arrayPtr+1, size -1, totalSize);
    return newString;
}

std::string toString(const int* const arrayPtr, const int size) {
    std::string totalString = "{";
    if (size == 0) {
        return totalString + "}";
    }
    if (size == 1) {
        return  totalString + std::to_string(arrayPtr[0]) + "}";
    }
    return totalString + toString(arrayPtr, size, size);
}


//tail recursion
int find(const int* const arrayPtr, const int size, const int numToFind, const int numChecked){
    if (size == 0){
        return -1;
    }
    if (arrayPtr[0] == numToFind){
        return numChecked;
    } else{
        int idx = find(arrayPtr+1, size-1, numToFind, numChecked+1);
        return idx;
    }
}

int find(const int* const arrayPtr, const int size, const int numToFind){
    return find(arrayPtr, size, numToFind, 0);
}


//non-tail recursion
int findLast(const int* const arrayPtr, const int size, const int numToFind, const int numChecked){
    if (size == 0){
        return -1;
    }
    if (arrayPtr[size-1] == numToFind){
        return size - 1 - numChecked;
    } else {
        int idx = findLast(arrayPtr, size-1, numToFind, numChecked);
        return idx;
    }
}

int findLast(const int* const arrayPtr, const int size, const int numToFind){
    return findLast(arrayPtr, size, numToFind, 0);
}

int* copyArray(const int* arrayToCopy, const int size, int* numLinesRun){
    int *newArray = new int[size];
    *numLinesRun += 4;
    for (int i = 0; i < size; i++){
        newArray[i] = arrayToCopy[i];
        *numLinesRun += 4;
    }
    return newArray;
    }

//Tail Recursion
int findMaxIndex(const int* const arrayPtr, const int size, const int highestNum, const int numChecked, const int highIdx){
    if (size == 0){
        return highIdx;
    }
    if (arrayPtr[0] > highestNum){
        int idx = findMaxIndex(arrayPtr+1, size-1, arrayPtr[0], numChecked+1, numChecked);
        return idx;
    } else {
        int idx = findMaxIndex(arrayPtr+1, size-1, highestNum, numChecked+1, highIdx);
        return idx;
    }
}

int findMaxIndex(const int* const arrayPtr, const int size){
    if (size == 0){
        return -1;
    } else{
        return findMaxIndex(arrayPtr, size, arrayPtr[0], 0, 0);
    }
}

void sort(int* arrayToSort, int size, int* numLinesRun){
    bool swapped = true;
    *numLinesRun += 4;
    while (swapped){
        swapped = false;
        *numLinesRun += 2;
        for (int i = 0; i < size-1; i++){
            if (arrayToSort[i] > arrayToSort[i+1]){
                int temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i+1];
                arrayToSort[i+1] = temp;
                swapped = true;
                *numLinesRun += 4;
            }
            *numLinesRun += 4;
        }
    }
}
//non tail recursion
int binFind(const int* const arrayPtr, const int size, const int numToFind) {
    if (size == 0) {
        return -1;
    }
    if (size == 1) {
        if (arrayPtr[0] == numToFind) {
            return 0;
        } else {
            return -1;
        }
    }
    int mid = ceil(size / 2);
    if (arrayPtr[mid] == numToFind) {
        return mid;
    } else if (size % 2 != 0) {
        //if array has odd num of items
        if (arrayPtr[mid] < numToFind) {
            int idx = binFind(arrayPtr + mid + 1, mid, numToFind);
            if (idx == -1) {
                return -1;
            }
            return idx + mid + 1;
        } else {
            int idx = binFind(arrayPtr, mid, numToFind);
            if (idx == -1) {
                return -1;
            }
            return idx;
        }
    } else {
        //if array has even num of items
        if (arrayPtr[mid] < numToFind){
            int idx = binFind(arrayPtr + mid, mid, numToFind);
            if (idx == -1){
                return -1;
            }
            return idx + mid;
        } else {
            int idx = binFind(arrayPtr, mid, numToFind);
            if (idx == -1) {
                return -1;
            }
            return idx;
        }

    }
}

