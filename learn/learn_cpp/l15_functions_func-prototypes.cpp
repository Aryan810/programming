#include <iostream>

using namespace std;

// Function prototype: 
// int sum(int a, int b);
    // OR
// int sum(int, int)

void func1();

int main(){

    // int n1, n2;
    // cout << "Enter first number: "<<endl;
    // cin >> n1;

    // cout << "Enter second number: "<<endl;
    // cin >> n2;
    // cout << "the sum is: " << sum(n1, n2)<<endl;

    // Here n1 and n2 are actual parameters
    func1();


    return 0;
}

/* 
   we wrote function at last, this is only valid if
   we use function prototype at starting
*/
// int sum(int a, int b){
//     // here a, b are formal parameters which here taking value of actual parameters n1 and n2.

//     return (a+b);
// }

void func1(){
    cout << "we are in func1" << endl;
}