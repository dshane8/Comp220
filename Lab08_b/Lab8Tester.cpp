//
// Created by Dylan Shane on 11/6/17.
//

#include <iostream>
#include "IntLinkedList.h"

void testInsertAtFrontAndEndGetValueAtRemoveAt(){
    IntLinkedList insertAtEndList;
    IntLinkedList insertAtFrontList;

    std::cout << "Testing adds and get: "<< std::endl;
    bool errors = false;
    for (int i=0; i<10; i++){
        insertAtEndList.insertAtEnd(i);
        insertAtFrontList.insertAtFront(i);
        if (insertAtEndList.itemCount() != i+1){
            std::cout << "ERROR: AddToEnd wrong size for:"<< insertAtEndList.toString() << std::endl;
            errors = true;
        }
        if (insertAtFrontList.itemCount() != i+1){
            std::cout << "ERROR: AddToFront wrong size for:"<< insertAtFrontList.toString()<<std::endl;
            errors = true;
        }
    }
    for (int i=0; i<10; i++){
        if (insertAtEndList.getValueAt(i) != i){
            std::cout << "AddToEnd wrong get for:"<< insertAtEndList.toString()<<std::endl;
            errors = true;
        }
        if (insertAtFrontList.getValueAt(10-1-i) != i){
            std::cout << "AddToFront wrong size for :"<< insertAtFrontList.toString()<<std::endl;
            errors = true;
        }
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

    std::cout << "Testing arrayList itemCount when full:" << std::endl;
    if (10 != insertAtEndList.itemCount()) {
        std::cout << "FAIL: itemCount different on AddToEnd" << std::endl;
        errors = true;
    }
    if (10 != insertAtFrontList.itemCount()) {
        std::cout << "FAIL: itemCount different on AddToFront" << std::endl;
        errors = true;
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

    std::cout << "Testing remove from both lists:" << std::endl;
    for (int i=0; i<10; i++){
        int ans1 = insertAtEndList.removeValueAt(0);
        if (ans1 != i  || insertAtEndList.itemCount() != 10-i-1){
            errors = true;
            std::cout << "AddToEnd wrong remove: got "<< ans1 << " instead of " << i << " for array:"<< insertAtEndList.toString()<<std::endl;
        }
        int ans2 = insertAtFrontList.removeValueAt(0);
        if (ans2 != 10-i-1 || insertAtFrontList.itemCount() != 10-i-1){
            errors = true;
            std::cout << "AddToFront wrong remove: got "<< ans2 << " instead of " << i << " for array:"<< insertAtEndList.toString()<<std::endl;
        }
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

    std::cout << ("Testing arrayList sizes when empty:\n");
    if (0 != insertAtEndList.itemCount()) {
        std::cout << ("FAIL: Size different on AddToEnd\n");
        errors = true;
    }
    if (0 != insertAtFrontList.itemCount()) {
        std::cout << ("FAIL: Size different on AddToFront\n");
        errors = true;
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;


}

void insertAtFrontAndEndIsEmptyClearTester() {
    int errorCount = 0;
    IntLinkedList tester;
    std::cout << ("\nTesting adding to the end and front simultaneously:\n");
    //add to the end and to the front
    tester.insertAtFront(20);
    tester.insertAtEnd(30);
    tester.insertAtFront(10);
    tester.insertAtEnd(40);
    for (int i = 10; i < 40; i += 10) {
        if (i != tester.getValueAt((i / 10) - 1)) {
            errorCount++;
            std::cout << "FAIL: list incorrect, should be {10, 20, 30, 40}, is:" << tester.toString() << "\n";
        }
    }
    //std::cout << tester.toString() << std::endl;
    if (tester.itemCount() != 4) {
        errorCount++;
        std::cout << ("FAIL: itemCount() failed\n");
    }
    if (tester.isEmpty()) {
        errorCount++;
        std::cout << ("FAIL: isEmpty() returned true when should be false\n");
    }

    tester.clearList();
    if (0 != tester.itemCount()) {
        errorCount++;
        std::cout << ("FAIL: clearList() failed, item count not zero\n");
    }
    if (!tester.isEmpty()) {
        errorCount++;
        std::cout << ("FAIL: isEmpty() returned false when should be true\n");
    }
    if (errorCount ==0){
        std::cout << "pass"<<std::endl;
    }
    else {
        std::cout << "FAIL: with " << errorCount << "errors" << std::endl;
    }
}

void insertAtTester(){
    std::cout << ("\nTesting insertAt:\n");
    //std::cout << ("Adding to a bunch of indexes\n");
    //fill up a list with 1-5
    bool errors = false;
    IntLinkedList tester;
    for (int j = 0; j < 5; j++) {
        tester.insertAtEnd(j);
    }
    for (int i = tester.itemCount()-1; i > -1; i--) {
        tester.insertAt(333, i);
    }

    //std::cout << tester.toString() <<std::endl;
    //check to see if 333 is at every other index
    for (int i=0; i < tester.itemCount(); i+=2) {
        //std::cout << tester.get(i) <<std::endl;
        if (tester.getValueAt(i) != 333) {
            errors = true;
            std::cout << ("FAIL: missing an add of 333\n");
        }
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

}

void findTester() {
    std::cout << ("\nTesting find\n");
    bool errors = false;
    IntLinkedList tester;
    //fill up tester 0-9
    for (int i=0; i< 10; i++) {
        tester.insertAtEnd(i);
    }

    //std::cout << tester.toString() << std::endl;
    //find 0-9
    for (int i = 0; i < 10; i++) {
        if (i != tester.find(i)) {
            std::cout << "Failed to find " <<  i << std::endl;
            errors = true;
        }
    }
    if (tester.findMaxIndex() != 9){
        std::cout << ("FindMax failed at array end\n");
        errors = true;
    }
    tester.insertAtFront(100);
    if (tester.findMaxIndex() != 0){
        std::cout << ("FindMax failed at array start\n");
        errors = true;
        //std::cout << tester.toString() << tester.findMax() <<std::endl;
    }
    tester.insertAtEnd(2);
    if (tester.findLast(2) != tester.itemCount()-1) {
        std::cout << ("FindLast failed\n");
        errors = true;
    }
    tester.clearList();

    //test negative numbers
    for (int i=-10; i < 0; i++) {
        tester.insertAtEnd(i);
    }
    //std::cout << tester.toString() << std::endl;
    if (tester.findMaxIndex() != 9){
        std::cout << ("FindMax failed at array end with negative numbers\n");
        errors = true;
    }
    tester.insertAtFront(100);
    if (tester.findMaxIndex() != 0){
        std::cout << ("FindMax failed at array start\n");
        errors = true;
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
}

void testCopyConstructor(){
    std::cout << ("\nTesting Copy Constructor\n");
    int numErrors = 0;
    //create object, add some stuff
    IntLinkedList original;
    for (int i=0; i<4; i++){
        original.insertAtEnd(i);
    }
    //copy it
    IntLinkedList copy = IntLinkedList(original);
    //check they're the same
    if (!(original.toString() == copy.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    original.removeValueAt(0);
    original.removeValueAt(0);
    original.insertAtEnd(4);
    original.insertAtEnd(5);
    //check that they're different
    if (!( original.toString() == "{2, 3, 4, 5}")){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (!( copy.toString() == "{0, 1, 2, 3}")){
        std::cout << "FAIL: error in copy after changes, it is now" << copy.toString() <<  std::endl;
        numErrors++;
    }
    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
    }
    //When this function ends, they'll both be deleted, which will check they don't have shared memory
}

void testAssnOperator(){
    std::cout << ("\nTesting Assignment Operator\n");
    int numErrors = 0;
    //create object, add some stuff
    IntLinkedList original;
    for (int i=0; i<4; i++){
        original.insertAtEnd(i);
    }
    //create a new list with its own data
    IntLinkedList listToSet;
    for (int i=10; i<14; i++){
        listToSet.insertAtEnd(i);
    }
    //assign the original to the new
    listToSet = original;

    //check they're the same
    if (!(original.toString() == listToSet.toString())){
        std::cout << "FAIL: error in copy checking toString" << std::endl;
        numErrors++;
    }
    //remove and add stuff to one
    original.removeValueAt(0);
    original.removeValueAt(0);
    original.insertAtEnd(4);
    original.insertAtEnd(5);
    //check that they're different
    if (!( original.toString() == "{2, 3, 4, 5}")){
        std::cout << "FAIL: error in changing original, it is now:" <<original.toString() << std::endl;
        numErrors++;
    }
    if (!( listToSet.toString() == "{0, 1, 2, 3}")){
        std::cout << "FAIL: error in copy after changes, it is now" << listToSet.toString() <<  std::endl;
        numErrors++;
    }

    //check that there is no bad effect if you set an object to itself
    original = original;
    listToSet = listToSet;

    if (numErrors == 0){
        std::cout << "pass"<<std::endl;
    }
    //When this function ends, original and listToSet will both be deleted, which will check they don't have shared memory
}


int main(){
    insertAtFrontAndEndIsEmptyClearTester();
    testAssnOperator();
    testCopyConstructor();
    findTester();
    insertAtTester();
    testInsertAtFrontAndEndGetValueAtRemoveAt();
    return 0;
}

