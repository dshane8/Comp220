//
// Created by Dylan Shane on 9/5/17.
//
#include <cstdlib>
#include <iostream>

int genRandInt(int min, int max){
    if (min > max){
        std::cout << "Error. Min greater than max." << std::endl;
        return -1;
    }
    return arc4random()%(max - min + 1) + min;

}

int* genRandArray(int size, int min, int max){
    int *array = new int[size];
    if (min > max){
        int temp = max;
        max = min;
        min = temp;
    }
    for (int i = 0; i < size; i++){
        array[i] = genRandInt(min, max);
    }
    return array;
    }

int* genShuffledArray(int size){
    if (size < 1){
        return nullptr;
    }
    int *array = new int[size];
    for (int i = 0; i < size; i++){
        array[i] = i + 1;
    }
    for (int i = 0; i < size; i++){
        int randIdx = genRandInt(0, size - 1);
        int temp = array[randIdx];
        array[randIdx] = array[i];
        array[i] = temp;
    }
    return array;
    }

std::string toString(int* arrayPtr, int size){
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

int find(int* arrayPtr, int size, int numToFind){
    for (int i = 0; i < size; i++){
        if (arrayPtr[i] == numToFind){
            return i;
        }
    }
    return -1;
    }

int findLast(int* arrayPtr, int size, int numToFind){
    int index = -1;
    for (int i = 0; i < size; i++){
        if (arrayPtr[i] == numToFind)
            index = i;
    }
    return index;
    }

int* copyArray(int* arrayToCopy, const int size){
    int *newArray = new int[size];
    for (int i = 0; i < size; i++){
        newArray[i] = arrayToCopy[i];
    }
    return newArray;
    }