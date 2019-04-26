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
    //ReadCheckinCheckouttimefromfile();

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
            cout<< "*****************************************************"<<endl;
            cout<< "WELCOME TO THE INSTRUCTIONS MENU" << endl;
            cout<< "*****************************************************"<<endl;
            cout<< "Option 1:The 'menu' contains the options of Menu which leads to more program functions"<<endl;
            cout<< "option 2:The 'quit' option terminates the program" << endl;
            cout << ""<< endl;
            cout<< "*****************************************************"<<endl;
            cout<< "***********************MENU**************************"<<endl;
            cout<< "*****************************************************"<<endl;
            cout << ""<< endl;
            cout<< "The 'MENU' option leads to the staff manager menu which contains 7 options"<<endl;
            cout << "1.Search-Enables us to search for a particular employee" << endl;
            cout << "2.Delete- Used to delete Employee details from database" << endl;
            cout << "3.Edit-To update or change Employee details in the Database" << endl;
            cout << "4.Create - To add new employee details to the database" << endl;
            cout << "5.Fire - Used to change status of employee to fired" << endl;
            cout << "6.Show - Leads us to a new menu called 'Employee menu' " << endl;
            cout << "0.Quit. " << endl;
            cout << ""<< endl;
            cout<< "*****************************************************"<<endl;
            cout<< "******************Employee Menu**********************"<<endl;
            cout<< "*****************************************************"<<endl;
            cout << ""<< endl;
            cout << "1.Employee ID-Displays employee ID" << endl;
            cout << "2.Name -Displays name of the employee" << endl;
            cout << "3.Age - Displays the age of employee" << endl;
            cout << "4.Role - Displays the role of the employee in the company" << endl;
            cout << "5.Salary - Displays the salary of the employee" << endl;
            cout << "6.Status - Displays the status of the employee in the company" << endl;
            cout << "0. Quit. - Returns back to the menu " << endl;
            cout << ""<< endl;
            cout<< "*****************************************************"<<endl;
            cout<< "********************EDIT MENU************************"<<endl;
            cout<< "*****************************************************"<<endl;
            cout << ""<< endl;
            cout << "1.Name - Edits the name of the employee" << endl;
            cout << "2.Employee ID - Edits the employee ID" << endl;
            cout << "3.Age - Edits the age of the employee" << endl;
            cout << "4.Role - Edits the Role of the employee" << endl;
            cout << "5.Salary - Edits the salary of the employee" << endl;
            cout << "6.Status - Edits the status of the employee" << endl;
            cout << "7.Attributes - Edits the attributes of an employee" << endl;
            cout << "0. Quit. - Returns back to orginal menu " << endl;
          
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
void ReadCheckinCheckouttimefromfile(){
  int l=0;
  for (int i=0;i<employees.size();i++){
    string fileName = employees[i].ID + filenameA;
    if (filexist(fileName.c_str())){
      ifstream fin;
      string input,array[31];
      fin.open(fileName.c_str());
      while (getline(fin,input)){
          employees[i].checkin[l]=input;
          l=l+1;
      }
      fin.close();
    }
    string fileName2 = employees[i].ID+filenameB;
    if (filexist(fileName2.c_str())){
      ifstream fin;
      string input,array[31];
      fin.open(fileName2.c_str());
      while (getline(fin,input)){
            employees[i].checkout[l]=input;
            l=l+1;
      }
      fin.close();
    }
  }
}*/
