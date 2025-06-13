#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    ofstream out;
    out.open("l60_test.txt");
    out << "my name is aryan gupta!"<<endl;
    out.close();


    return 0;
}