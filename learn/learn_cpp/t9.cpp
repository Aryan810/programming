#include <iostream>


using namespace std;
int age;
int main(int argc, char const *argv[])
{   
    cout << "Enter your age: "<<endl;
    cin >> age;
    // if else statments
    /*
    if (age > 18){
        cout << "you can drive a car"<<endl;

    }else if (age < 18){
        cout << "you can not drive a car"<<endl;
    }else
    {
        cout << "not sure" << endl;
    }
    */


    // switch-case
    switch (age)
    {
    case 18:
        cout << "not sure";
        break;
    case 2:
        cout << "you gave 2";
        break;
    case 22:
        cout << "you gave 22";
        break;
    default:
        cout << "No spetial case";
        break;
    }
    


    return 0;
}

