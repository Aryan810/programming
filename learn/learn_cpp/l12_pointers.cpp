#include <iostream>

using namespace std;

int main(){

    // what is a pointer ?
    // ANS: datatype which holds the address of other data type.

    int a = 3;
    // &a means address of 'a'
    // or, '&' >> gives address of a variable ('address of' operator)
    int *b = &a;
    // '*' >> means Dereference operator (value at)
    // '*' >> gives value at a given address >> i.e '*b' gives value at address 'b' i.e value of a.
    cout << "address of a "<< b<<endl;
    cout << "addresss of a "<< &a<<endl;

    int** c = &b;
    // '**' >> pointer to pointer i.e it has address of 'b' which is pointer of 'a'.
    cout << "value at c is " << *c << endl;
    cout << "value at value of c is a which is " << **c << " or " << *b <<endl;
    cout << "value of *c == b is " << (*c == b) << endl; 

    return 0;
}