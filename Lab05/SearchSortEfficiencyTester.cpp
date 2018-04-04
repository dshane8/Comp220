//
// Created by Dylan Shane on 10/3/17.
//

#include "SearchSortEfficiencyTester.h"
#include "ArrayLib.h"
#include <math.h>
#include <iostream>


void compareMergeandBubble(){
    std::cout << "Array Size" << "\t"  << "Sort" << "\t" << "Merge" << std::endl;

    for (int i = 1; i < 70; i += 3) {
        int bubbleTimer = 0;
        int mergeTimer = 0;
        int trashTimer = 0;

        int *bubbleTestArray = genShuffledArray(i, trashTimer);
        int *mergeTestArray = genShuffledArray(i, trashTimer);

        int numToSearch = i + 5;

        sort(bubbleTestArray, i, bubbleTimer);
        mergeSort(mergeTestArray, i, mergeTimer);

        std::cout << "\t" << i << "\t \t" << bubbleTimer << "\t \t \t" << mergeTimer << std::endl;

        delete[] bubbleTestArray;
        bubbleTestArray = nullptr;

        delete[] mergeTestArray;
        mergeTestArray = nullptr;
    }
}

void compareLinearandBinary(){
    std::cout << "sort & binFind"  << "\t" << "Linear" << std::endl;
    int timerBin = 0;
    int timerSort = 0;
    int timerLinear = 0;
    int garbageTimer = 0;

    int *testArray = genShuffledArray(1000, timerBin);
    int *sortedTestArray = copyArray(testArray, 1000, timerBin);

    sort(sortedTestArray, 1000, timerSort);

    for (int j = 1; j < 2600; j++) {
        int numToFind = genRandInt(0, 1000, garbageTimer);
        binFind(sortedTestArray, 1000, numToFind, timerBin);
        find(testArray, 1000, numToFind, timerLinear);
        std::cout << timerSort + timerBin << "\t  \t" << timerLinear << std::endl;
        }

    delete[] testArray;
    testArray = nullptr;

    delete[] sortedTestArray;
    sortedTestArray = nullptr;


}


void compareFindSortandBinFind() {
    //TODO
    std::cout << "Array Size" << "\t" << "Find" << "\t" << "Sort" << "\t" << "BinFind" << std::endl;

    for (int i = 1; i < 70; i += 3) {
        int timer1 = 0;
        int timer2 = 0;
        int timer3 = 0;

        int *testArray = genShuffledArray(i, timer1);

        timer1 = 0;
        timer2 = 0;


        int numToSearch = i + 5;

        find(testArray, i, numToSearch, timer1);
        sort(testArray, i, timer2);
        binFind(testArray, i, numToSearch, timer3);

        std::cout << "\t" << i << "\t \t" << timer1 << "\t \t \t" << timer2 << "\t \t \t" << timer3 << std::endl;

        delete[] testArray;
        testArray = nullptr;
    }
}


int main() {
    compareFindSortandBinFind();
    compareLinearandBinary();
    compareMergeandBubble();
}
