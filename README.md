# STAFF MANAGEMENT SYSTEM GROUP 68
## Problem Statement
  Recently, the deteriorating attendance rate of the companies has been a huge issue. Some employees have been showing up late for work and leaving early before the end of work hours. This is not fair for the other responsible and discipline employees as there is no. standardization within the company. To cope with this issue, the companies should implement a computer program which can take into account the attendance of each employee and the performance rating of each employee measured through varied attributes and stored in the system for reference.
## Prequisites
The program is a C++ 11 standard program. It must run in an appropriate C++ 11 Standard compiler.
## Build
Linux:
```sh
make main
```
Windows:
```sh
make main
```
or
```sh
mingw32-make main
```
## Run the program
Linux:
```sh
./main
```
Windows:
```sh
main.exe
```
## File Input and Output
Employee.txt - Information of each employee

Employee.txt:
```sh
<Employee 1 name>,<Employee 1 ID>,<Employee 1 age>,<Employee 1 role>,<Employee 1 salaray>,<Employee 1 status>,<Employee 1 attributes>,<Employee 1 rating>
<Employee 2 name>,<Employee 2 ID>,<Employee 2 age>,<Employee 2 role>,<Employee 2 salaray>,<Employee 2 status>,<Employee 2 attributes>,<Employee 2 rating>
```
\<Employee ID\>checkintime.txt - Check in time of employee with the ID

\<Employee ID\>checkintime.txt:
```sh
<Day 1 check in time>
<Day 2 check in time>
...
<Day 30 check in time>
<Day 31 check in time>
```
\<Employee ID\>checkouttime.txt - Check out time of employee with the ID

\<Employee ID\>checkouttime.txt:
```sh
<Day 1 check out time>
<Day 2 check out time>
...
<Day 30 check out time>
<Day 31 check out time>
```
## What the project does
This program manages the employee data base for a small company. It encompasses basic features of handling attributes of employees such as employee ID, name, age, role, and salary. Additionally, it helps in managing operations such as adding and deleting new and existing employee information from user input. Also, gives the option of defining further required attributes for the convenience of the company. In order to improve management efficiency the program also includes attendance (Check-in and check-out time) and employee ratings to analyse and gather data for each employee making it easier to make decisions in the company.
## Why the project is useful
 A company has a lot of day to day operations which can efficiently be carried out through the use of the program. The attributes such as age, employee id can be instantly reviewed and at the same time an employee can be added or deleted dynamically using the program. Also, parameters such as check-in and check-out time and attendance can help in maintaining efficiency and reviewing employee performance which overall lead to developing a rating system for all employees. Using these parameters as proof employee promotions and salary increments can also be dealt with.
## How users can get started with the project
The program works with a basic introduction screen containing 3 primary options namely menu, instructions and an exit option. The menu option leads to the major operations the program encompasses such as addition, deletion and edit options. The show/search functions contains the advanced functions such as searching, sorting to analyse, organize and conclude results for developing rating and organising the employees.The Delete function will delete the record of information of the employees and the Fire function will change the status of the employee to "Fired!". The Rating System is based on the Checkin and Checkout Time of the Employee.The whole month of the Checkin & Checkout Time has to be inputed into the program in order to enable the rating systemThe instructions works as a ‘readme’ tool where the user can get to know the functions of any of the commands and the purpose they serve making it user friendly. The last option which is the escape option helps to return to the main menu every time.
## Additonal Features
* Access the information of employees
* Import & Export the information of the employees to local file(.txt)
* Access the CheckinTimeFile & CheckoutTimeFile of specific employees 
* Import & Export CheckinTime and Checkout Time of particular employee to local file(.txt)
## Where users can get help with your project and who maintains and contributes to the project
 Our project mainly focuses on those companies which have a maximum of 1000 employees. This is because this is just a prototype program and we need advance coding to handle larger data. Human Resources will be primary user of this program because their duties are to make sure every employee is committed to their roles. Me (Chan Jun Yi,3035602558) and my partner (Kavin Rajagopal,3035435888) will be the owner of this program as we will maintain, edit and improve the program in the near future.
