#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
//creating a structure that holds the essential details of the employer
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

//declaring a constant variable to fix the employee database to 1000
const int MAX_NUM_EMPLOYEES = 1000;
//function calling
char selection_menu();
char employee_menu();
char main_menu();
char edit_menu();
void printheading();
void printemployees(Employee );
void editprofile(Employee );
int main()
{
//Variable declaration of attributes
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



//a vector with each position holding the different particulars of the employee

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
// selection 1: gives us a search option to search amongst the entire database of employers.
//find the correct employee using the ID input taken with in the case block
                        case'1':
                        {
                            char choice=employee_menu();
                            while (choice!='0'){

                                int i;

                                switch (choice){
//provides the

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
//This is for the choice 2 for deletion of employee details
//The employee details are removed from the vector
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
//The 3rd option helps in editing the particulars of an employee
//The id is used to access a particular cell of the vector and make the respective changes
                        case'3':
                            {
                                string nameorid;
                                cout<<"Name or ID to be edited: ";
                                cin.ignore();
                                getline(cin,nameorid);
                                    for(int i=0;i<employees.size();++i){
                                        if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                                printheading();
                                                printemployees(employees[i]);
                                                char element=edit_menu();
                                                string newdata,olddata,newattribute;
                                                while (element!='0'){
                                                    switch (element){
                                                        case'1':
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].name<<endl;
                                                                cout<<"New: ";
                                                                cin.ignore();
                                                                getline(cin,newdata);
                                                                if (isLetters(newdata)){
                                                                    cout<<"valid"<<endl;
                                                                    break;
                                                                }
                                                                else
                                                                    cout<<"invalid"<<endl;
                                                            }
                                                            cout<<endl;
                                                            employees[i].name=newdata;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        case'2':
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].ID<<endl;
                                                                cout<<"New: ";
                                                                cin.ignore();
                                                                getline(cin,newdata);
                                                                if (isNumber(newdata)){
                                                                    cout<<"valid"<<endl;
                                                                    break;
                                                                }
                                                                else
                                                                    cout<<"Invalid input!"<<endl;
                                                            }
                                                            cout<<endl;
                                                            employees[i].ID=newdata;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        case'3':
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].age<<endl;
                                                                cout<<"New: ";
                                                                cin.ignore();
                                                                getline(cin,newdata);
                                                                int AgeInt = atoi(newdata.c_str());
                                                                if (isNumber(newdata)){
                                                                    if (AgeInt<100&&AgeInt>20){
                                                                        cout<<"valid"<<endl;
                                                                        break;
                                                                    }
                                                                    else
                                                                        cout<<"invalid"<<endl;
                                                                }
                                                                else
                                                                    cout<<"invalid"<<endl;
                                                            }
                                                            cout<<endl;
                                                            employees[i].age=newdata;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        case'4':
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].role<<endl;
                                                                cout<<"New: ";
                                                                cin.ignore();
                                                                getline(cin,newdata);
                                                                if (isLetters(newdata)){
                                                                    cout<<"valid"<<endl;
                                                                    break;
                                                                }
                                                                else
                                                                    cout<<"invalid"<<endl;
                                                            }
                                                            cout<<endl;
                                                            employees[i].role=newdata;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        case'5':
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].salary<<endl;
                                                                cout<<"New: ";
                                                                cin.ignore();
                                                                getline(cin,newdata);
                                                                if (isNumber(newdata)){
                                                                    cout<<"valid"<<endl;
                                                                    break;
                                                                }
                                                                else
                                                                    cout<<"invalid"<<endl;
                                                            }
                                                            cout<<endl;
                                                            employees[i].salary=newdata;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        case'6':
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].status<<endl;
                                                                cout<<"New: ";
                                                                cin.ignore();
                                                                getline(cin,newdata);
                                                                if (isLetters(newdata)|| newdata=="Active" || newdata=="Inactive"){
                                                                    cout<<"valid"<<endl;
                                                                    break;
                                                                }
                                                                else
                                                                    cout<<"invalid"<<endl;
                                                            }
                                                            cout<<endl;
                                                            employees[i].status=newdata;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        case'7':
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].attribute<<endl;
                                                                    cout<<"New: ";
                                                                    cin.ignore();
                                                                    getline(cin,newdata);
                                                                    if (isLetters(newdata)){
                                                                        cout<<"valid"<<endl;
                                                                        break;
                                                                    }
                                                                    else
                                                                        cout<<"invalid"<<endl;
                                                            }
                                                            olddata=employees[i].attribute;
                                                            newattribute=olddata+", "+newdata;
                                                            employees[i].attribute=newattribute;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        default:
                                                            cout<<"Invalid Input!"<<endl;
                                                    }
                                                    element=edit_menu();
                                                }
                                        }
                                    }


                                    break;

                             }
