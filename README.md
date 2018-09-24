CSUF CPSC 131, Fall 2017
Project 1

Project 1 Requirements: Grocery cash register

Introduction

To compute a grocery bill, a checkout stand typically has a scanner to identify product codes of items. This code is used to get the price of the item from the store’s price list, along with the item name and whether it is taxable. This information is then used to compute the price of the item and the total of the bill (see figure below). In this project, you will write C++ code to represent the workings of such a

Objective

You are given partial implementations of three classes. PriceList is a class to hold information of all items in the grocery store. There could be up to 1,000,000 items. The information of each item is its price, barcode, item name, and whether it is taxable; these are kept together in Class PriceListItem. The items in PriceList are loaded all together from a text file[1], or inserted one at a time. The complete grocery bill is computed in Class GroceryBill. To do so, it is given (a const pointer to) a previously created PriceList to get the prices, and the tax rate percentage for taxable items when constructed. It is then given barcodes of items and their quantity. The barcodes can be given one at a time, or they can be collected together in a text file.

You are to complete the implementations of these classes, adding public/private member variables and functions as needed. You should not use any of the C++ Standard Library containers (such as std::array, std::vector, std::list) for this project. Your code is tested in the provided main.cpp. Initially, the given code does not even compile. As you complete the code, it will pass the tests in the main.

Source Code Files

You are given “skeleton” code with many blank spaces. Your assignment is to fill in the missing parts so that the code is complete and works properly.

The included C++ code has multiple files:

●        PriceListItem.h and PriceListItem.cpp: This is to be completed, with public/private member variables and functions as needed, so that it can be used in other classes.

●        PriceList.h and PriceList.cpp: This is to be completed, with public/private member variables and functions as needed.

○        This class contains a method to read item information from a text file. This method is already implemented.

●        GroceryBill.h and GroceryBill.cpp: This is to be completed, with public/private member variables and functions as needed.

●        main.cpp: Code that brings everything together into one application. The main function also tests the output of your functions. This is already complete and you should not change this code (it is ok to edit the file for your own testing, but during grading we will use the original main file).

●        A README.md file. You must edit this file to include the name and CSUF email address of each student in your group. Do this even if you are working by yourself. We need this information so that we can enter your grades into Titanium. For example, if your group includes (fictional) students Ada Lovelace and Charles Babbage, your README.md should be in this format

Add default constructors, copy constructor, assignment operator, destructor if needed to the classes.

Hints

●        Start implementing the PriceListItem class, then the PriceList class, and finally the GroceryBill class. As you write each class, test your code - the main function is just a series of tests. Do NOT wait until you complete the project before testing your code.

Simplifying assumptions

●        The maximum number of different items in the grocery store (maximum number of PriceListItems that could be stored in the ItemList class) is 1,000,000.

●        The maximum number of items scanned in any one grocery bill is 1,000.

●        Names of items do not contain spaces.

Group members:
Steven Kha  stevenkha@csu.fullerton.edu
Jarrett Chien JarrettChien@csu.fullerton.edu
