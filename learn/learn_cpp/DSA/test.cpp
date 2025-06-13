#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){

    // map<int, int> m;
    // // m[8000] += 1;
    // // m[800] = 23;
    // // cout << m.size() << endl;
    // string s = "1232";
    // // cout << (s.find('5'));
    // // s.erase(0, 1);
    // int temp = s.find("2");
    // cout << temp << endl;
    // cout << s << endl;
    // s.erase(1, 2);
    // cout << s << endl;

    map<char, int> s;
    s['a'] = 4;
    s['b'] = 10;
    map<char, int> p;
    s['a'] = 4;
    s['b'] = 10;
    cout << (s==p);
    

    return 0;
}