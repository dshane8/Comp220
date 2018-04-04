//
// Created by Dylan Shane on 9/5/17.
//
#include <cstdlib>
#include <iostream>
#include <math.h>

int genRandInt(int min, int max, int& numLinesRun){
    numLinesRun += 3;
    if (min > max){
        int temp = min;
        min = max;
        max = temp;
        numLinesRun += 4;
        return arc4random()%(max - min + 1) + min;
    }
    numLinesRun += 1;
    return arc4random()%(max - min + 1) + min;

}

int* genRandArray(int size, int min, int max, int& numLinesRun){
    int *array = new int[size];
    numLinesRun += 5;
    if (min > max){
        int temp = max;
        max = min;
        min = temp;
        numLinesRun += 4;
    }
    for (int i = 0; i < size; i++){
        array[i] = genRandInt(min, max, numLinesRun);
        numLinesRun += 4;
    }
    return array;
    }

int* genShuffledArray(int size, int& numLinesRun){
    if (size < 1){
        numLinesRun += 1;
        return nullptr;
    }
    int *array = new int[size];
    numLinesRun += 4;
    for (int i = 0; i < size; i++){
        array[i] = i + 1;
        numLinesRun += 4;
    }
    for (int i = 0; i < size; i++){
        int randIdx = genRandInt(0, size - 1, numLinesRun);
        int temp = array[randIdx];
        array[randIdx] = array[i];
        array[i] = temp;
        numLinesRun += 7;
    }
    return array;
    }

std::string toString(const int* arrayPtr, int size){
    std::string newString = "{";
    if (size == 0){
        return newString + "}";
    }
    if (size == 1){
        return newString + std::to_string(arrayPtr[0]) + "}";
    }
    for (int i = 0; i < size; i++){
        if (i + 1 != size) {
            std::string intAdd = std::to_string(arrayPtr[i]);
            newString += intAdd + ", ";
        }
    }
    return newString + std::to_string(arrayPtr[(size-1)])+ "}";
    }

int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    numLinesRun += 4;
    for (int i = 0; i < size; i++){
        numLinesRun += 3;
        if (arrayPtr[i] == numToFind){
            numLinesRun += 1;
            return i;
        }
        numLinesRun += 1;
    }
    return -1;
    }

int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    int index = -1;
    numLinesRun += 5;
    for (int i = 0; i < size; i++){
        if (arrayPtr[i] == numToFind) {
            index = i;
            numLinesRun += 1;
        }
        numLinesRun += 4;
    }
    return index;
    }

int* copyArray(const int* arrayToCopy, const int size, int& numLinesRun){
    int *newArray = new int[size];
    numLinesRun += 4;
    for (int i = 0; i < size; i++){
        newArray[i] = arrayToCopy[i];
        numLinesRun += 4;
    }
    return newArray;
    }

int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun){
    int max = arrayPtr[0];
    int maxIdx = 0;
    numLinesRun += 5;
    for (int i = 1; i < size; i++){
        if (max < arrayPtr[i]){
            max = arrayPtr[i];
            maxIdx = i;
            numLinesRun += 2;
        }
        numLinesRun += 4;
    }
    numLinesRun += 1;
    if (size < 1){
        return -1;
    } else {
        return maxIdx;
    }
}

//Bubble Sort
void sort(int* arrayToSort, int size, int& numLinesRun){
    bool swapped = true;
    numLinesRun += 4;
    //While loop checks to see if there were any swaps made in the array
    while (swapped){
        swapped = false;
        numLinesRun += 2;
        for (int i = 0; i < size-1; i++){
            //swaps two numbers if they are out of order
            if (arrayToSort[i] > arrayToSort[i+1]){
                int temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i+1];
                arrayToSort[i+1] = temp;
                swapped = true;
                numLinesRun += 4;
            }
            numLinesRun += 4;
        }
    }
}

