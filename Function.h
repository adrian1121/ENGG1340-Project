#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include "Menu.h"

using namespace std;
/*
 *Structure of Employee which include information of Employee
 */

struct Employee{
    string name;
    string ID;
    string age;
    string role;
    string salary;
    string checkin[31];
    string checkout[31];
    string rating;
    string status;
    string attribute;
    int total_time;
};

void printemployees(Employee employees);
void printheading();
void Showprofile();
void Searchprofile();
void Fireprofile();
void Deleteprofile();
void Searchprofile();
void Editprofile();
void CheckinCheckout();
void CreateProfile();
void CheckEmployeeFile();


#endif
