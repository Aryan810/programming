#include <iostream>

using namespace std;

int factorial(int num){
    if ((num == 0) or (num == 1)){
        return 1;
    }else{ 
        return (num * factorial(num - 1));
    }
}

int fibonacci(int a){
    if ((a==1)or(a==2)){
        return 1;
    }else{
        return (fibonacci(a-1) + fibonacci(a-2));
    }
}

int fib_iterative(int a){
    if ((a==1)or(a==2)){
        return 1;
    }else{
        int b = 1, c = 1;
        int temp = 0;
        for (int i = 0; i < (a - 2); i++)
        {
            temp = b + c;
            b = c;
            c = temp;
        }
        
        return temp;
    }
}

int main(){

    int a;
    // while (1){
    //     cout << "Enter a number: "<<endl;
    //     cin >> a;
    //     cout << "The factorial of "<< a << " is "<<factorial(a)<<endl;
    // }


    while (1){
        cout << "Enter a number: "<<endl;
        cin >> a;
        cout << "The fibonacci of "<< a << " is "<<fib_iterative(a)<<endl;
    }

    return 0;
}