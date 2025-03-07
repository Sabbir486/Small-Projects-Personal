#include<bits/stdc++.h>
using namespace std;

struct Employee{
    int id;
    string name;
    double salary;
};

//For Printing
void displayEmployee(const Employee& emp){
    cout<<"Id: "<<emp.id<<" , Name: "<<emp.name<<" , Salary: "<<emp.salary<<endl;
}

int main(){
    vector<Employee> employees = {
        {101, "Sabbir", 100000},
        {102, "Rony", 400000},
        {103, "Fahim", 500000},
        {104, "Naimur", 300000},
        {105, "Tanvir", 200000},
    };

    //lambda ---> unnamed function ---> [](){}
    sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2){
        return e1.salary > e2.salary;
    });
    cout<<"Employees sorted according salary "<<endl;
    for_each(employees.begin(), employees.end(), displayEmployee);
    cout<<endl<<endl;


    vector<Employee> highEarner;
    copy_if(employees.begin(), employees.end(), back_inserter(highEarner), 
    //lambda function
    [](const Employee& e){
        return e.salary > 300000;
    });
    cout<<"Employees who are high earners "<<endl;
    for_each(highEarner.begin(), highEarner.end(), displayEmployee);
    cout<<endl<<endl;


    double totalSalary = accumulate(employees.begin(), employees.end(), 0.0, 
    [](double sum, const Employee& e){
        return sum + e.salary;
    });
    cout<<"Total Salary: "<<totalSalary<<endl;
    cout<<endl;

    // auto highestPaid = max_element(employees.begin(), employees.end(), 
    // [](const Employee& e1, const Employee& e2){
    //     return e1.salary < e2.salary;
    // });
    // cout<<"Highest Paid: "<<highestPaid<<endl;
    
    return 0;
}