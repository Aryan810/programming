#include <iostream>

using namespace std;

// struct employee
// {
//     /* data */
//     int id;
//     char grade;
//     float salary;
// };

//OR

// typedef struct employee
// {
//     int id;
//     char grade;
//     float salary;
// } ep;

//or

// struct employee
// {
//     /* data */
//     int id;
//     char grade;
//     float salary;
// };

// typedef employee ep;


// UNIONS:
 
// union money
// {
//     int rice;
//     char car;
//     float pounds;
// };



int main(){

    // ep aryan;
    // aryan.id = 0;
    // aryan.grade = 'a';
    // aryan.salary = 1200000;
    // cout << aryan.salary;

    // union money m1;
    // m1.rice = 123;
    // m1.car = 'a';
    // cout << m1.rice;
    // cout << m1.car;

    enum meal{breakfast, lunch, dinner};
    // cout << lunch;
    meal m1 = dinner;
    cout << (m1==2); // 
    return 0;
}