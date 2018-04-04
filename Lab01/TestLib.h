//
// Created by Toby Dragon on 8/26/17.
//

#ifndef COMP220LAB_TESTLIB_H
#define COMP220LAB_TESTLIB_H

/**
 * reports whether ints are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertEquals(int expected, int actual);

/**
 * reports whether floats are close enough to equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @param errorMargin - the amount of error you're willing to accept
 * @post prints only "pass" if the values are within the error margin from each other,
 *       else it prints "FAIL" and their respective values
 */
void printAssertCloseToEqual(float expected, float actual, float errorMargin);

#endif //COMP220LAB_TESTLIB_H
