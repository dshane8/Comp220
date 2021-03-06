//
// Created by Dylan Shane on 11/6/17.
//

#ifndef LAB08_B_INTLINKEDLIST_H
#define LAB08_B_INTLINKEDLIST_H


#include <string>
#include "LinkedNode.h"
#include "IntList.h"

class IntLinkedList : public IntList {
private:
    int numItems;
    LinkedNode* front;
    LinkedNode* end;

public:
    //O(1)
    IntLinkedList();
    //O(n)
    IntLinkedList(const IntLinkedList& listToCopy);
    //O(n)
    IntLinkedList& operator=(const IntLinkedList& arrayListToCopy);
    //O(n)
    ~IntLinkedList();

    /**
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
//O(1)
    void insertAtEnd(int itemToAdd);

    /**
     * appends the new item to the beginning of the list
     * @param itemToAdd the item to add to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
//O(1)
    void insertAtFront(int itemToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param itemToAdd the item to add
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
     */
//O(n)
    void insertAt(int itemToAdd, int index);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
//O(n)
    int getValueAt(int index);

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
//O(n)
    int removeValueAt(int index);

    /**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
//O(1)
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
//O(1)
    int itemCount();

    /**
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
//O(n)
    void clearList();

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
//O(n)
    std::string toString();

    /**
     * finds the largest value in the array
     * @return the first index of the maximum value, or -1 if size < 1
     */
//O(n)
    int findMaxIndex();

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
//O(n)
    int find(int numToFind);

    /**
     * Searches an int array for a certain value
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
//O(n)
    int findLast(int numToFind);

};


#endif //LAB08_B_INTLINKEDLIST_H