//The case 4 creates a new employee details
//A new vector space is created to store thge new employee details in the database
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
//This case block is used to fire an employee from his postion by updating his status in the company
                        case'5':
                            {
                                string nameorid;
                                int check=0;
                                cout<<"Name or ID to be fired: "<<endl;
                                cin.ignore();
                                getline(cin,nameorid);
                                for(i=0;i<employees.size();++i){
                                    if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                        cout<<employees[i].name<<" "<<employees[i].ID<<" has been fired!";
                                        employees[i].status="Fired!";
                                        check++;
                                        break;
                                    }
                                }
                                if (check==0)
                                    cout<<"No result found!"<<endl;
                                break;
                            }
//This redirects back to the options meny and the different choices can then be accesed accordingly
// attribute information can be accessed here.
	
                        case'6':
                            {
                             char choice=show_menu();
                             while (choice!='0'){
                                int i;
                                switch (choice){
//Used to display the Name of the employee
                                    case'1':
                                        {
                                            for(i=0;i<employees.size()-1;i++){
                                                for(int k=i;k<employees.size()-1;k++){
                                                    sort(employees.begin(), employees.end(), compareID);
                                                }
                                            }
                                            cout<<"Total employees: "<<employees.size()<<endl;
                                            printheading();
                                            for(i=0;i<employees.size();++i){
                                                cout<<i+1<<".";
                                                printemployees(employees[i]);
                                                cout<<endl;
                                            }
                                            break;
                                        }
                                    case'2':
                                        {
                                            for(i=0;i<employees.size()-1;i++){
                                                for(int k=i;k<employees.size()-1;k++){
                                                    sort(employees.begin(), employees.end(), comparename);
                                                }
                                            }
                                            cout<<"Total employees: "<<employees.size()<<endl;
                                            printheading();
                                            for(i=0;i<employees.size();++i){
                                                cout<<i+1<<".";
                                                printemployees(employees[i]);
                                                cout<<endl;
                                            }
                                            break;
                                        }
                                    case'3':
                                        {
                                            for(i=0;i<employees.size()-1;i++){
                                                for(int k=i;k<employees.size()-1;k++){
                                                    sort(employees.begin(), employees.end(), compareage);
                                                }
                                            }
                                            cout<<"Total employees: "<<employees.size()<<endl;
                                            printheading();
                                            for(i=0;i<employees.size();++i){
                                                cout<<i+1<<".";
                                                printemployees(employees[i]);
                                                cout<<endl;
                                            }
                                            break;
                                        }
                                    case'4':
                                        {
                                            for(i=0;i<employees.size()-1;i++){
                                                for(int k=i;k<employees.size()-1;k++){
                                                    sort(employees.begin(), employees.end(), comparerole);
                                                }
                                            }
                                            cout<<"Total employees: "<<employees.size()<<endl;
                                            printheading();
                                            for(i=0;i<employees.size();++i){
                                                cout<<i+1<<".";
                                                printemployees(employees[i]);
                                                cout<<endl;
                                            }
                                            break;
                                        }
                                    case'5':
                                        {
                                            for(i=0;i<employees.size()-1;i++){
                                                for(int k=i;k<employees.size()-1;k++){
                                                    sort(employees.begin(), employees.end(), comparesalary);
                                                }
                                            }
                                            cout<<"Total employees: "<<employees.size()<<endl;
                                            printheading();
                                            for(i=0;i<employees.size();++i){
                                                cout<<i+1<<".";
                                                printemployees(employees[i]);
                                                cout<<endl;
                                            }
                                            break;
                                        }
                                    case '6':
                                        {
                                            for(i=0;i<employees.size()-1;i++){
                                                for(int k=i;k<employees.size()-1;k++){
                                                    sort(employees.begin(), employees.end(), comparesalary);
                                                }
                                            }
                                            cout<<"Total employees: "<<employees.size()<<endl;
                                            printheading();
                                            for(i=0;i<employees.size();++i){
                                                cout<<i+1<<".";
                                                printemployees(employees[i]);
                                                cout<<endl;
                                            }
                                            break;
                                        }
                                    default:
                                        cout << "Invalid input!" << endl;

                                }
                                choice=
					
					_menu();
                             }
                            break;
                            }
			case'7':
                            {
                                check=false;
                            }
                        default:
                            {
                                cout<<"invalid input!"<<endl;
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
                check == false;
                break;
        }
    }
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
	cout << "********************************"<< endl;
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


