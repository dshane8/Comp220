#include <iostream>
#include "ArrayLib.h"
#include <cstdlib>
#include <cmath>

void compareFindAndFindLast() {
    //TODO
    std::cout << "Array Size" << "\t" << "Find" << "\t" << "FindLast" << std::endl;

    for (int i = 3; i < 50; i += 2) {
        int timer1 = 0;
        int timer2 = 0;

        int *testArray = genShuffledArray(i, &timer1);

        timer1 = 0;
        timer2 = 0;


        int numToSearch = floor(i / 2);

        find(testArray, i, numToSearch, &timer1);
        findLast(testArray, i, numToSearch, &timer2);

        std::cout << "\t" << i << "\t \t" << timer1 << "\t \t \t" << timer2 << std::endl;

        delete[] testArray;
        testArray = nullptr;
    }
}

void compareFindMaxIndexAndSort(){
    //TODO
    std::cout << "Array Size" << "\t" << "FindMax" << "\t \t" << "Sort" << std::endl;

    for (int i=1; i< 50; i+=2) {
        int timer1 = 0;
        int timer2 = 0;

        int* testArray = genRandArray(i, 0, i, &timer1);

        timer1 = 0;
        timer2 = 0;

        findMaxIndex(testArray, i, &timer1);
        sort(testArray, i, &timer2);

        std::cout << "\t" <<  i << "\t \t" << timer1 << "\t \t \t" << timer2 << std::endl;

        delete[] testArray;
        testArray = nullptr;

    }
}


void compareGenRandArrayAndGenShuffledArray(){
    //TODO: the numbers in the for loop might need adjustment to make a nice graph
    std::cout << "Array Size" << "\t" << "RandArray" << "\t" << "ShuffArray" << std::endl;
    for (int i=1; i< 50; i+=2){
        int timer1 = 0;
        int timer2 = 0;

        int* testArray = genRandArray(i, 0, i, &timer1);
        int* testArray2 = genShuffledArray(i, &timer2);
        std::cout << "\t" <<  i << "\t \t" << timer1 << "\t \t \t" << timer2 << std::endl;

        //TODO: ensure there are no memory leaks or dangling pointers.
        delete[] testArray;
        delete[] testArray2;

        testArray = nullptr;
        testArray2 = nullptr;
    }
}
int main() {
    srand(time(NULL));
    compareGenRandArrayAndGenShuffledArray();
    std::cout << std::endl;
    std::cout << std::endl;
    compareFindAndFindLast();
    std::cout << std::endl;
    std::cout << std::endl;
    compareFindMaxIndexAndSort();
}

