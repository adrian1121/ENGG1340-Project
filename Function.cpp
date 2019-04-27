#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Function.h"
#include "Logic.h"

using namespace std;



extern vector<Employee> employees;
extern int j, i;
extern string filename1,filename2;
extern bool filexist(const char* filename);
extern string filenameA,filenameB;
bool checkFile = filexist("Employee.txt");

string Name;
string id;
string Age;
string Role;
string Salary;
/*
 * Print the information of a specific employee
 * @param employees employees in the vector
 */
void printemployees(Employee employees){
    cout << left;
    cout<<setw(25)<<employees.name<<setw(15)<<employees.ID<<setw(15)<<employees.age<<setw(15);
    cout<<employees.role<<setw(15)<<employees.salary<<setw(15)<<employees.status<<setw(20);
    cout<<employees.attribute<<setw(15)<<employees.rating<<endl;
}
/*
 * Print Heading information of a employee
 */
void printheading(){
    cout << left;
    cout << setw(25) << "Name "<< setw(15) << "ID ";
    cout << setw(15) << "Age "<< setw(15) << "Role ";
    cout << setw(15) << "Salary "<<setw(15)<<"Status ";
    cout<<setw(20)<<"Attributes"<<setw(15)<<"Rating"<<endl;
}
void CheckEmployeeFile(){
  ifstream fin;
  string input;
  int k=0;
  string array[8];
  if (checkFile){
      fin.open("Employee.txt");
      while (getline(fin,input)){
          istringstream buf(input);
          for (int i = 0; i < 8; i++) {
            getline(buf, array[i], ',');
          }
              employees.push_back(Employee());
              employees[k].name = array[0];
              employees[k].ID=array[1];
              employees[k].age = array[2];
              employees[k].role = array[3];
              employees[k].salary= array[4];
              employees[k].status=array[5];
              employees[k].attribute=array[6];
              employees[k].rating=array[7];
              k++;
      }
      fin.close();
  }
}
/*
 * Create new profile for employee
 * Insert all the information of employees in to the vector and file
 */
