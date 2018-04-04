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
    std::cout << "findTest" << std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    int linesRun = 0;
    for (int i=0; i< 10; i++){
        if (i != find(a1, 10, a1[i], &linesRun)){
            failCount++;
        }
    }
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }

    int a2[]={10, 20, 3, 22, 2, 33, 3, 9, 3, 2};
    printAssertEquals(2, find(a2, 10, 3, &linesRun));
    printAssertEquals(-1, find(a2, 10, 500, &linesRun));
    printAssertEquals(-1, find(a2, 0, 10, &linesRun));
}

void findLastTest(){
    std::cout << "findLastTest" << std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    int linesRun = 0;
    for (int i=0; i< 10; i++){
        if (i != findLast(a1, 10, a1[i], &linesRun)){
            failCount++;
        }
    }
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }

    int a2[]={10, 20, 3, 22, 2, 33, 3, 9, 3, 2};
    printAssertEquals(8, findLast(a2, 10, 3, &linesRun));
    printAssertEquals(-1, findLast(a2, 10, 500, &linesRun));
    printAssertEquals(-1, findLast(a2, 0, 10, &linesRun));
}

void genRandArrayTest(int low, int high){
    int countSize = high-low+1;
    int* randCounts = new int [countSize]{};
    int outCount=0;
    int linesRun = 0;

    int* randArray = genRandArray(countSize*100, low, high, &linesRun);
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
    int linesRun = 0;
    //print some random arrays to make sure they look right
    int* rands = genRandArray(15, 20, 25, &linesRun);
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = genRandArray(15, -3, 3, &linesRun);
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
    int linesRun = 0;
    int* shuffled = genShuffledArray(size, &linesRun);
    int missing=0;
    for (int i=1; i<= size; i++){
        if (find(shuffled, size, i, &linesRun) == -1){
            missing++;
        }
    }

    delete[] shuffled;
    shuffled = nullptr;
    if (missing <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, missing count:" << missing << std::endl;
    }

}

void genShuffledArrayTest(){
    int linesRun = 0;
    std::cout << "shuffledArrayTest" << std::endl;
    //print some shuffled arrays to make sure they look right
    int* shuffled = genShuffledArray(10, &linesRun);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = genShuffledArray(10, &linesRun);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = nullptr;

    genShuffledArrayTest(12);
    genShuffledArrayTest(5);
    genShuffledArrayTest(1);
    int* array = genShuffledArray(0, &linesRun);
    if (array == nullptr){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, array:" << array << std::endl;
    }
}

void copyArrayTest(){
    int linesRun = 0;
    std::cout << "copyArrayTest" << std::endl;
    int a1[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a2[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a3[] = {10, 20, 30, 220, 640, 330, 240, 90, 8650, 230};

    int* copy = copyArray(a1, 10, &linesRun);
    printAssertArrayEqual(copy, a1, 10);
    for (int i=0; i< 10; i++){
        copy[i] = copy[i]*10;
    }
    printAssertArrayEqual(copy, a3, 10);
    printAssertArrayEqual(a1, a2, 10);

    delete[] copy;
    copy = nullptr;
}


void findMaxIndexTest(){
    //TODO
    std::cout << "findMaxTest..." << std::endl;
    //Consider cases like max at end, max at start, all negative numbers, array of size 1 and 0, etc...
    int a1[] = {1, 95, 291, 102, 41, 900};
    int a2[] = {};
    int a3[] = {9};
    int a4[] = {-5, -9, -3, -43};
    int a5[] = {40, 29, 18, 21, 5};

    int timerOne, timerTwo, timerThree, timerFour, timerFive = 0;

    printAssertEquals(5, findMaxIndex(a1, 6, &timerOne));
    printAssertEquals(-1, findMaxIndex(a2, 0, &timerTwo));
    printAssertEquals(0, findMaxIndex(a3, 1, &timerThree));
    printAssertEquals(2, findMaxIndex(a4, 4, &timerFour));
    printAssertEquals(0, findMaxIndex(a5, 5, &timerFive));
}

void sortTest(){
    //TODO
    //Should check that it works on array size 1 and 0, already sorted arrays, even size arrays,
    //odd size arrays, arrays with multiple same values, etc.
    int timerOne = 0;
    int* a1 = genShuffledArray(10, &timerOne);
    std::cout << toString(a1, 10) << std::endl;
    sort(a1, 10, &timerOne);
    std::cout << toString(a1, 10) << std::endl;

    bool check = checkSorted(a1, 10);
    if (check){
        std::cout << "pass" << std::endl;
    } else {
        std::cout << "fail" << std::endl;
    }

    delete[] a1;
    int size = genRandInt(10, 20, &timerOne);
    a1 = genShuffledArray(size, &timerOne);
    sort(a1, size, &timerOne);

    check = checkSorted(a1, size);
    if (check){
        std::cout << "pass" << std::endl;
    } else {
        std::cout << "fail" << std::endl;
    }

    delete[] a1;
    size = genRandInt(10, 20, &timerOne);
    a1 = genShuffledArray(size, &timerOne);
    sort(a1, size, &timerOne);

    check = checkSorted(a1, size);
    if (check){
        std::cout << "pass" << std::endl;
    } else {
        std::cout << "fail" << std::endl;
    }

    delete[] a1;
    a1 = nullptr;
    //Note the new functions in TestLib.h that might be useful here:
    //bool checkSorted(int* a, int size);
    //bool checkForSameElements(const int* a1, const int* a2, int size);
}

int main(){
    toStringTest();
    std::cout << std::endl;
    findTest();
    std::cout << std::endl;
    findLastTest();
    std::cout << std::endl;
    genRandArrayTest();
    std::cout << std::endl;
    genShuffledArrayTest();
    std::cout << std::endl;
    copyArrayTest();
    std::cout << std::endl;
    findMaxIndexTest();
    std::cout << std::endl;
    sortTest();
    return 0;
}
