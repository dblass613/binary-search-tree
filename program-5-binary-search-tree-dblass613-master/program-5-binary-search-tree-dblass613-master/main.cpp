/*
		*	Author:	Dazhia Blassingame
		*	Date: 11/6/17
		*	Assignment: Program 5- Binary Search Tree
		*	File: main.cpp
		*	Description: This file allows the client to choose whether they want to enter a mean, view a list of the entrees and the number of times they have been ordered, or view the entrees ordered more than once.
*/
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
int main() {
    int option;
    int counter = 0;
    BinarySearchTree tree = BinarySearchTree();
    do {
        cout << "Choose an option: \n 1. Enter an entree  \n 2.View a list of all the entrees ordered  \n 3. View entrees ordered more than once \n 4. Exit \n";
        cin >> option;

        switch (option) {
            case 1:
                int entree;
                cout << "Enter an entree \n Dish 1 – Fried Chicken \n Dish 2 – Pork Chops \n Dish 3 – Baked Chicken \n Dish 4 – Grilled Salmon \n Dish 5 – Roast Beef \n Dish 6 – Grilled Steak \n Dish 7 – Meat Loaf" << endl;
                cin >> entree;
                if (entree >= 1 && entree <= 7) {
                    tree.Insert(entree);
                    counter++;
                }
                break;
            case 2:
                tree.Display();
                break;
            case 3:
                tree.Orders();
            case 4:
                exit(0);
        }
    } while (option != 4);
}