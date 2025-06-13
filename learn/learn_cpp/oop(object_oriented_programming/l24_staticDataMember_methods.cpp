#include <iostream>

using namespace std;

class Employee
{
    int id;
    static int count;

public:
    void setData(void)
    {
        cout << endl;
        cout << "Enter ID: ";
        cin >> id;
        cout << endl;
        count++;
    }
    void getData(void)
    {
        cout << "ID is "<<id<<" and enployee no. "<<count<<endl;
    }

    // NOW WE ARE MAKING A Static Function called getCount.
    static void getCount(void){
        cout << "The current count is: "<<count<<endl;
    }
};

int Employee :: count = 0; // Here 'count' is a static data members.

int main()
{

    Employee aryan, anuj, shubham;
    // aryan.id = 1;        // These will give error as id and count are private members.
    // aryan.count = 1;
    aryan.setData();
    aryan.getData();

    anuj.setData();
    anuj.getData();

    shubham.setData();
    shubham.getData();

    cout << "\nNOW WE ARE GOING TO RUN getCount>>>\n";
    Employee :: getCount(); // here getCount is a static member function.

    return 0;
}