int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun) {
    numLinesRun += 6;
    if (size == 0) {
        return -1;
    }
    if (size == 1) {
        numLinesRun += 1;
        if (arrayPtr[0] == numToFind) {
            return 0;
        } else {
            return -1;
        }
    }
    int mid = ceil(size / 2);
    numLinesRun += 1;
    if (arrayPtr[mid] == numToFind) {
        numLinesRun += 1;
        return mid;
    } else if (size % 2 != 0) {
        //Above else-if & below if statement
        numLinesRun += 2;
        //if array has odd num of items
        if (arrayPtr[mid] < numToFind) {
            int idx = binFind(arrayPtr + mid + 1, mid, numToFind, numLinesRun);
            numLinesRun += 1;
            if (idx == -1) {
                numLinesRun += 1;
                return -1;
            }
            return idx + mid + 1;
        } else {
            int idx = binFind(arrayPtr, mid, numToFind, numLinesRun);
            numLinesRun += 1;
            if (idx == -1) {
                numLinesRun += 1;
                return -1;
            }
            return idx;
        }
    } else {
        numLinesRun += 1;
        //if array has even num of items
        if (arrayPtr[mid] < numToFind){
            int idx = binFind(arrayPtr + mid, mid, numToFind, numLinesRun);
            numLinesRun += 1;
            if (idx == -1){
                numLinesRun += 1;
                return -1;
            }
            return idx + mid;
        } else {
            int idx = binFind(arrayPtr, mid, numToFind, numLinesRun);
            numLinesRun += 1;
            if (idx == -1) {
                numLinesRun += 1;
                return -1;
            }
            return idx;
        }

    }
}


/**
 * returns an array that is a sorted, merged copy of arrays a1 and a2
 * Operates in O(n), linear time
 * @pre both a1 and a2 must be sorted
 * @post numLinesRun is updated to include lines run by this function
 * @return an array of size (size1+size2) that is an in-order (sorted) copy of all values from a1 and a2,
 * or nullptr if (size1+size2) < 1
 */
int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun){
    if ((size1 + size2) < 1){
        return nullptr;
    }
    int counterOne = 0;
    int counterTwo = 0;
    int* newArray = new int[size1 + size2];
    //if (size1 > size2){
    for (int i = 0; i < size1 + size2; i++){
        if (counterOne >= size1){
            newArray[i] = a2[counterTwo];
            counterTwo++;
        } else if (counterTwo >= size2){
            newArray[i] = a1[counterOne];
            counterOne++;
        } else {
            if (a1[counterOne] > a2[counterTwo]){
                newArray[i] = a2[counterTwo];
                counterTwo++;
            } else if (a1[counterOne] <= a2[counterTwo]){
                newArray[i] = a1[counterOne];
                counterOne++;
            }
        }
    }
    return newArray;
}


/**
 * returns a sorted copy of the array using merge sort
 * @post numLinesRun is updated to include lines run by this function
 * @return a copy of the array sorted from min to max values, or nullptr if size < 1
 */
int* mergeSort(const int* arrayToSort, int size, int& numLinesRun){
    numLinesRun += 4;
    if (size < 1){
        return nullptr;
    } else if (size == 1){
        numLinesRun += 1;
        return copyArray(arrayToSort, 1, numLinesRun);
    }
    numLinesRun += 2;
    int mid = ceil(size / 2);
    if ((size % 2) == 0){
        int *firstHalf = mergeSort(arrayToSort, mid, numLinesRun);
        int *secondHalf = mergeSort(arrayToSort+mid, mid, numLinesRun);
        int *result = merge(firstHalf, mid, secondHalf, mid, numLinesRun);
        delete[] firstHalf;
        firstHalf = nullptr;
        delete[] secondHalf;
        secondHalf = nullptr;
        numLinesRun += 7;
        return result;
    } else {
        int *firstHalf = mergeSort(arrayToSort, mid, numLinesRun);
        int *secondHalf = mergeSort(arrayToSort+mid, mid+1, numLinesRun);
        int *result = merge(firstHalf, mid, secondHalf, mid+1, numLinesRun);
        delete[] firstHalf;
        firstHalf = nullptr;
        delete[] secondHalf;
        secondHalf = nullptr;
        numLinesRun += 7;
        return result;
    }

}

