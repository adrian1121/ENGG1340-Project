#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
struct Employee{
    string name;
    string ID;
    int age;
    string role;
    double salary;
    string checkin[31];
    string checkout[31];
    double rating;
    string status;
    string attribute;
};
const int MAX_NUM_EMPLOYEES = 1000;
char selection_menu();
char employee_menu();
char main_menu();
char edit_menu();
void printheading();
void printemployees(Employee );
void editprofile(Employee );
int main()
{
    string Name;
    string id;
    int Age;
    string Role;
    double Salary;
    string Checkin[31];
    string Checkout[31];
    double Rating;
    string Status;
    string special_attribute;

    vector<Employee> employees;
    int i=0,j=0;
    char choice = main_menu();
	bool check = true, checksearch= true;
    while (check){
        switch (choice){
            case'1':
                {
                    char number = selection_menu();
                    switch (number){
                        case'1':
                        {
                            char choice=employee_menu();
                            while (choice!='0'){

                                int i;

                                switch (choice){
// selection 1: gives us a search option to search amongst the entire database of employers and find the correct employee using the ID input taken with in the case block
                                    case'1':
                                        {
                                            string id;
                                            cout<<"ID: ";
                                            cin>>id;
                                            for(i=0;i<employees.size();++i){
                                                    if (employees[i].ID==id){
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        break;
                                                    }
                                            }
                                            break;
                                        }
                                    case'2':
                                        {
                                            string Name;
                                            cout<<"Name: ";
                                            cin>>Name;
                                            for(i=0;i<employees.size();++i){
                                                    if (employees[i].name==Name){
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        break;
                                                    }
                                            }
                                            break;
                                        }
                                    case'3':
                                        {
                                            int Age;
                                            cout<<"Age: ";
                                            cin>>Age;
                                            for(i=0;i<employees.size();++i){
                                                    if (employees[i].age==Age)
                                                        printheading();
                                                        printemployees(employees[i]);
                                            }
                                            break;
                                        }
                                    case'4':
                                        {
                                            string Role;
                                            cout<<"Role: ";
                                            cin>>Role;
                                            for(i=0;i<employees.size();++i){
                                                    if (employees[i].role==Role)
                                                        printheading();
                                                        printemployees(employees[i]);
                                            }
                                            break;
                                        }
                                    case'5':
                                        {
                                            double wages;
                                            int i;
                                            cout<<"1: Higher than: "<<endl;
                                            cout<<"2. Slower than: "<<endl;
                                            cin>>i;
                                            if (i==1){
                                                cout<<"Higher than ";
                                                cin>>wages;
                                                for(i=0;i<employees.size();++i){
                                                    if (employees[i].salary>=wages){
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        cout<<endl;
                                                    }
                                                }
                                            }
                                            else if (i==2){
                                                cout<<"Lower than ";
                                                cin>>wages;
                                                for(i=0;i<employees.size();++i){
                                                    if (employees[i].salary>=wages){
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        cout<<endl;
                                                    }
                                                }
                                            }
                                            else
                                                cout<<"Invalid Input!"<<endl;
                                            break;
                                        }
                                    default:
                                        cout << "Invalid input!" << endl;

                                }
                                choice=employee_menu();
                            }
                        break;
                        }
                        case'2':
                            {
                                string nameorid;
                                cout<<"Please enter name or id: ";
                                cin>>nameorid;
                                for(i=0;i<employees.size();++i){
                                    if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                        cout<<employees[i].name<<" "<<employees[i].ID<<" has been removed!"<<endl;
                                        employees.erase(employees.begin()+i);
                                        j=j-1;
                                        break;
                                    }
                                }
                                break;

                            }
                        case'3':
                            {
                                string nameorid;
                                cout<<"Name or ID to be edited: ";
                                cin>>nameorid;
                                for(i=0;i<employees.size();++i){
                                    if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                        printheading();
                                        printemployees(employees[i]);
                                        editprofile(employees[i]);
                                        break;
                                    }
                                }
                                break;

                             }
                        case'4':
                            cout<<"Name: ";
                            cin>>Name;
                            cout<<endl;
                            cout<<"ID: ";
                            cin>>id;
                            cout<<endl;
                            cout<<"Age: ";
                            cin>>Age;
                            cout<<endl;
                            cout<<"Role: ";
                            cin>>Role;
                            cout<<endl;
                            cout<<"Salary($): ";
                            cin>>Salary;
                            cout<<endl;
                            employees.push_back(Employee());
                            employees[j].name=Name;
                            employees[j].ID=id;
                            employees[j].age=Age;
                            employees[j].role=Role;
                            employees[j].salary=Salary;
                            employees[j].status="Active";
                            j=j+1;
                            break;
                        case'5':
                            {
                                string nameorid;
                                cin>>nameorid;
                                for(i=0;i<employees.size();++i){
                                    if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                        cout<<employees[i].name<<" "<<employees[i].ID<<" has been fired!";
                                        employees[i].status="Fired!";
                                        break;
                                    }
                                }
                                break;
                            }
                        case'6':
                            {
                                cout<<"Total employees: "<<employees.size()<<endl;
                                printheading();
                                for(i=0;i<employees.size();++i){
                                    cout<<i+1<<".";
                                    printemployees(employees[i]);
                                    cout<<endl;
                                }
                                break;
                            }

                    }
                break;
                }
            case'2':
                cout<<"yea"<<endl;
                break;
            case'3':
                check == false;
                break;
        }
    }
}
char selection_menu()
{
	char choice;

	// The welcome menu is printed providing the various options that can be executed.
	cout << "********************************" << endl;
	cout << "* Welcome to Staff Manager *" << endl;
	cout << "********************************" << endl;
	cout << "1.Search" << endl;
	cout << "2.Delete" << endl;
	cout << "3.Edit" << endl;
	cout << "4.Create" << endl;
	cout << "5.Fire" << endl;
	cout << "6.Show" << endl;
	cout << "0.Quit. " << endl;
	cout << "Please enter your choice: ";

	// Bsed on the use input the function return the choice to perform the required tasks accordingly.
	cin >> choice;
	cout << endl;

	return choice;
}