void CreateProfile(){
  if (checkFile){
      while (true){
          cout<<"Name: ";
          cin.ignore();
          getline(cin,Name);
          if (isLetters(Name)){
              cout<<"valid"<<endl;
              break;
          }

          else
              cout<<"invalid"<<endl;

      }
      cout<<endl;

      while (true){
          cout<<"ID: ";
          getline(cin,id);
          if (isNumber(id)){
              cout<<"valid"<<endl;
              break;
          }

          else
              cout<<"Invalid input!"<<endl;

      }
      cout<<endl;
      while (true){
          cout<<"Age: ";
          getline(cin,Age);
          int AgeInt = atoi(Age.c_str());
          if (isNumber(Age)){
              if (AgeInt<100&& AgeInt>20&&Age.size()==2){
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
      while (true){
          cout<<"Role: ";
          getline(cin,Role);
          if (isLetters(Role)){
              cout<<"valid"<<endl;
              break;
          }

          else
              cout<<"invalid"<<endl;

      }
      cout<<endl;
      while (true){
          cout<<"Salary($): ";
          getline(cin,Salary);
          if (isNumber(Salary)){
              cout<<"valid"<<endl;
              break;
          }
          else
              cout<<"invalid"<<endl;
      }
      cout<<endl;
      ofstream writer("Employee.txt");
      int vectorSize= employees.size();
      employees.push_back(Employee());
      employees[vectorSize].name=Name;
      employees[vectorSize].ID=id;
      employees[vectorSize].age=Age;
      employees[vectorSize].role=Role;
      employees[vectorSize].salary= Salary;
      employees[vectorSize].status="Active";
      employees[vectorSize].attribute="NULL";
      employees[vectorSize].rating="NULL";

      for (int i = 0; i < employees.size(); i++) {
       writer << employees[i].name << "," << employees[i].ID << "," << employees[i].age << "," << employees[i].role << "," << employees[i].salary <<","<<employees[i].status<<","<<employees[i].attribute<<","<<employees[i].rating<< endl;
      }
      writer.close();

  }else {
      ofstream fout;
      fout.open ("Employee.txt");
       while (true){
          cout<<"Name: ";
          cin.ignore();
          getline(cin,Name);
          if (isLetters(Name)){
              cout<<"valid"<<endl;
              break;
          }

          else
              cout<<"invalid"<<endl;

      }
      cout<<endl;

      while (true){
          cout<<"ID: ";
          getline(cin,id);
          if (isNumber(id)){
              cout<<"valid"<<endl;
              break;
          }

          else
              cout<<"Invalid input!"<<endl;

      }
      cout<<endl;
      while (true){
          cout<<"Age: ";
          getline(cin,Age);
          int AgeInt = atoi(Age.c_str());
          if (isNumber(Age)){
              if (AgeInt<100&& AgeInt>20){
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
      while (true){
          cout<<"Role: ";
          getline(cin,Role);
          if (isLetters(Role)){
              cout<<"valid"<<endl;
              break;
          }

          else
              cout<<"invalid"<<endl;

      }
      cout<<endl;
      while (true){
          cout<<"Salary($): ";
          getline(cin,Salary);
          if (isNumber(Salary)){
              cout<<"valid"<<endl;
              break;
          }
          else
              cout<<"invalid"<<endl;
      }

      int vectorSize= employees.size();
      employees.push_back(Employee());
      employees[vectorSize].name=Name;
      employees[vectorSize].ID=id;
      employees[vectorSize].age=Age;
      employees[vectorSize].role=Role;
      employees[vectorSize].salary= Salary;
      employees[vectorSize].status="Active";
      employees[vectorSize].attribute="NULL";
      employees[vectorSize].rating="NULL";
      for (int i = 0; i < employees.size(); i++) {
       fout << employees[i].name << "," << employees[i].ID << "," << employees[i].age << "," << employees[i].role << "," << employees[i].salary <<","<<employees[i].status<<","<<employees[i].attribute<<","<<employees[i].rating<< endl;
      }
      fout.close();

  }
}
/*
 * Show the information of employees by different categories in ascending order
 * 1. Show through ID
 * 2. Show through name
 * 3. Show through Age
 * 4. Show through role
 * 5. Show through Salary
 * 6. Show through status
 * 7. Show through rating
 */

void Showprofile(){
char choice=show_menu();
while (choice!='8'){
  int i=0;
  int Checkprofile;

  if (employees.size()==0){
    cout<<"No result found!"<<endl;
    break;
  }
  else{
    switch (choice){
      case'1':
      {
        for(i=0;i<employees.size()-1;i++){
          for(int k=i;k<employees.size()-1;k++){
            sort(employees.begin(), employees.end(), comparename);
          }
        }
        cout<<"Total employees: "<<employees.size()<<endl;
        cout<<"  ";
        printheading();
        for(i=0;i<employees.size();++i){
          cout<<i+1<<".";
          printemployees(employees[i]);
          Checkprofile++;
          cout<<endl;
        }
        break;
      }
      case'2':
      {
        for(i=0;i<employees.size()-1;i++){
          for(int k=i;k<employees.size()-1;k++){
            sort(employees.begin(), employees.end(), compareID);
          }
        }
        cout<<"Total employees: "<<employees.size()<<endl;
        cout<<"  ";
        printheading();
        for(i=0;i<employees.size();++i){
          cout<<i+1<<".";
          printemployees(employees[i]);
          Checkprofile++;
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
        cout<<"  ";
        printheading();
        for(i=0;i<employees.size();++i){
          cout<<i+1<<".";
          printemployees(employees[i]);
          Checkprofile++;
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
        cout<<"  ";
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
            cout<<"  ";
            printheading();
            for(i=0;i<employees.size();++i){
                cout<<i+1<<".";
                printemployees(employees[i]);
                Checkprofile++;
                cout<<endl;
            }
            break;
        }
      case '6':
        {
            for(i=0;i<employees.size()-1;i++){
                for(int k=i;k<employees.size()-1;k++){
                    sort(employees.begin(), employees.end(), comparestatus);
                }
            }
            cout<<"Total employees: "<<employees.size()<<endl;
            cout<<"  ";
            printheading();
            for(i=0;i<employees.size();++i){
                cout<<i+1<<".";
                printemployees(employees[i]);
                Checkprofile++;
                cout<<endl;
            }
            break;
        }
      case '7':
        {
            int check_in_hour;
            int check_out_hour;
            int check_in_minutes;
            int check_out_minutes;
            int diff_minutes;
            int total_time_raw;
            for( i =0;i <employees.size();i++){
                employees[i].total_time = 0;
                for(int j=0;j<31;j++){
                    if (employees[i].checkin[j] == "") {
                      break;
                    }
                    check_in_hour= atoi(((employees[i].checkin[j]).substr(0,2)).c_str());
                    check_out_hour= atoi(((employees[i].checkout[j]).substr(0,2)).c_str());
                    //cout << check_in_hour << " " << check_out_hour << " " << check_out_hour - check_in_hour << endl;
                    check_in_minutes= atoi(((employees[i].checkin[j]).substr(2,2)).c_str());
                    check_out_minutes=atoi(((employees[i].checkout[j]).substr(2,2)).c_str());
                    if (check_in_minutes > check_out_minutes){
                        diff_minutes= check_in_minutes - check_out_minutes;
                    }
                    else if (check_in_minutes < check_out_minutes)
                    {
                        diff_minutes= check_out_minutes - check_in_minutes;
                    }
                    total_time_raw=((check_out_hour-check_in_hour)*60) + diff_minutes;
                    employees[i].total_time += total_time_raw;
                }
            }
            for( i =0;i<employees.size();i++){
                if(employees[i].total_time>= 18600){
                    employees[i].rating = "9";
                }
                if(employees[i].total_time<18600 && employees[i].total_time >=16740){
                    employees[i].rating = "8";
                }
                if(employees[i].total_time <16700 && employees[i].total_time >=14880){
                    employees[i].rating = "7";
                }
                if(employees[i].total_time <14880 && employees[i].total_time >=13020){
                    employees[i].rating = "6";
                }
                if(employees[i].total_time < 13020 && employees[i].total_time >=11160){
                    employees[i].rating = "5";
                }
                if(employees[i].total_time<11160 && employees[i].total_time >=9300){
                    employees[i].rating = "4";
                }
                if(employees[i].total_time<9300 && employees[i].total_time >=7440){
                    employees[i].rating = "3";
                }
                if(employees[i].total_time <7440 && employees[i].total_time >=5580){
                    employees[i].rating = "2";
                }
                if(employees[i].total_time <5580 && employees[i].total_time>=3720){
                    employees[i].rating = "1";
                }
                if(employees[i].total_time <3720 ){
                    employees[i].rating = "0";
                }
            }
            int max=employees[0].total_time;
            string Bestemployee,Bestid;
            for(int i=0; i<employees.size(); i++){
                for(int j=i+1; j<employees.size(); j++){
      //If there is a smaller element found on right of the array then swap it.
                    if(max < employees[i].total_time){
                        max = employees[i].total_time;
                        Bestemployee=employees[i].name;
                        Bestid=employees[i].ID;
                        Checkprofile++;
                        sort(employees.begin(), employees.end(), comparerating);
                    }
                }
            }
            cout<<"Total employees: "<<employees.size()<<endl;
            cout<<"Best employee: "<<Bestemployee<<endl;
            cout<<"ID: "<<Bestid<<endl;
            cout<<"  ";
            printheading();
            for(int i=0;i<employees.size();++i){
                cout<<i+1<<".";
                printemployees(employees[i]);
                cout<<endl;
            }
            break;

        }
      default:
        cout << "Invalid input!" << endl;


      }


    }
    choice=show_menu();

  }


}
/*
 * Search the information of specific employees by choosing different categories
 * 1. Search through ID
 * 2. Search through name
 * 3. Search through Age
 * 4. Search through role
 * 5. Search through Salary
 * 6. Search through status
 */

void Searchprofile(){
char choice=employee_menu();
                            while (choice!='6'){

                                int i;
                                bool trueresult=true;
                                switch (choice){

                                    case'1':
                                        {
                                          string Name;
                                          while (true){
                                              cout<<"Name: ";
                                              cin.ignore();
                                              getline(cin,Name);
                                              if (isLetters(Name)){
                                                  cout<<"valid"<<endl;
                                                  break;
                                              }

                                              else
                                                  cout<<"invalid"<<endl;

                                          }
                                          cout<<endl;
                                              for(i=0;i<employees.size();++i){
                                                  if (employees[i].name==Name){
                                                      printheading();
                                                      printemployees(employees[i]);
                                                      trueresult=false;
                                                      break;
                                                  }
                                              }
                                              if (trueresult)
                                                  cout<<"No result found!!"<<endl;

                                          break;
                                        }
                                    case'2':
                                        {

                                            string id;
                                            while (true){
                                                cout<<"ID: ";
                                                cin.ignore();
                                                getline(cin,id);
                                                if (isNumber(id)){
                                                    cout<<"valid"<<endl;
                                                    break;
                                                }

                                                else
                                                    cout<<"Invalid input!"<<endl;

                                            }
                                            cout<<endl;
                                                for(i=0;i<employees.size();++i){
                                                    if (employees[i].ID==id){
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        trueresult=false;
                                                        break;
                                                    }
                                                }
                                                if (trueresult)
                                                    cout<<"No result found!!"<<endl;

                                            break;
                                        }
                                    case'3':
                                        {
                                            string Age;
                                            int count=0;
                                             while (true){
                                                cout<<"Age: ";
                                                cin.ignore();
                                                getline(cin,Age);
                                                int AgeInt = atoi(Age.c_str());
                                                if (isNumber(Age)){
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
                                                for(i=0;i<employees.size();++i){
                                                    if (employees[i].age==Age){
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        count++;
                                                    }
                                                }
                                                if (count==0)
                                                    cout<<"No result found!"<<endl;
                                                else
                                                    trueresult=false;

                                            break;
                                        }
                                    case'4':
                                        {
                                            string Role;
                                            int count;
                                            while (true){
                                                cout<<"Role: ";
                                                cin.ignore();
                                                getline(cin,Role);
                                                if (isLetters(Role)){
                                                    cout<<"valid"<<endl;
                                                    break;
                                                }

                                                else
                                                    cout<<"invalid"<<endl;
                                            }
                                            cout<<endl;
                                                for(i=0;i<employees.size();++i){
                                                    if (employees[i].role==Role){
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        count++;
                                                    }
                                                }
                                                if (count==0)
                                                    cout<<"No result found!"<<endl;
                                                else
                                                    trueresult=false;

                                            break;
                                        }
                                    case'5':
                                        {
                                            string wages,option;
                                            int Intwage,Intinput,truecount=0;
                                            cout<<"1. Higher than: "<<endl;
                                            cout<<"2. Lower than: "<<endl;
                                            cout<<"Your option: ";
                                            cin.ignore();
                                            getline(cin,option);
                                            if (option=="1"){
                                                while (true){
                                                    cout<<"Higher than ";
                                                    getline(cin,wages);
                                                    Intinput = atoi(wages.c_str());
                                                    if (isNumber(wages)){
                                                        cout<<"valid"<<endl;
                                                        break;
                                                    }
                                                    else
                                                        cout<<"invalid"<<endl;
                                                }
                                                for(int i=0;i<employees.size();++i){
                                                    Intwage=atoi((employees[i].salary).c_str());
                                                    if (Intwage>=Intinput){
                                                        truecount++;
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        cout<<endl;
                                                    }
                                                }

                                            }
                                            else if (option=="2"){
                                                while (true){
                                                    cout<<"Lower than ";
                                                    cin.ignore();
                                                    getline(cin,wages);
                                                    Intinput = atoi(wages.c_str());
                                                    if (isNumber(wages)){
                                                        cout<<"valid"<<endl;
                                                        break;
                                                    }
                                                    else
                                                        cout<<"invalid"<<endl;
                                                }
                                                for(int i=0;i<employees.size();++i){
                                                    Intwage=atoi((employees[i].salary).c_str());
                                                    if (Intwage<=Intinput){
                                                        truecount++;
                                                        printheading();
                                                        printemployees(employees[i]);
                                                        cout<<endl;
                                                    }
                                                }
                                                if (truecount==0)
                                                    cout<<"No result found!"<<endl;
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
}
/*
 * Fire the specific employee inserting the particular ID or Name
 * The status of the employee will turned "Fired!"
 */

void Fireprofile(){
string nameorid;
                                int check=0;
                                cout<<"Name or ID to be fired: "<<endl;
                                cin.ignore();
                                int toBeEdited;
                                getline(cin,nameorid);
                                for(int i=0;i<employees.size();++i){
                                    if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                        cout<<employees[i].name<<" "<<employees[i].ID<<" has been fired!"<<endl;
                                        cout << employees[i].status<<endl;
                                        employees[i].status="Fired!";
                                        cout << employees[i].status;
                                        check++;
                                        toBeEdited=i;
                                        ifstream fin;
                                        ofstream fout;
                                        string str,newline;
                                        int line =0;
                                        newline=employees[i].name + "," +employees[i].ID + "," + employees[i].age + "," + employees[i].role + "," + employees[i].salary+","+employees[i].status+","+employees[i].attribute +","+employees[i].rating;
                                        fin.open("Employee.txt");
                                        fout.open("temp.txt");
                                        while (getline(fin,str)){
                                            if (line==toBeEdited ){
                                                line++;
                                                fout <<newline<<endl;
                                                continue;
                                            }
                                            fout << str <<endl;
                                            line++;
                                        }
                                        fin.close();
                                        fout.close();
                                        remove ("Employee.txt");
                                        rename ("temp.txt","Employee.txt");
                                        break;
                                    }
                                }

                                if (check==0)
                                    cout<<"No result found!"<<endl;
}
/*
 * Delete the specific employee inserting the particular ID or Name
 * The information of the specific employees will be deleted
 */
void Deleteprofile(){
string nameorid;
                                cout<<"Please enter name or id to be deleted: ";
                                cin.ignore();
                                getline(cin,nameorid);
                                cout<<endl;
                                int toBeRemoved =0;
                                int line=0,check=0;
                                for(int i=0;i<employees.size();++i){
                                    if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                        cout<<employees[i].name<<" "<<employees[i].ID<<" has been removed!"<<endl;
                                        toBeRemoved = i;
                                        employees.erase(employees.begin()+i);
                                        j=j-1;
                                        check++;
                                        break;
                                    }
                                }
                                if (check==0)
                                    cout<<"Invalid input!"<<endl;
                                ifstream fin;
                                ofstream fout;
                                fin.open("Employee.txt");
                                fout.open("temp.txt");
                                string str;
                                while (getline(fin,str)){
                                    if (line==toBeRemoved ){
                                        continue;
                                    }
                                    fout << str <<endl;
                                    line++;
                                }
                                fin.close();
                                fout.close();
                                remove ("Employee.txt");
                                rename ("temp.txt","Employee.txt");
}
/*
 * Edit the information of specific employees through inserting specific ID or Name
 * 1. Edit ID
 * 2. Edit name
 * 3. Edit Age
 * 4. Edit role
 * 5. Edit Salary
 * 6. Edit status
 * 7. Edit Attributes
 */
void Editprofile(){
string nameorid;
                                cout<<"Name or ID to be edited: ";
                                cin.ignore();
                                int toBeEdited =0,check=0;
                                getline(cin,nameorid);
                                    for(int i=0;i<employees.size();++i){
                                        if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
                                                printheading();
                                                printemployees(employees[i]);
                                                char element=edit_menu();
                                                check++;
                                                string newdata,olddata,newattribute;
                                                while (element!='8'){
                                                    switch (element){
                                                        case'1':{
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
                                                            toBeEdited =i;
                                                            employees[i].name=newdata;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                        }case'2':{
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
                                                            toBeEdited = i;
                                                            break;
                                                       } case'3':{
                                                            while (true){
                                                                cout<<"Old: "<<employees[i].age<<endl;
                                                                cout<<"New: ";
                                                                cin.ignore();
                                                                getline(cin,newdata);
                                                                int AgeInt = atoi(newdata.c_str());
                                                                if (isNumber(newdata)){
                                                                    if (AgeInt<100&&AgeInt>20&&newdata.size()==2){
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
                                                            toBeEdited = i;
                                                            break;
                                                        }case'4':{
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
                                                            toBeEdited = i;
                                                            break;
                                                        }case'5':{
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
                                                            toBeEdited = i;
                                                            break;
                                                        }case'6':{
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
                                                            toBeEdited = i;
                                                            break;
                                                        }case'7':{
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
                                                            if (olddata=="NULL")
                                                                    newattribute=newdata;
                                                            else
                                                                newattribute=olddata+"- "+newdata;
                                                            employees[i].attribute=newattribute;
                                                            toBeEdited =i;
                                                            printheading();
                                                            printemployees(employees[i]);
                                                            break;
                                                       } default:
                                                            cout<<"Invalid Input!"<<endl;


                                                    }
                                                    ifstream fin;
                                                    ofstream fout;
                                                    string str,newline;
                                                    int line =0;
                                                    newline=employees[i].name + "," +employees[i].ID + "," + employees[i].age + "," + employees[i].role + "," + employees[i].salary+","+employees[i].status+","+employees[i].attribute +","+employees[i].rating;
                                                    fin.open("Employee.txt");
                                                    fout.open("temp.txt");
                                                    while (getline(fin,str)){
                                                        if (line==toBeEdited ){
                                                            line++;
                                                            fout <<newline<<endl;
                                                            continue;
                                                        }
                                                        fout << str <<endl;
                                                        line++;
                                                    }
                                                    fin.close();
                                                    fout.close();
                                                    remove ("Employee.txt");
                                                    rename ("temp.txt","Employee.txt");

                                                    element=edit_menu();
                                                }
                                        }
                                        if (check==0)
                                            cout<<"No result found!"<<endl;
                                    }

}
/*
 * Insert the Checkkin & Checkout time of a month for the specific Employee
 * Store the input into a file and vector
 */
void CheckinCheckout(){
  string check_in_time,check_in_hour,check_in_minutes;
  string check_out_time,check_out_hour,check_out_minutes;
  string day,options;
  string nameorid;
  int DayInt,checkname=0;
  cout<<"Name or ID to be checkin & checkout: "<<endl;
  cin.ignore();
  getline(cin,nameorid);
  for(int i=0;i<employees.size();++i){
      if ((employees[i].name==nameorid)||(employees[i].ID==nameorid)){
          checkname++;
          printemployees(employees[i]);
        for(int x=0;x<31;x++){
          cout<<"Day: "<<x+1<<endl;
          cout<<"1. Continue"<<endl;
          cout<<"2. Exit"<<endl;
          getline(cin,options);
          if (options=="1"){
                  while (true){
                    cout<<" check in hour (HH)"<<endl;
                    getline(cin,check_in_hour);
                    int checkinhourInt = atoi(check_in_hour.c_str());
                    if (isNumber(check_in_hour)){
                      if (checkinhourInt<24&&checkinhourInt>00&&check_in_hour.size()==2){
                        cout<<"valid"<<endl;
                        break;
                      }
                    else
                        cout<<"invalid"<<endl;
                    }
                  }
                  cout<<endl;
                  while (true){
                      cout<<" check in minutes (MM)"<<endl;
                      getline(cin,check_in_minutes);
                      int checkinminutesInt = atoi(check_in_minutes.c_str());
                      if (isNumber(check_in_minutes)){
                          if (checkinminutesInt<60&&checkinminutesInt>0&&check_in_minutes.size()==2){
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
                  check_in_time=check_in_hour+check_in_minutes;
                  cout<<"Check In Time: "<<check_in_time<<endl;
                  while (true){
                      cout<<" check out hour (HH)"<<endl;
                      getline(cin,check_out_hour);
                      int checkouthourInt = atoi(check_out_hour.c_str());
                      if (isNumber(check_out_hour)){
                          if (checkouthourInt<24&&checkouthourInt>00&&check_out_hour.size()==2){
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
                  while (true){
                      cout<<" check out minutes (MM)"<<endl;
                      getline(cin,check_out_minutes);
                      int checkoutminutesInt = atoi(check_out_minutes.c_str());
                      if (isNumber(check_out_minutes)){
                          if (checkoutminutesInt<60&&checkoutminutesInt>00&&check_out_minutes.size()==2){
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
                  check_out_time=check_out_hour+check_out_minutes;
                  cout<<" check out time (HH:MM)"<<check_out_time<<endl;
                  employees[i].checkin[x]=check_in_time;
                  employees[i].checkout[x]=check_out_time;

                string fileName = employees[i].ID + filenameA;
                string fileName2 = employees[i].ID + filenameB;
                bool checkFile1 = filexist(fileName.c_str());
                bool checkFile2 = filexist(fileName2.c_str());
                if (checkFile1){
                  ifstream fin;
                  ofstream fout;
                  fin.open(fileName.c_str());
                  fout.open("newcheckin.txt");
                  for(int k=0;k<31;k++){
                    fout<<employees[i].checkin[k]<<endl;
                  }

                  fin.close();
                  fout.close();
                  remove (fileName.c_str());
                  rename ("newcheckin.txt",fileName.c_str());
                }
                else{
                  ofstream fout;
                  fout.open(fileName.c_str());
                  for(int k=0;k<31;k++){
                    fout<<employees[i].checkin[k]<<endl;
                  }
                  fout.close();

                }
                if (checkFile2){
                  ifstream fin;
                  ofstream fout;
                  fin.open(fileName2.c_str());
                  fout.open("newcheckout.txt");
                  for(int k=0;k<31;k++){
                    fout<<employees[i].checkout[k]<<endl;
                  }

                  fin.close();
                  fout.close();
                  remove (fileName2.c_str());
                  rename ("newcheckout.txt",fileName2.c_str());
                }
                else{
                  ofstream fout;
                  fout.open(fileName2.c_str());
                  for(int k=0;k<31;k++){
                    fout<<employees[i].checkout[k]<<endl;
                  }
                  fout.close();
                }
          }
          else if(options=="2")
            break;


          else
            cout<<"Invalid Input!"<<endl;
        }
        break;
    }

    if (checkname==0)
        cout<<"No result found!"<<endl;
    break;
  }
}



#endif
