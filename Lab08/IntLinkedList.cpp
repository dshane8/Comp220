//
// Created by Dylan Shane on 10/31/17.
//

#include "IntLinkedList.h"
#include <stdexcept>


IntLinkedList::IntLinkedList(){
    front = nullptr;
    end = nullptr;
    numItems = 0;
}

IntLinkedList::IntLinkedList(const IntLinkedList& listToCopy) {
    if (listToCopy.front == nullptr){
        front = nullptr;
        end = nullptr;
        numItems = 0;
    } else {
        LinkedNode* currentCopyNode = listToCopy.front;
        front = new LinkedNode(currentCopyNode->getItem());
        currentCopyNode = currentCopyNode->getNext();
        LinkedNode* currentNode = front;
        while (currentCopyNode != nullptr){
            LinkedNode* newNode = new LinkedNode(currentCopyNode->getItem());
            currentNode->setNext(newNode);
            currentCopyNode = currentCopyNode->getNext();
            currentNode = currentNode->getNext();
        }
        end = currentNode;
    }
}

IntLinkedList& IntLinkedList::operator=(const IntLinkedList& linkedListToCopy){
    if (this != &linkedListToCopy) {
        numItems = linkedListToCopy.numItems;
        if (numItems == 0){
            front = nullptr;
            end = nullptr;
        } else {
            LinkedNode* currentNode = new LinkedNode(linkedListToCopy.front->getItem());
            LinkedNode* nodeToCopy = linkedListToCopy.front->getNext();
            while (nodeToCopy != nullptr) {
                LinkedNode* copiedNode = new LinkedNode(nodeToCopy->getItem());
                currentNode->setNext(copiedNode);
                nodeToCopy = nodeToCopy->getNext();
                currentNode = currentNode->getNext();
            }
        }
    }
    return *this;
}

IntLinkedList::~IntLinkedList() {
    LinkedNode* current = front;
    while (current != nullptr){
        LinkedNode* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
}



void IntLinkedList::insertAtEnd(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if (front == nullptr){
        front = newNode;
        end = newNode;
    } else {
        end->setNext(newNode);
        end = newNode;
    }
    numItems++;
}

void IntLinkedList::insertAtFront(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if (front == nullptr){
        front = newNode;
        end = newNode;
    } else {
        newNode->setNext(front);
        front = newNode;
    }
    numItems++;
}

void IntLinkedList::insertAt(int itemToAdd, int index) {
    if (index > numItems - 1 || index < 0) {
        throw std::out_of_range("<Your error message here>");
    } else if (index == 0) {
        insertAtFront(itemToAdd);
    } else if (index == numItems - 1) {
        insertAtEnd(itemToAdd);
    } else {
        LinkedNode *newNode = new LinkedNode(itemToAdd);
        int count = 0;
        LinkedNode *current = front;
        while (count != index - 1) {
            current = current->getNext();
        }
        LinkedNode *nextNode = current->getNext();
        current->setNext(newNode);
        newNode->setNext(nextNode);
        numItems++;
    }
}

int IntLinkedList::getValueAt(int index){
    if (index > numItems - 1 || index < 0){
        throw std::out_of_range("<Your error message here>");
    } else {
        int currentIdx = 0;
        LinkedNode *currentNode = front;
        while (currentIdx != index) {
            currentNode = currentNode->getNext();
            currentIdx++;
        }
        return currentNode->getItem();
    }

}

int IntLinkedList::removeValueAt(int index){
    if (index > numItems - 1 || index < 0){
        throw std::out_of_range("<Your error message here>");
    } else if (index == 0){
        LinkedNode* nodeToDelete = front;
        int itemToReturn = nodeToDelete->getItem();
        front = nodeToDelete->getNext();
        delete nodeToDelete;
        numItems--;
        return itemToReturn;
    }  else if (index == numItems - 1){
        LinkedNode* nodeToDelete = end;
        LinkedNode* newEndNode = front;
        int itemToDelete = nodeToDelete->getItem();
        while (newEndNode->getNext() != nodeToDelete){
            newEndNode = newEndNode->getNext();
        }
        end = newEndNode;
        delete nodeToDelete;
        numItems--;
        return itemToDelete;
    }else {
        int currIdx = 0;
        LinkedNode* nodeBeforeDelete = front;
        LinkedNode* nodeToBeDeleted = nodeBeforeDelete->getNext();
        while (currIdx != index){
            nodeToBeDeleted = nodeToBeDeleted->getNext();
            nodeBeforeDelete = nodeBeforeDelete->getNext();
            currIdx++;
        }
        nodeBeforeDelete->setNext(nodeToBeDeleted->getNext());
        int returnItem = nodeToBeDeleted->getItem();
        delete nodeToBeDeleted;
        numItems--;
        return returnItem;
    }
}

bool IntLinkedList::isEmpty(){
    return (numItems == 0);
}

int IntLinkedList::itemCount(){
    return numItems;
}

void IntLinkedList::clearList(){
    LinkedNode* currentNode = front;
    while (currentNode != nullptr){
        LinkedNode* nodeToDelete = currentNode;
        currentNode = currentNode->getNext();
        delete nodeToDelete;
    }
    front = nullptr;
    end = nullptr;
    numItems = 0;
}

std::string IntLinkedList::toString(){
    std::string returnString = "{";
    if (front == nullptr){
        return returnString + "}";
    }
    LinkedNode* currentNode = front;
    int currentIdx = 0;
    while (currentIdx != numItems - 2){
        returnString += std::to_string(currentNode->getItem()) + ", ";
        currentNode = currentNode->getNext();
    }
    return returnString + std::to_string(currentNode->getNext()->getItem()) + "}";


}

int IntLinkedList::findMaxIndex(){
    if (front == nullptr){
        return -1;
    } else {
        int max = front->getItem();
        int maxIdx = 0;
        int counter = 0;
        LinkedNode* currentNode = front;
        while (currentNode != nullptr){
            if (currentNode->getItem() > max){
                max = currentNode->getItem();
                maxIdx = counter;
            }
            counter++;
        }
        return maxIdx;
    }
}

int IntLinkedList::find(int numToFind){
    LinkedNode* currentNode = front;
    int currentIdx = 0;
    while (currentNode != nullptr){
        if (currentNode->getItem() == numToFind){
            return currentIdx;
        }
        currentNode = currentNode->getNext();
        currentIdx++;
    }
    return -1;
}

int IntLinkedList::findLast(int numToFind){
    LinkedNode* currentNode = front;
    int currentIdx = 0;
    int foundIdx = -1;
    while (currentNode != nullptr){
        if (currentNode->getItem() == numToFind){
            foundIdx = currentIdx;
        }
        currentNode = currentNode->getNext();
        currentIdx++;
    }
    return foundIdx;
}