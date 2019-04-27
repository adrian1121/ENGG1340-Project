#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Menu.h"
#include "Logic.h"
#include "Function.h"

using namespace std;
/*
 *The element of the vector is in structure form
 */
vector<Employee> employees;
/*
 * Check if the file exists
 * Parameter fileName file name
 * @return true if file exists
 * @return false otherwise
*/
bool filexist(const char* filename){
    ifstream fin;
    fin.open (filename);
    if (fin.fail()){
        return false;
    }
    return true;

}
int j=0,i=0;
string filenameA="checkintime.txt",filenameB="checkouttime.txt";
void ReadCheckinCheckouttimefromfile();
int main()
{

	  bool check = true, checksearch= true;
    CheckEmployeeFile();
    ReadCheckinCheckouttimefromfile();

    while (check){
        char choice = main_menu();
        switch (choice){
            case'1':
                {
                    char number = selection_menu();
                    switch (number){
                        case'1':
                        {
                            Searchprofile();
                            break;
                        }
                        case'2':
                            {
                                	Deleteprofile();
                                break;

                            }
                        case'3':
                            {
                                Editprofile();
                                    break;
                             }
                             case'4':
                                   {
                                   CreateProfile();
                                   break;
                                   }
                        case'5':
                            {
                                Fireprofile();
                                break;
                            }
                        case'6':
                            {
                                Showprofile();
                                break;
                            }
                        case'7':
                            {
                              CheckinCheckout();
                              break;
                            }
                        case'8':
                            {
                                break;
                            }
                        default:
                            {
                                cout<<"invalid input!"<<endl;
                            }
                    }
                break;
                }
			 case'2':
            cout<< "*******************"<<endl;
            cout<< "WELCOME TO THE INSTRUCTIONS MENU" << endl;
            cout<< "*******************"<<endl;
            cout<< "Option 1:The 'menu' contains the options of Menu which leads to more program functions"<<endl;
            cout<< "option 2:The 'quit' option terminates the program" << endl;
            cout << ""<< endl;
            cout<< "*******************"<<endl;
            cout<< "********MENU*********"<<endl;
            cout<< "*******************"<<endl;
            cout << ""<< endl;
            cout<< "The 'MENU' option leads to the staff manager menu which contains 7 options"<<endl;
            cout << "1.Search-Enables us to search for a particular employee in Employee Menu" << endl;
            cout << "2.Delete- Used to delete Employee details from database" << endl;
            cout << "3.Edit-To update or change Employee details in the Database" << endl;
            cout << "4.Create - To add new employee details to the database" << endl;
            cout << "5.Fire - Used to change status of employee to fired" << endl;
            cout << "6.Show - Leads us to a new menu called 'Employee menu' " << endl;
            cout << "7.Checktime - Input Checkin & Checkout time for 31 days for specific employee. (The difference between the time in a month will be calculated and the rating will based on the difference) " << endl;
            cout << "8. Quit- Returns back to the main_menu"<<endl;
            cout<<"Search Function"<<endl;
            cout << ""<< endl;
            cout<< "*******************"<<endl;
            cout<< "*******Employee Menu*******"<<endl;
            cout<< "*******************"<<endl;
            cout << ""<< endl;
            cout << "1.Employee ID-Displays employee ID" << endl;
            cout << "2.Name -Displays name of the employee" << endl;
            cout << "3.Age - Displays the age of employee" << endl;
            cout << "4.Role - Displays the role of the employee in the company" << endl;
            cout << "5.Salary - Displays the salary of the employee" << endl;
            cout << "6. Quit. - Returns back to the menu " << endl;
            cout << ""<< endl;
            cout<<"Edit Function"<<endl;
            cout<<"Enter the ID or Name of the employee so that the information can be edited."<<endl;
            cout<< "*******************"<<endl;
            cout<< "*******EDIT MENU*********"<<endl;
            cout<< "*******************"<<endl;
            cout << ""<< endl;
            cout << "1.Name - Edits the name of the employee" << endl;
            cout << "2.Employee ID - Edits the employee ID" << endl;
            cout << "3.Age - Edits the age of the employee" << endl;
            cout << "4.Role - Edits the Role of the employee" << endl;
            cout << "5.Salary - Edits the salary of the employee" << endl;
            cout << "6.Status - Edits the status of the employee" << endl;
            cout << "7.Attributes - Edits the attributes of an employee" << endl;
            cout << "8. Quit. - Returns back to orginal menu " << endl;
            cout<<""<<endl;
            cout<<"Fire function"<<endl;
            cout<<"Enter the ID or Name of the employee to be fired so that the status is written Fired! "<<endl;
            cout<<""<<endl;
            cout<<"Show function"<<endl;
            cout<<"Show the information of the employees through different categories accordingly"<<endl;
            cout<< "*******************"<<endl;
            cout<< "*******SHOW MENU*********"<<endl;
            cout<< "*******************"<<endl;
            cout << ""<< endl;
            cout << "1.Name - Shows the name of the employee alphabetically" << endl;
            cout << "2.Employee ID - Shows the employee ID numerically" << endl;
            cout << "3.Age - Shows the age of the employee numerically" << endl;
            cout << "4.Role - Shows the Role of the employee alphabetically" << endl;
            cout << "5.Salary - Shows the salary of the employee numerically" << endl;
            cout << "6.Status - Shows the status of the employee alphabetically" << endl;
            cout << "7.Rating - Shows the Rating of an employee numerically (This rating system is based on the checkin and checkout time of the employee) " << endl;
            cout << "8. Quit. - Returns back to orginal menu " << endl;
            cout<<""<<endl;
            cout<<"Checktime function"<<endl;
            cout<<"Input the Checkin & Checkout time of the specific employee in a particular month and store it in a file and the vector!"<<endl;
            cout<<""<<endl;
          
                break;
            case'3':
                check = false;
                break;
            default:{
              cout<<"Invalid input!"<<endl;
            }
        break;
        }
    }
}
/*
 * Check if the Checkin & Checkout File of the employee exist anot
 * If exist, Read all the data from the file and insert into the vector in the program.
 */
void ReadCheckinCheckouttimefromfile(){
  for (int i=0;i<employees.size();i++){
    string fileName = employees[i].ID + filenameA;
    if (filexist(fileName.c_str())){
      int l=0;
      ifstream fin;
      string input,array[31];
      fin.open(fileName.c_str());
      for (int n = 0; n < 31; n ++){
          getline(fin,input);
          if (input == "")
            break;
          employees[i].checkin[l]=input;
          l=l+1;
      }
      fin.close();
    }

    string fileName2 = employees[i].ID+filenameB;
    if (filexist(fileName2.c_str())){
      int l=0;
      ifstream fin;
      string input,array[31];
      fin.open(fileName2.c_str());
      for (int n = 0; n < 31; n ++){
            getline(fin,input);
            if (input == "")
              break;
            employees[i].checkout[l]=input;
            l=l+1;
      }

      fin.close();
    }
  }
}

           
