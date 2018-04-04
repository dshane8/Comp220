//
//  BST.cpp
//  TreeProject
//
//  Created by Toby Dragon on 11/13/14.
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//

#include <iostream>
#include "BST.h"

BST::BST(){
    root = nullptr;
}

//return copy of node and everything below
BTNode* copySubTree(BTNode* topTree){
    if (topTree == nullptr){
        return nullptr;
    } if (topTree->getLeft() == nullptr && topTree->getRight() == nullptr){
        BTNode* copiedNode = new BTNode(topTree->getItem());
        return copiedNode;
    } else {
        BTNode* parentNode = new BTNode(topTree->getItem());
        BTNode* childLeft = nullptr;
        BTNode* childRight = nullptr;
        if (topTree->getLeft() != nullptr){
            childLeft = copySubTree(topTree->getLeft());
        } if (topTree->getRight() != nullptr){
            childRight = copySubTree(topTree->getRight());
        }
        parentNode->setLeft(childLeft);
        parentNode->setRight(childRight);
        return parentNode;
    }
}


void deleteSubTree(BTNode* current){
    if (current != nullptr) {
        deleteSubTree(current->getLeft());
        deleteSubTree(current->getRight());
        delete current;
    }
}

//O(n)
BST::BST(const BST& treeToCopy){
    //TODO (consider calling a recursive function)
    root = copySubTree(treeToCopy.root);
}

//O(n)
BST& BST::operator=(const BST& treeToCopy){
    //TODO (consider calling a recursive function)
    if (this != &treeToCopy){
        deleteSubTree(root);
        root = copySubTree(treeToCopy.root);
    }
    return *this;

}

//O(n)
BST::~BST(){
    deleteSubTree(root);
}

void add(BTNode* current,  int newValue){
    if (newValue == current->getItem()){
        throw DuplicateValueException();
    }
    else if (newValue < current->getItem()){
        BTNode* child = current->getLeft();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setLeft(new BTNode(newValue));
        }
    }
    else {
        BTNode* child = current->getRight();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setRight(new BTNode(newValue));
        }
    }
}

//O(log(n))
void BST::add(int newValue){
    if (root == nullptr){
        root = new BTNode(newValue);
    }
    else {
        ::add(root, newValue);
    }
}

bool find(BTNode *current, int itemToFind) {
    if (current == nullptr){
        return false;
    }
    else {
        if (current->getItem() == itemToFind) {
            return true;
        } else if (current->getItem() > itemToFind) {
            return find(current->getLeft(), itemToFind);
        } else {
            return find(current->getRight(), itemToFind);
        }
    }
}

//O(log(n))
bool BST::find(int itemToFind) {
    return ::find(root, itemToFind);
}

void printInOrder(BTNode* current){
    //TODO
    if (current == nullptr){
        return;
    } if (current->getLeft() != nullptr){
        printInOrder(current->getLeft());
    }
    std::cout << std::to_string(current->getItem()) + ", ";
    if (current->getRight() != nullptr){
        printInOrder(current->getRight());
    }
}

//O(n)
void BST::printInOrder(){
    ::printInOrder(root);
    std::cout << "" << std::endl;
}

int itemCount(BTNode* current) {
    //TODO
    if (current == nullptr){
        return 0;
    }
    if (current->getRight() == nullptr && current->getLeft() == nullptr) {
        return 1;
    } else {
        return itemCount(current->getLeft()) + itemCount(current->getRight()) + 1;

    }
}

//O(n)
int BST::itemCount(){
    return ::itemCount(root);
}

int height(BTNode* current) {
    //TODO
    int leftDist = -1;
    int rightDist = -1;
    if (current == nullptr) {
        return -1;
    } else {
        if (current->getRight() != nullptr) {
            rightDist = height(current->getRight());
        }
        if (current->getLeft() != nullptr) {
            leftDist = height(current->getLeft());
        }
        if (leftDist > rightDist) {
            return leftDist + 1;
        } else if (leftDist <= rightDist) {
            return rightDist + 1;
        }
    }
}

//O(log(n))
int BST::height(){
    return ::height(root);
}

int max(BTNode* current){
    if (current == nullptr){
        throw std::out_of_range("Tree is empty.");
    }
    if (current->getRight() == nullptr){
        return current->getItem();
    } else {
        return max(current->getRight());
    }
}

//O(log(n))
int BST::max(){
    //TODO (consider calling a recursive function)
    return ::max(root);
}