char employee_menu()
{
	char choice;

	// print selection menu
	cout << "********************************" << endl;
	cout << "* Welcome to Employee Menu *" << endl;
	cout << "********************************" << endl;
	cout << "1.Employee ID" << endl;
	cout << "2.Name" << endl;
	cout << "3.Age" << endl;
	cout << "4.Role" << endl;
	cout << "5.Salary" << endl;
	cout << "6.Status" << endl;
	cout << "0. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
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
	cout << "0. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
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
void printemployees(Employee employees){
    cout << left;
    cout<<setw(15)<<employees.name<<setw(15)<<employees.ID<<setw(15)<<employees.age<<setw(15);
    cout<<employees.role<<setw(15)<<employees.salary<<setw(15)<<employees.status<<setw(15)<<employees.attribute<<endl;
}
void printheading(){
    cout << left;
    cout << setw(15) << "Name "<< setw(15) << "ID ";
    cout << setw(15) << "Age "<< setw(15) << "Role ";
    cout << setw(15) << "Salary "<<setw(15)<<"Status "<<setw(15)<<"Attributes"<<endl;
}
void editprofile(Employee employees){
    char element=edit_menu();
    string newdata,olddata,newattribute;
    int newage;
    double newsalary;
    while (element!='0'){
        switch (element){
            case'1':
                cout<<"Old: "<<employees.name<<endl;
                cout<<"New: ";
                cin>>newdata;
                employees.name=newdata;
                printheading();
                printemployees(employees);
                break;
            case'2':
                cout<<"Old: "<<employees.ID<<endl;
                cout<<"New: ";
                cin>>newdata;
                employees.ID=newdata;
                printheading();
                printemployees(employees);
                break;
            case'3':
                cout<<"Old: "<<employees.age<<endl;
                cout<<"New: ";
                cin>>newage;
                employees.age=newage;
                printheading();
                printemployees(employees);
                break;
            case'4':
                cout<<"Old: "<<employees.role<<endl;
                cout<<"New: ";
                cin>>newdata;
                employees.role=newdata;
                printheading();
                printemployees(employees);
                break;
            case'5':
                cout<<"Old: "<<employees.salary<<endl;
                cout<<"New: ";
                cin>>newsalary;
                employees.salary=newsalary;
                printheading();
                printemployees(employees);
                break;
            case'6':
                cout<<"Old: "<<employees.status<<endl;
                cout<<"New: ";
                cin>>newdata;
                employees.status=newdata;
                printheading();
                printemployees(employees);
                break;
            case'7':
                cout<<"Old: "<<employees.attribute<<endl;
                cout<<"New: ";
                cin>>newdata;
                olddata=employees.attribute;
                newattribute=olddata+", "+newdata;
                employees.attribute=newattribute;
                printheading();
                printemployees(employees);
                break;

        }
        element=edit_menu();
    }
}
