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

