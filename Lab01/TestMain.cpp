#include <iostream>
#include "TestLib.h"
#include "ArrayLib.h"

// shows output to demonstrate whether assertEquals is working properly
void printAssertEqualsTest(){
    std::cout << "printAssertEqualsTest, should be 4 passes:" << std::endl;
    printAssertEquals(1, 1);
    printAssertEquals(0, 0);
    printAssertEquals(-1, -1);
    printAssertEquals(1001, 1001);

    std::cout << "printAssertEqualsTest, should be 6 fails and values:" << std::endl;
    printAssertEquals(1, 2);
    printAssertEquals(2, 1);
    printAssertEquals(0, 1);
    printAssertEquals(0, -1);
    printAssertEquals(-1, 1);
    printAssertEquals(1000, 1001);
}

// shows output to demonstrate whether assertCloseToEqual is working properly
void printAssertCloseToEqualTest(){
    std::cout << "printAssertCloseToEqualTest, should be ..." << std::endl;
    //show situations where the test should pass and others where the test should fail
    //including demonstrating the current problem
    printAssertCloseToEqual(10, 12, 1); // FAIL
    printAssertCloseToEqual(13, 17, 4); // PASS
    printAssertCloseToEqual(12, 6, -7); // NEG
    printAssertCloseToEqual(17, 12, 3); // FAIL
    printAssertCloseToEqual(6, 4, 3);   // PASS
    printAssertCloseToEqual(10, 6, 3);  // FAIL
    printAssertCloseToEqual(10, 6, -3); // NEG
    printAssertCloseToEqual(38, 40, 5); // PASS
}

// shows output to demonstrate whether genRandInt is working properly
void printGenRandIntTest(){
    std::cout << "printGenRandIntTest, should be ..." << std::endl;
    //For several different min and max values, generate a lot of random numbers,
    // and check for the situations noted in lab assignment(border cases, negatives, etc.)
    //Hint: You do not need to use the testing functions (might be easier not to use them)
    std::cout << "testing range -5-5 ..." << std::endl;
    for (int i = 0; i < 20; i++) {
        int testNum = genRandInt(-5,5);
        if (testNum >= -5 && testNum <= 5){
            std::cout << "pass. number generated: " << testNum << std::endl;
        } else {
            std::cout << "FAIL. Unreasonable random number." << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "testing range 0-10 ..." << std::endl;

    for (int i = 0; i < 20; i++) {
        int testNum = genRandInt(0,10);
        if (testNum >= 0 && testNum <= 10){
            std::cout << "pass. number generated: " << testNum << std::endl;
        } else {
            std::cout << "FAIL. Unreasonable random number." << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "testing range 7-12 ..." << std::endl;

    for (int i = 0; i < 10; i++) {
        int testNum = genRandInt(7,12);
        if (testNum >= 7 && testNum <= 12){
            std::cout << "pass. number generated: " << testNum << std::endl;
        } else {
            std::cout << "FAIL. Unreasonable random number." << std::endl;
        }
    }

    genRandInt(100, -1); // Error


}

int main() {

    //When you want random numbers from C++, this must be placed once at the start of the program
    srand(time(NULL));

    std::cout << "BEGIN TESTING" << std::endl;

    printAssertEqualsTest();
    std::cout << std::endl;
    printAssertCloseToEqualTest();
    std::cout << std::endl;
    printGenRandIntTest();
    std::cout << std::endl;
    std::cout << "END TESTING" << std::endl;

    return 0;
}