void rating()
{
    for(int i =0;i<1000;i++)
    {
        if(total_time[i] >= 18600)
        {
            employees[i].rating = 10;
            employees[i].salary + = 10000;
        }
        if(total_time[i] <18600 && total_time[i] >=16740)
        {
            employees[i].rating = 9;
            employees[i].salary + = 9000;
        }
        if(total_time[i] <16700 && total_time[i] >=14880)
        {
            employees[i].rating = 8;
            employees[i].salary + = 8000;
        }
        if(total_time[i] <14880 && total_time[i] >=13020)
        {
            employees[i].rating = 7;
            employees[i].salary + = 7000;
        }
        if(total_time[i] < 13020 && total_time[i] >=11160)
        {
            employees[i].rating = 6;
            employees[i].salary + = 6000;
        }
	    if(total_time[i] <11160 && total_time[i] >=9300)
        {
            employees[i].rating = 5;
            employees[i].salary + = 5000;
        }
	    if(total_time[i] <9300 && total_time[i] >=7440)
        {
            employees[i].rating = 4;
            employees[i].salary + = 4000;
        }
	    if(total_time[i] <7440 && total_time[i] >=5580)
        {
            employees[i].rating = 3;
            employees[i].salary + = 3000;
        }
	    if(total_time[i] <5580 && total_time[i] >=3720)
        {
            employees[i].rating = 2;
            employees[i].salary + = 2000;
        }
	    if(total_time[i] <3720 )
        {
            employees[i].rating = 1;
            employees[i].salary + = 1000;
        }
	    
	    
int total_time[1000];
void timing_entry(Employee);
void Total_time(vector<Employee> employees)
{
    int check_in_hour;
    int check_out_hour;
    int check_in_minutes;
    int check_out_minutes;
    int diff_minutes;
    int total_time_raw;
    
    
    for(int i =0;i < 1000;i++){
        for(int j=0;j<31;j++)
        {
          check_in_hour= stoi((employees[i].checkin[j]).substr(0,1));
		
          check_out_hour= stoi((employees[i].checkout[j]).substr(0,1));
		
          check_in_minutes= stoi((employees[i].checkin[j]).substr(3,4));
		
          check_out_minutes=stoi((employees[i].checkout[j]).substr(3,4));
           if (check_in_minutes > check_out_minutes)
           {
               diff_minutes= check_in_minutes - check_out_minutes;
           }
           else if (check_in_minutes < check_out_minutes)
           {
              diff_minutes= check_out_minutes - check_in_minutes; 
           }
           
           
         total_time_raw=((check_out_hour-check_in_hour)*60) + diff_minutes;
           
        }
        total_time[i]= total_time_raw;
    }
}

}
void timing_entry(Employee employees)
{
    string check_in_time;
    string check_out_time;
    
    for(int j=0; j<31;j++)
    { 
        cout << "Please enter day "  << j+1 <<" check in time (HH:MM)"<< endl;
        cin >> check_in_time;
        cout << "Please enter day "  << j+1 <<" check out time"<< endl;
        cin >> check_out_time;
        
        employees.checkin[j]=check_in_time;
        employees.checkout[j]=check_out_time;
        
    }
    
}




void rating(vector<Employee>employees)
{
    int max=employees[0].total_time;
    int Bestemployee;
    for(int i=0; i<999; i++)
    {
        for(int j=i+1; j<1000; j++)
        {
            //If there is a smaller element found on right of the array then swap it.
            if(max < total_time[i])
            {
                max = total_time[i];
                Bestemployee=i;
            }
        }
    }
    
    
}
	    
