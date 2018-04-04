//
// Created by Toby Dragon on 8/26/17.
//
#include <iostream>
#include "TestLib.h"

void printAssertEquals(int expected, int actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertCloseToEqual(float expected, float actual, float errorMargin ){
    if (errorMargin < 0){
        std::cout << "Negative error margin." << std::endl;
        return;
    }
    float diff = abs(expected - actual);
    if ( diff <= errorMargin){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\t not close to actual: " << actual << std::endl;
    }
}