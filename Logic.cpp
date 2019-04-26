#include <iostream>
#include <string>
#include <algorithm>
#include "Logic.h"

/*
 * Ascending comparator for Employee Name alphabetically
 * Parameter A first Employee Name
 * Parameter B second Employee Name
 * @return true if Employee A name is alphabetically smaller than Employee B name
 * @return false otherwise
 */
bool comparename(const Employee &a, const Employee &b)
{
    return a.name < b.name;
}
/*
 * Ascending comparator for Employee ID numerically
 * Parameter A first Employee ID
 * Parameter B second Employee ID
 * @return true if Employee A ID is numerically smaller than Employee B ID
 * @return false otherwise
 */
bool compareID(const Employee &a, const Employee &b)
{
    return a.ID < b.ID;
}
/*
 * Ascending comparator for Employee age numerically
 * Parameter A first Employee age
 * Parameter B second Employee age
 * @return true if Employee A age is numerically smaller than Employee B age
 * @return false otherwise
 */
bool compareage(const Employee &a, const Employee &b)
{
    return a.age < b.age;
}
/*
 * Ascending comparator for Employee Role alphabetically
 * Parameter A first Employee Role
 * Parameter B second Employee Role
 * @return true if Employee A role is alphabetically smaller than Employee B role
 * @return false otherwise
 */
bool comparerole(const Employee &a, const Employee &b)
{
    return a.role < b.role;
}
/*
 * Ascending comparator for Employee Salary numerically
 * Parameter A first Employee Salary
 * Parameter B second Employee Ssalary
 * @return true if Employee A salary is numerically smaller than Employee B salary
 * @return false otherwise
 */
bool comparesalary(const Employee &a, const Employee &b)
{
    return a.salary < b.salary;
}
/*
 * Ascending comparator for Employee status alphabetically
 * Parameter A first Employee status
 * Parameter B second Employee status
 * @return true if Employee A status is alphabetically smaller than Employee B status
 * @return false otherwise
 */
bool comparestatus(const Employee &a, const Employee &b)
{
    return a.status < b.status;
}
/*
 * Ascending comparator for Employee rating numerically
 * Parameter A first Employee rating
 * Parameter B second Employee rating
 * @return true if Employee A rating is numerically smaller than Employee B rating
 * @return false otherwise
 */
bool comparerating(const Employee &a, const Employee &b)
{
    return a.rating < b.rating;
}
/*
 * Check the input is integer
 *@return true if input is integer
 *@return false otherwise
 */
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
/*
 * Check the input is alphabetical letter
 *@return true if input is alphabetical letter
 *@return false otherwise
 */
bool isLetters(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
	    if (input[i]==' ')
            continue;
		int uppercaseChar = toupper(input[i]); //Convert character to upper case version of character
		if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
		{
			return false;
		}
	}
	//At this point, we have gone through every character and checked it.
	return true; //Return true since every character had to be A-Z
}
