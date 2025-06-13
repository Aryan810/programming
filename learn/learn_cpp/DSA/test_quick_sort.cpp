#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){
    // vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(4);
    // vec.push_back(8);
    // vec.push_back(5);
    // vector<int>::iterator i = find(vec.begin(), vec.end(), 8);
    // cout << i-vec.begin();
    
    // string s = "<aryan>";
    // s.erase(s.end()-1);
    // cout << s;

    // stack<int> s;
    // for (int i=0;i<114;i++){s.push(4);}
    // cout << s.size();
    // s.pop();

    string s = "aryan~mahan";
    cout << s.substr(6, s.size()-6-1);

    // vector<string> * ptr;
    // ptr = new vector<string>();
    // ptr->push_back("first");
    // ptr->push_back("second");
    // cout << ptr->at(1);

    return 0;
}