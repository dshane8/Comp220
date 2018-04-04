//
// Created by Toby Dragon on 10/24/17.
//
#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"

void queueCopyConstructorTest() {
    std::cout << "queueCopyConstructorTest" << std::endl;
    LinkedQueue newQueue;

    for (int i = 0; i < 4; i++) {
        std::string personToAdd = "person " + std::to_string(i + 1);
        newQueue.enqueue(personToAdd);
    }

    std::cout << "test for multiple nodes" << std::endl;

    LinkedQueue copyQueue=LinkedQueue (newQueue);

    int errorCounter = 0;
    while (!newQueue.isEmpty()) {
        if (newQueue.dequeue() != copyQueue.dequeue()) {
            errorCounter++;
        }
    }
    if (errorCounter == 0) {
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed with " << errorCounter << " errors." << std::endl;
    }

    errorCounter = 0;

    std::cout << "test for one node" << std::endl;
    newQueue.enqueue("Person 1");
    LinkedQueue copyQueueOneNode = newQueue;

    if (newQueue.dequeue() != copyQueueOneNode.dequeue()) {
        errorCounter++;
    }

    if (errorCounter == 0) {
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed with " << errorCounter << " errors." << std::endl;
    }

    errorCounter = 0;

    std::cout << "test for nodes with same item value" << std::endl;
    newQueue.enqueue("Person 1");
    for (int i = 0; i < 2; i++) {
        newQueue.enqueue("Same Person");
    }
    newQueue.enqueue("Person 3");
    LinkedQueue copyQueueSameNodes = newQueue;

    while (! newQueue.isEmpty()) {
        if (newQueue.dequeue() != copyQueueSameNodes.dequeue()) {
            errorCounter++;
        }
    }

    if (errorCounter == 0){
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed with " << errorCounter << " errors." << std::endl;
    }
}
void stackCopyConstructorTest(){
    std::cout << "stackCopyConstructorTest" << std::endl;
    LinkedStack newStack;

    for (int i = 0; i < 4; i++) {
        std::string personToAdd = "person " + std::to_string(i + 1);
        newStack.push(personToAdd);
    }

    std::cout << "test for multiple nodes" << std::endl;

    LinkedStack copyStack = LinkedStack (newStack);

    int errorCounter = 0;
    while (!newStack.isEmpty()) {
        if (newStack.pop() != copyStack.pop()) {
            errorCounter++;
        }
    }
    if (errorCounter == 0) {
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed with " << errorCounter << " errors." << std::endl;
    }

    errorCounter = 0;

    std::cout << "test for one node" << std::endl;
    newStack.push("Person 1");
    LinkedStack copyStackOneNode = newStack;

    if (newStack.pop() != copyStackOneNode.pop()) {
        errorCounter++;
    }

    if (errorCounter == 0) {
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed with " << errorCounter << " errors." << std::endl;
    }

    errorCounter = 0;

    std::cout << "test for nodes with same item value" << std::endl;
    newStack.push("Person 1");
    for (int i = 0; i < 2; i++) {
        newStack.push("Same Person");
    }
    newStack.push("Person 3");
    LinkedStack copyStackSameNode = newStack;

    while (! newStack.isEmpty()) {
        if (newStack.pop() != copyStackSameNode.pop()) {
            errorCounter++;
        }
    }

    if (errorCounter == 0){
        std::cout << "passed." << std::endl;
    } else {
        std::cout << "failed with " << errorCounter << " errors." << std::endl;
    }
}

void simpleStackQueueTest(){
    std::cout << "simpleStackQueueTest" << std::endl;
    LinkedQueue testQueue;
    LinkedStack testStack;

    for (int i=0; i<4; i++){
        std::string personToAdd = "person" + std::to_string(i+1);
        testQueue.enqueue(personToAdd);
        testStack.push(personToAdd);
    }
    std::cout << "Queue:" << std::endl;
    int count=1;
    while( ! testQueue.isEmpty()){
        std::cout << count << ":" << testQueue.dequeue()<< std::endl;
        count++;
    }
    std::cout << "\nStack:" << std::endl;
    count=1;
    while( ! testStack.isEmpty()){
        std::cout << count << ":" << testStack.pop()<< std::endl;
        count++;
    }
    try {
        testStack.pop();
        std::cout << "FAIL: should have thrown exception from pop"<< std::endl;
    }
    catch(std::out_of_range& e){
        std::cout << "pass: caught exception: "<< e.what() << std::endl;
    }
    try {
        testQueue.dequeue();
        std::cout << "FAIL: should have thrown exception from dequeue"<< std::endl;
    }
    catch(std::out_of_range& e){
        std::cout << "pass: caught exception: "<< e.what() << std::endl;
    }
    testStack.push("Maria");
    testStack.push("Janice");
    testStack.pop();
    testStack.push("Paul");
    testStack.push("Johan");
    testStack.pop();
    std::cout << testStack.pop()<< std::endl;

    testQueue.enqueue("Maria");
    testQueue.enqueue("Janice");
    testQueue.dequeue();
    testQueue.enqueue("Paul");
    testQueue.enqueue("Johan");
    testQueue.dequeue();
    std::cout << testQueue.dequeue()<< std::endl;
}

int main(){
    simpleStackQueueTest();
    std::cout << "--------------------" << std::endl;
    queueCopyConstructorTest();
    std::cout << "--------------------" << std::endl;
    stackCopyConstructorTest();
    return 0;
}

