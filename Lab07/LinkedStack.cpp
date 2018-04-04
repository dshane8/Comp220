//
// Created by Toby Dragon on 10/24/17.
//

#include "LinkedStack.h"

//Creates an empty stack
LinkedStack::LinkedStack(){
    top = nullptr;
}

LinkedNode* copyRecursive(LinkedNode* nodeToCopy){
    if (nodeToCopy->getNext() == nullptr){
        LinkedNode* newNode = new LinkedNode(nodeToCopy->getItem());
        return newNode;
    } else {
        LinkedNode* newNode = copyRecursive(nodeToCopy->getNext());
        LinkedNode* copiedNode = new LinkedNode(nodeToCopy->getItem());
        copiedNode->setNext(newNode);
        return copiedNode;
    }

}

//copy constructor
LinkedStack::LinkedStack(const LinkedStack& stackToCopy) {
    if (stackToCopy.top == nullptr) {
        top = nullptr;
    } else {
        LinkedNode *current = stackToCopy.top;
        LinkedNode* topNode = copyRecursive(current);
        top = topNode;
    }
}

//destructor
LinkedStack::~LinkedStack(){
    LinkedNode* currentNode = top;
    while (currentNode != nullptr){
        LinkedNode* temp  = currentNode;
        currentNode = currentNode->getNext();
        delete temp;
    }
}

//puts an item onto the top of the stack
void LinkedStack::push (std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    newNode->setNext(top);
    top = newNode;
}

//takes the item off the top of the stack and returns it
//throws out_of_range exception if the stack is empty
std::string LinkedStack::pop(){
    //TODO
    if (isEmpty()){
        throw std::out_of_range("Error. Out of range.");
    }
    LinkedNode* temp = top;
    top = top->getNext();
    std::string returnItem = temp->getItem();
    delete temp;
    return returnItem;
}

//returns true if the stack has no items, false otherwise
bool LinkedStack::isEmpty(){
    return top == nullptr;
}
