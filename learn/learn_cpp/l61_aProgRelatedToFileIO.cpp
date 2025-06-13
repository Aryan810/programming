#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string name;
    ofstream out("l60_test.txt");
    cout << "Enter your name: ";
    cin >> name;

    out << name; // writing the string to the pipe.

    out.close();

    ifstream in("l60_test.txt");
    string data;
    // in >> data;
    getline(in, data);
    cout << "The content in file is: " << data <<endl;

    return 0;
}