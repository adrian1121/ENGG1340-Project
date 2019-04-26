#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Function.h"

bool comparename(const Employee &a, const Employee &b);
bool compareID(const Employee &a, const Employee &b);
bool compareage(const Employee &a, const Employee &b);
bool comparerole(const Employee &a, const Employee &b);
bool comparesalary(const Employee &a, const Employee &b);
bool comparestatus(const Employee &a, const Employee &b);
bool comparerating(const Employee &a, const Employee &b);

bool isNumber(string );
bool isLetters(string );

#endif
