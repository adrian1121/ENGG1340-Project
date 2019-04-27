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
           
