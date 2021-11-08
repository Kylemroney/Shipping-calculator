// KyleRoneyWeek3.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Write a Item Shipping Calculator program that does the following:
// Prompt and retrieve the following input from the user(through the console):
// - Item name
// - Is the item fragile(add in $2.00 if the item is fragile)
// - The order total(without shipping)
// - The destination to which the item will be shipped(USA, Canada, Australia)
// Use the following table to determine the calculations to perform:
// - If the item is fragile add $2.00 to the shipping cost.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	// Variables I will be using for this program
	string name;
	double fragile = 0;
	double total{};
	string destination;
	string item;
	// Week 3 program introduction
	cout << ".................................................." << endl;
	cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
	cout << ".................................................." << endl;
    // Asking the user for the item input
	cout << "\nPlease enter the item name (no spaces)...........:";
	cin >> name;
	// Asking the user if the item is fragile and making the fragile If/else statement
	cout << "Is the item fragile? (y=yes/n=no)................:";
	cin >> item;
	if (item == "y" || item == "Y") {
		fragile = fragile + 2;
	}
	else if (item == "n" || item == "N") {
		fragile = 0;
	}
	else {
		cout << "\nInvalid entry, exiting" << endl;
		return 0;
	}
	//Asking the user for the order total
	cout << "Please enter the order total.....................:";
	cin >> total;
	//Asking the user what the destination is. (USA, CAN, or AUS or MARS)
	cout << "Please enter destination. (usa/can/aus/mars)..........:";
	cin >> destination;
	// Using the transform function to store the destination and item outputs to another array
	transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	// Beginning the If/If else statements for USA shipping
	if (destination == "USA") {
		if (total < 50) 
		fragile = fragile + 6;
		else if (total > 50 || total < 100)
		fragile = fragile + 9;
		else if (total > 100.01 || total < 150)
		fragile = fragile + 12.;
		else
			fragile = 0;
	}
	// Beginning the If/If else statements for CAN shipping
	if (destination == "CAN") {
		if (total < 50)
			fragile = fragile + 8;
		else if (total > 50 || total < 100)
			fragile = fragile + 12;
		else if (total > 100.01 || total < 150)
			fragile = fragile + 15;
		else
			fragile = 0;
	}
	// Beginning the If/If else statements for AUS shipping
	if (destination == "AUS") {
		if (total < 50)
			fragile = fragile + 10;
		else if (total > 50 || total < 100)
			fragile = fragile + 14;
		else if (total > 100.01 || total < 150)
			fragile = fragile + 17;
		else
			fragile = 0;
	}
	if (destination == "MARS") {
		if (total < 50)
			fragile = fragile + 50;
		else if (total > 50 || total < 100)
			fragile = fragile + 55;
		else if (total > 100.01 || total < 150)
			fragile = fragile + 60;
		else
			fragile = 0;
	}
	else {
		cout << "\nInvalid entry, exiting" << endl;
		return 0;
	}
	// Making the order.txt file (Got stuck here.)
	// freopen("Order.txt");
	// Ending the program with the users outputs
	cout << "\nYour item is.................................." << name << endl;
	cout << "Your shipping cost is.........................$" << fragile << endl;
	cout << "You are shipping to..........................." << destination << endl;
	cout << "Your total shipping costs are ................$" << total + fragile << endl;
	cout << "\n----------------------------------------------Thank you!" << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
