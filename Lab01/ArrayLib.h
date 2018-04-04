//
// Created by Toby Dragon on 8/26/17.
//

#ifndef COMP220LAB_ARRAYLIB_H
#define COMP220LAB_ARRAYLIB_H

/**
 * generates a random integer
 * @pre the function srand() must be called once before this function is used the first time
 * @return an integer between min and max inclusive (including both min and max),
 *         unless min is greater than max, then prints error and returns -1
 */
int genRandInt(int min, int max);

#endif //COMP220LAB_ARRAYLIB_H
