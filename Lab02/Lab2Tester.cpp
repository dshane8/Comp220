//
// Created by Toby Dragon on 9/2/16.
//

#include <iostream>
#include "ArrayLib.h"
#include "TestLib.h"


void toStringTest(){
    std::cout << "toStringTest" << std::endl;
    int a1[] = {1, 2, 3, 4};
    printAssertStringEqual("{1, 2, 3, 4}", toString(a1, 4));
    int a2[] = {1};
    printAssertStringEqual("{1}", toString(a2, 1));
    int a3[] = {121, 432, 53, 4, 96, 3684};
    printAssertStringEqual("{121, 432, 53, 4, 96, 3684}", toString(a3, 6));
    printAssertStringEqual("{}", toString(a3, 0));
}

void findTest(){
    std::cout << "findTest..." << std::endl;
    int arrayOne[] = {5, 3, 7, 3, 9};
    int index = find(arrayOne, 5, 3);
    printAssertEquals(1, index);

    int arrayTwo[] = {1, 8, 9, 121, 90, 42};
    index = find(arrayTwo, 20, 6);
    printAssertEquals(-1, index);
}

void findLastTest(){
    std::cout << "findLastTest..." << std::endl;
    int arrayOne[] = {5, 3, 7, 3, 9};
    int index = findLast(arrayOne, 5, 3);
    printAssertEquals(3, index);

    int arrayTwo[] = {1, 8, 9, 121, 90, 42};
    index = findLast(arrayTwo, 20, 6);
    printAssertEquals(-1, index);
}

void genRandArrayTest(int low, int high){
    int countSize = high-low+1;
    int* randCounts = new int [countSize]{};
    int outCount=0;

    int* randArray = genRandArray(countSize*100, low, high);
    for (int i=0; i<countSize*100; i++){
        int num = randArray[i];
        num = num - low;
        if (num >= countSize){
            outCount++;
        }
        else {
            randCounts[num]++;
        }
    }
    delete[] randArray;
    randArray = nullptr;

    bool allPresent = true;
    for (int i=0; i<countSize; i++){
        if (randCounts[i]<=0){
            allPresent = false;
        }
    }
    delete[] randCounts;
    randCounts = nullptr;

    if (allPresent && outCount == 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, allPresent:" << allPresent << ", outCount:" << outCount << std::endl;
    }
}

void genRandArrayTest(){
    std::cout << "genRandArrayTest" << std::endl;
    //print some random arrays to make sure they look right
    int* rands = genRandArray(15, 20, 25);
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = genRandArray(15, -3, 3);
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = nullptr;

    genRandArrayTest(0, 10);
    genRandArrayTest(1, 5);
    genRandArrayTest(50, 60);
    genRandArrayTest(-10, 10);
    genRandArrayTest(-10, -5);
}

//relies on a working find function!!!
void genShuffledArrayTest(int size){
    int* shuffled = genShuffledArray(size);
    int missing=0;
    for (int i=1; i<= size; i++){
        if (find(shuffled, size, i) == -1){
            missing++;
        }
    }

    if (missing <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, missing count:" << missing << std::endl;
    }


    delete[] shuffled;
    shuffled = nullptr;
}

void genShuffledArrayTest(){
    std::cout << "shuffledArrayTest" << std::endl;
    //print some shuffled arrays to make sure they look right
    int* shuffled = genShuffledArray(10);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = genShuffledArray(10);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = nullptr;

    genShuffledArrayTest(12);
    genShuffledArrayTest(5);
    genShuffledArrayTest(1);
    int* array = genShuffledArray(0);
    if (array == nullptr){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, array:" << array << std::endl;
    }
}

void copyArrayTest(){
    std::cout << "copyArrayTest ..." << std::endl;
    int *startArray = genShuffledArray(8);
    std::cout << "first array: " << toString(startArray, 8) << std::endl;
    int *copiedArray = copyArray(startArray, 8);
    std::cout << "copied array: " << toString(copiedArray, 8) << std::endl;
    int missing = 0;
    for (int i = 0; i < 8; i++){
        if (startArray[i] != copiedArray[i]){
            missing++;
        }
    }

    if (missing == 0) {
        std::cout << "pass" << std::endl;
    } else {
        std::cout << "failed." << std::endl;
    }
    delete []startArray;

    delete []copiedArray;

    startArray = genRandArray(8, -100, 100);
    std::cout << "second array: " << toString(startArray, 8) << std::endl;
    copiedArray = copyArray(startArray, 8);
    std::cout << "copied array: " << toString(copiedArray, 8) << std::endl;

    missing = 0;

    for (int i = 0; i < 8; i++){
        if (startArray[i] != copiedArray[i]){
            missing++;
        }
    }

    if (missing == 0) {
        std::cout << "pass" << std::endl;
    } else {
        std::cout << "failed." << std::endl;
    }

}

int main(){
    srand(time(NULL));
    toStringTest();
    std::cout << std::endl;
    findTest();
    std::cout << std::endl;
    findLastTest();
    std::cout << std::endl;
    genRandArrayTest();
    std::cout << std::endl;
    copyArrayTest();
    std::cout << std::endl;
    genShuffledArrayTest();

    

    return 0;
}
