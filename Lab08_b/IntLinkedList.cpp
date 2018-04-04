//
// Created by Dylan Shane on 11/6/17.
//

#include "IntLinkedList.h"
#include "LinkedNode.h"
#include <stdexcept>

//O(1)
IntLinkedList::IntLinkedList(){
    front = nullptr;
    end = nullptr;
    numItems = 0;
}

//O(n)
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
        numItems = listToCopy.numItems;
    }
}

//O(n)
IntLinkedList& IntLinkedList::operator=(const IntLinkedList& linkedListToCopy){
    if (this != &linkedListToCopy) {
        numItems = linkedListToCopy.numItems;
        if (numItems == 0){
            front = nullptr;
            end = nullptr;
        } else {
            this->clearList();
            LinkedNode* currentNode = new LinkedNode(linkedListToCopy.front->getItem());
            front = currentNode;
            LinkedNode* nodeToCopy = linkedListToCopy.front->getNext();
            while (nodeToCopy->getNext() != nullptr) {
                LinkedNode* copiedNode = new LinkedNode(nodeToCopy->getItem());
                currentNode->setNext(copiedNode);
                nodeToCopy = nodeToCopy->getNext();
                currentNode = currentNode->getNext();
            }
            LinkedNode* lastNode = new LinkedNode(nodeToCopy->getItem());
            currentNode->setNext(lastNode);
            end = lastNode;
        }
    }
    return *this;
}

//O(n)
IntLinkedList::~IntLinkedList() {
    LinkedNode* current = front;
    while (current != nullptr){
        LinkedNode* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
}


//O(1)
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

//O(1)
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

//O(n)
void IntLinkedList::insertAt(int itemToAdd, int index) {
    if (index > numItems - 1 || index < 0) {
        throw std::out_of_range("Index out of range.");
    } else if (index == 0) {
        insertAtFront(itemToAdd);
    } else if (index == numItems - 1) {
        LinkedNode* newNode = new LinkedNode(itemToAdd);
        LinkedNode* current = front;
        while (current->getNext() != end){
            current = current->getNext();
        }
        current->setNext(newNode);
        newNode->setNext(end);
    } else {
        LinkedNode *newNode = new LinkedNode(itemToAdd);
        int count = 0;
        LinkedNode *current = front;
        while (count != index - 1) {
            current = current->getNext();
            count++;
        }
        LinkedNode *nextNode = current->getNext();
        current->setNext(newNode);
        newNode->setNext(nextNode);
        numItems++;
    }
}

//O(n)
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

//O(n)
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

//O(1)
bool IntLinkedList::isEmpty(){
    return (numItems == 0);
}

//O(1)
int IntLinkedList::itemCount(){
    return numItems;
}

//O(n)
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

//O(n)
std::string IntLinkedList::toString(){
    std::string returnString = "{";
    if (front == nullptr){
        return returnString + "}";
    }
    LinkedNode* currentNode = front;
    while (currentNode->getNext() != nullptr){
        returnString += std::to_string(currentNode->getItem()) + ", ";
        currentNode = currentNode->getNext();
    }
    return returnString + std::to_string(currentNode->getItem()) + "}";


}

//O(n)
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
            currentNode = currentNode->getNext();
            counter++;
        }
        return maxIdx;
    }
}

//O(n)
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

//O(n)
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


