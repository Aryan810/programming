#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream inp;
    inp.open("input1.txt");
    for (int i=0;i<21;i++){
        string s;
        inp >> s;
        cout << s << endl;
    }
    string s;
    inp >> s;
    cout << s.size() << " " << s << endl;
    string g;
    inp >> g;
    cout << g << endl;
    inp.close();

    return 0;
}