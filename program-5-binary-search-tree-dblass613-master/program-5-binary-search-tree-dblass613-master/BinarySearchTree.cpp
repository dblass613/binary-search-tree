/*
		*	Author:	Dazhia Blassingame
		*	Date: 11/6/17
		*	Assignment: Program 5 - Binary Search Tree
		*	File: BinarySearchTree.cpp
		*	Description: This file implements the methods of a binary search tree that will be used for a restaurant
*/
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() {// return true if the tree is empty, otherwise return false
    root = NULL;
}

bool BinarySearchTree::empty() {//checks to see if tree is empty
    return (root == NULL);
}

bool BinarySearchTree::Insert(int dishNum){//insert a value dishNum
    node * newptr = new node;
    newptr->dishNumber = dishNum;
    newptr->leftchild = NULL;
    newptr->rightchild = NULL;

    if(empty()){
        newptr->counter = 1;
        root = newptr;
        return true;
    }else if(IsThere(dishNum)) {
        if (Search(dishNum) != NULL) {
            node *q = Search(dishNum);
            q->counter++;
        }
        return false;
    }else{
        node * p = new node;
        newptr->counter = 1;

        p = Insert(root,dishNum);
        if(dishNum < p->dishNumber){
            p->leftchild = newptr;
        }else{
            p->rightchild = newptr;
        }
    }
}
node * BinarySearchTree::Insert(node * p, int dishNum){ //recursive method for inserting a value
    if(p==NULL){
        return NULL;
    }else if(dishNum < p->dishNumber){
        if(p->leftchild == NULL){
            return p;
        }else{
            return Insert(p->leftchild, dishNum);
        }
    }else if(dishNum > p->dishNumber) {
        if (p->rightchild == NULL) {
            return p;
        } else {
            return Insert(p->rightchild, dishNum);
        }
    }
}

bool BinarySearchTree::IsThere(int dishNum) { //return true if dishNum is in the tree, otherwise return false
    node * p = root;
    if(Search(dishNum) != NULL){
        return true;
    }else{
        return false;
    }
}

void BinarySearchTree::Delete(int dishNum){ //if value dishNum is in the tree, remove dishNum
    node * element = Search(dishNum);
    node * parent = SearchForParent(element, dishNum);

    if(element != NULL){
        if(element->leftchild == NULL && element->rightchild ==NULL){
            delete element;
        }
        else if(element->leftchild==NULL ) {
            if(parent->leftchild == element){
                parent->leftchild = element->rightchild;
                delete element;
            }else{
                parent->rightchild = element->rightchild;
                delete element;
            }
        }else if(element->rightchild == NULL){
            if(parent->leftchild == element){
                parent->leftchild = element->leftchild;
                delete element;
            }else{
                parent->rightchild = element->leftchild;
                delete element;
            }
        }else{
            node * righty = Righty(root);
            element->dishNumber =righty->dishNumber;
            node * rightyParent = SearchForParent(root, righty->dishNumber);
            rightyParent->rightchild = righty->leftchild;
            delete righty;
        }
    }
}

void BinarySearchTree::Display() {//Display the data stored from smallest to largest based on dish number
    node * p = root;
    Display(p);
}

void BinarySearchTree::Display(node * p) {
    if(p != NULL)
    {
        Display(p->leftchild);
        switch(p->dishNumber){
            case 1:
                cout << p->dishNumber << ": Fried Chicken " <<p->counter << " orders" << endl;
                break;
            case 2:
                cout << p->dishNumber << ": Pork Chops " <<p->counter << " orders" << endl;
                break;
            case 3:
                cout << p->dishNumber << ": Baked Chicken " <<p->counter << " orders" << endl;
                break;
            case 4:
                cout << p->dishNumber << ": Grilled Salmon " <<p->counter << " orders" << endl;
                break;
            case 5:
                cout << p->dishNumber << ": Roast Beef " <<p->counter << " orders" << endl;
                break;
            case 6:
                cout << p->dishNumber << ": Grilled Steak " <<p->counter << " orders" << endl;
                break;
            case 7:
                cout << p->dishNumber << ": Meat Loaf " <<p->counter << " orders" << endl;
                break;
        }
        Display(p->rightchild);

    }
}

node * BinarySearchTree::Search(int dishNum) { //calls recursive method to search tree for a dish number
    node * p = root;
    return Search(p, dishNum);
}

node* BinarySearchTree::Search(node *p, int dishNum) { //recusive method used to search the binary search tree for a dish number
    if(p==NULL)
        return NULL;
    else if(dishNum == p->dishNumber) return p;
    else if(dishNum < p->dishNumber){
        return Search(p->leftchild, dishNum);
    }else if(dishNum > p->dishNumber){
        return Search(p->rightchild, dishNum);
    }
}

node * BinarySearchTree::SearchForParent(node *q, int dishNum){ //search for the parent of a node
    if(q==NULL)
        return NULL;
    else if(q->dishNumber == dishNum)
        return NULL;
    else if(q->leftchild->dishNumber == dishNum ||q->rightchild->dishNumber == dishNum)
        return q;
    else if(dishNum < q->dishNumber)
        return SearchForParent(q->leftchild, dishNum);
    else if(dishNum > q->dishNumber)
        return SearchForParent(q->rightchild, dishNum);
}
node* BinarySearchTree::Righty(node *p) { //find the right most element in the left sub tree
    node * temp = NULL;
    if(p->leftchild == NULL){
        return temp;
    }else if(p->leftchild->rightchild == NULL){
        Righty(p);
    }else{
        temp = p->leftchild->rightchild;
        Righty(p);
    }
}
void BinarySearchTree::Orders(){  //display all entrees with more than 1 order
    Orders(root);
}
void BinarySearchTree::Orders(node * p){ //recursive method to display all entrees with more than 1 order
    if(p != NULL) {
        Display(p->leftchild);
        if(p->counter >= 2) {
            switch (p->dishNumber){
                case 1:
                    cout << p->dishNumber << ": Fried Chicken" << p->counter << " orders" << endl;
                    break;
                case 2:
                    cout << p->dishNumber << ": Pork Chops" << p->counter << " orders" << endl;
                    break;
                case 3:
                    cout << p->dishNumber << ": Baked Chicken" << p->counter << " orders" << endl;
                    break;
                case 4:
                    cout << p->dishNumber << ": Grilled Salmon" << p->counter << " orders" << endl;
                    break;
                case 5:
                    cout << p->dishNumber << ": Roast Beef" << p->counter << " orders" << endl;
                    break;
                case 6:
                    cout << p->dishNumber << ": Grilled Steak" << p->counter << " orders" << endl;
                    break;
                case 7:
                    cout << p->dishNumber << ": Meat Loaf" << p->counter << " orders" << endl;
                    break;
            }
        }
        Display(p->rightchild);

    }
}