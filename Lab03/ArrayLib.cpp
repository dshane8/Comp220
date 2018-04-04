//
// Created by Dylan Shane on 9/5/17.
//
#include <cstdlib>
#include <iostream>

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

std::string toString(const int* arrayPtr, int size){
    std::string newString = "{";
    if (size == 0){
        return newString + "}";
    }
    if (size == 1){
        return newString + std::to_string(1) + "}";
    }
    for (int i = 0; i < size; i++){
        if (i + 1 != size) {
            std::string intAdd = std::to_string(arrayPtr[i]);
            newString += intAdd + ", ";
        }
    }
    return newString + std::to_string(arrayPtr[(size-1)])+ "}";
    }

int find(const int* arrayPtr, int size, int numToFind, int* numLinesRun){
    *numLinesRun += 4;
    for (int i = 0; i < size; i++){
        *numLinesRun += 3;
        if (arrayPtr[i] == numToFind){
            *numLinesRun += 1;
            return i;
        }
        *numLinesRun += 1;
    }
    return -1;
    }

int findLast(const int* arrayPtr, int size, int numToFind, int* numLinesRun){
    int index = -1;
    *numLinesRun += 5;
    for (int i = 0; i < size; i++){
        if (arrayPtr[i] == numToFind) {
            index = i;
            *numLinesRun += 1;
        }
        *numLinesRun += 4;
    }
    return index;
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

int findMaxIndex(const int* arrayPtr, int size, int* numLinesRun){
    int max = arrayPtr[0];
    int maxIdx = 0;
    *numLinesRun += 5;
    for (int i = 1; i < size; i++){
        if (max < arrayPtr[i]){
            max = arrayPtr[i];
            maxIdx = i;
            *numLinesRun += 2;
        }
        *numLinesRun += 4;
    }
    *numLinesRun += 1;
    if (size < 1){
        return -1;
    } else {
        return maxIdx;
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

