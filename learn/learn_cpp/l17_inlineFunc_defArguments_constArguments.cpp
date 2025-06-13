#include <iostream>

using namespace std;

// inline int product(int a, int b){

//     // do not use inline functions with static vriables.

//     // static int c = 2;
//     // c = c * (a+b);
//     return (a*b);
// }

float moneyRecieved(int currentMoney, float factor = 1.04f){
    return (currentMoney * factor);
}

// here function cannot change data in p.
// int str_len(const char *p){
//     return 0; // just returning 0 as return is a int.
// }

int main(){
    int money;
    cout << "Enter the current money: ";
    cin >> money;
    // cout << "the value is: " << product(a, b) << endl;
    // cout << "the value is: " << product(a, b) << endl;
    // cout << "the value is: " << product(a, b) << endl;
    // cout << "the value is: " << product(a, b) << endl;
    // cout << "the value is: " << product(a, b) << endl;
    cout << "if you have "<< money <<" rupess in bank you will get Rs: "<<moneyRecieved(money, 8.9098)<<" in one year";

    return 0;
}