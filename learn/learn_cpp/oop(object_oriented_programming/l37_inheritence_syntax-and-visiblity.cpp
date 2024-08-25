#include <iostream>

using namespace std;

class Employee{
    // int id;
    // float salary;
    public:
        int id;
        float salary;
        Employee(){}
        Employee(int inpId){
            id = inpId;
            salary = 34;
        }

};

// Derived class syntax
/*
class {{derived-class-name}} : {{visiblity-mode(public or private(DEFAULT))}} {{base-clas-name}}
{

}
*/

// Creating a Programmer class derived from employee class.
class Programmer : public Employee{
        public:
            int langCode;
            Programmer(int inpId, int lang_code = 9){
                langCode = lang_code;
                id = inpId;
            }
            void getData(void){
                cout << id << endl;
            }
};

int main(){
    Employee aryan(1), anuj(2);
    cout << aryan.salary;
    cout<<endl<<anuj.salary;

    Programmer shubham(3);
    cout<<endl<<shubham.langCode<<endl;
    shubham.getData();
    cout << shubham.id; // running only because we inherited programmer from employee publically
    return 0;
}