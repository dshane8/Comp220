//
// Created by Dylan Shane on 10/10/17.
//

#include "ArrayList.h"
#include "ArrayLib.h"

ArrayList::ArrayList(int initialCapacity){
    currCapacity = initialCapacity;
    currItemCount = 0;
    array = new int[currCapacity];;
}

ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;

    array = new int[currCapacity];
    for (int i = 0; i < currItemCount; i++) {
        array[i] = arrayListToCopy.array[i];
    }
}

ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
    if (this != &arrayListToCopy) {
        delete[] array;

        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;

        array = new int[currCapacity];
        for (int i = 0; i < currItemCount; i++) {
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}

ArrayList::~ArrayList() {
    delete[] array;
}



void ArrayList::doubleCapacity(){
    int trashTimer = 0;
    int* temp = ::copyArray(array, currCapacity*2, trashTimer);
    currCapacity += currCapacity;
    delete[] array;
    array = temp;
    temp = nullptr;
}


void ArrayList::insertAtEnd(int itemToAdd){
    if (currItemCount + 1 < currCapacity) {
        array[currItemCount] = itemToAdd;
    } else {
        doubleCapacity();
        array[currItemCount] = itemToAdd;
    }
    currItemCount++;
}


void ArrayList::insertAtFront(int itemToAdd) {
    if (currItemCount + 1 < currCapacity) {
        for (int i = currItemCount; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = itemToAdd;
    } else {
        doubleCapacity();
        for (int i = currItemCount; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = itemToAdd;
    }
    currItemCount++;
}

void ArrayList::insertAt(int itemToAdd, int index){
    if (index < 0 || index > currItemCount){
        throw std::out_of_range("Error");
    }
    if (currItemCount + 1 < currCapacity){
        for (int i = currItemCount; i > index; i--){
            array[i] = array[i - 1];
        }
        array[index] = itemToAdd;
    } else {
        doubleCapacity();
        for (int i = currItemCount; i > index; i--){
            array[i] = array[i - 1];
        }
        array[index] = itemToAdd;
    }

    currItemCount++;
}


int ArrayList::getValueAt(int index){
    if (index < currItemCount && index >= 0){
        return array[index];
    } else {
        throw std::out_of_range("Error");
    }
}


int ArrayList::removeValueAt(int index){
    if (index < currItemCount && index >= 0){
        int temp = array[index];
        for (int i = index; i < currItemCount; i++){
            array[i] = array[i + 1];
        }
        currItemCount--;
        return temp;
    } else {
        throw std::out_of_range("Error");
    }
}


bool ArrayList::isEmpty(){
    if (currItemCount < 1){
        return true;
    } else{
        return false;
    }
}


int ArrayList::itemCount(){
    return currItemCount;
}


void ArrayList::clearList(){
    for (int i = 0; i < currItemCount; i++){
        array[i] = 0;
    }
    currItemCount = 0;
}


std::string ArrayList::toString(){
    return ::toString(array, currItemCount);
}


int ArrayList::findMaxIndex(){
    int trashTimer;
    return ::findMaxIndex(array, currItemCount, trashTimer);
}


int ArrayList::find(int numToFind){
    int trashTimer;
    return ::find(array, currItemCount, numToFind, trashTimer);
}


int ArrayList::findLast(int numToFind){
    int trashTimer;
    return ::findLast(array, currItemCount, numToFind, trashTimer);
}



