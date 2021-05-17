/*
		*	Author:	Dazhia Blassingame
		*	Date: 11/6/17
		*	Assignment: Program 5- Binary Search Tree
		*	File: BinarySearchTree.h
		*	Description: This file declares the methods of a binary search tree that will be used for a restaurant
*/
class node {
    friend class BinarySearchTree;
    private:
        int dishNumber;
        int counter;
        node * leftchild;
        node * rightchild;
};

class BinarySearchTree {
    public:
        BinarySearchTree();
        bool empty(); // return true if the tree is empty, otherwise return false
        bool Insert(int dishNum);//insert a value dishNum
        node * Insert(node * p, int dishNum);
        bool IsThere (int dishNum);//return true if dishNum is in the tree, otherwise return false
        void Delete(int dishNum); //if value dishNum is in the tree, remove dishNum
        void Display();//Display the data stored from smallest to largest based on dish number
        void Display(node * q); // Recursive method used to Display the data stored from smallest to largest based on dish number
        node * SearchForParent(node *q, int dishNum); //search for the parent of a node
        node * Search(int dishNum); //calls recursive method to search tree for a dish number
        node * Search(node * p, int dishNum); //recusive method used to search the binary search tree for a dish number
        node * Righty(node * p); //find the right most element in the left sub tree
        void Orders(node * p); //display all entrees with more than 1 order
        void Orders(); //recursive method to display all entrees with more than 1 order

    private:
        node * root;//pointer to the root node
};


