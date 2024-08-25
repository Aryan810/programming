#include <iostream>

using namespace std;

class Employee{
    int id;
    int salary;
    public:
        void setId(void){
            salary = 122;
            cout << "Enter Id: ";
            cin >> id;
            cout << endl;
        }
        void getId(void){
            cout << "The id of this employee is "<<id<<endl;
        }
};

int main(){

    Employee Cust[4];
    for (int i = 0; i < 4; i++)
    {
        Cust[i].setId();
        Cust[i].getId();
    }
    
    

    return 0;
}