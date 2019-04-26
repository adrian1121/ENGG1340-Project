#ifndef MENU_CPP
#define MENU_CPP

#include <iostream>
#include "Menu.h"
using namespace std;
/*
 * Print the selection_menu
 * return the choice selected
 */
char selection_menu()
{
	char choice;

	// print selection menu
	cout << "********************************" << endl;
	cout << "* Welcome to Staff Manager *" << endl;
	cout << "********************************" << endl;
	cout << "1.Search" << endl;
	cout << "2.Delete" << endl;
	cout << "3.Edit" << endl;
	cout << "4.Create" << endl;
	cout << "5.Fire" << endl;
	cout << "6.Show" << endl;
	cout << "7.Checktime" << endl;
	cout << "8.Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
/*
 * Print the employee_menu
 * return the choice selected
 */
char employee_menu()
{
	char choice;

	// print selection menu
	cout << "********************************" << endl;
	cout << "* Welcome to Employee Menu *" << endl;
	cout << "********************************" << endl;
	cout << "1.Name" << endl;
	cout << "2.Employee ID" << endl;
	cout << "3.Age" << endl;
	cout << "4.Role" << endl;
	cout << "5.Salary" << endl;
	cout << "6.Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
/*
 * Print the show_menu
 * return the choice selected
 */
char show_menu()
{
	char choice;

	// print selection menu
	cout << "********************************" << endl;
	cout << "* Welcome to SHOW Menu *" << endl;
	cout << "********************************" << endl;
	cout << "1.Name" << endl;
	cout << "2.Employee ID" << endl;
	cout << "3.Age" << endl;
	cout << "4.Role" << endl;
	cout << "5.Salary" << endl;
	cout << "6.Status" << endl;
  cout << "7.Rating" << endl;
	cout << "8. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
/*
 * Print the edit_menu
 * return the choice selected
 */
char edit_menu()
{
	char choice;

	// print selection menu
	cout << "********************************" << endl;
	cout << "* Welcome to EDIT Menu *" << endl;
	cout << "********************************" << endl;
	cout << "1.Name" << endl;
	cout << "2.Employee ID" << endl;
	cout << "3.Age" << endl;
	cout << "4.Role" << endl;
	cout << "5.Salary" << endl;
	cout << "6.Status" << endl;
	cout << "7.Attributes" << endl;
	cout << "8. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
/*
 * Print the main_menu
 * return the choice selected
 */
char main_menu()
{
	char choice;

	// print selection menu
	cout << "********************************" << endl;
	cout << "* Welcome *" << endl;
	cout << "********************************" << endl;
	cout << "1. Menu" << endl;
	cout << "2. Instruction" << endl;
	cout << "3. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}

#endif
