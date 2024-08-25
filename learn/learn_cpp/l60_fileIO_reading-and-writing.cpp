#include <iostream>
#include <fstream>
#include <string>

/*
The useful classes to work in files in c++ are.
1: fstream
2: ifstream --> derived from fstreambase
3: ofstream --> derived from fstreambase


In order to work with files in c++, you will have to open it. Primarily,
there are 2 ways to open a file: 
1: Using the constructor
2: Using the member funtion open() of the class
*/

using namespace std;

int main(){
    string st = "written by programme";
    // Opening files using a constructor and writing to it.
    // ofstream out("l60_test.txt");
    // out << st;

    // Opening files using a constructor and reading to it.
    ifstream in("l60_testb.txt");
    string inp;
    // in >> inp;
    getline(in, inp);
    cout << inp;
    return 0;
}