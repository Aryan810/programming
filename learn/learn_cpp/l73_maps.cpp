#include <iostream>
#include <map>
#include <string>

using namespace std;

void display(map <string, int> & marks){
    map <string, int> :: iterator iter = marks.begin();
}

int main()
{
    map<string, int> marks;
    marks["aryan"] = 90;
    marks["shubham"] = 60;
    marks["anuj"] = 99;
    marks["neeta"] = 100;
    // marks.insert({{"manoj_gupta", 101}, {"aditya", 74}}); // Don't know why giving error.
    cout << marks.at("aryan")<< endl;
    map <string, int> :: iterator iter = marks.begin();
    for (iter = marks.begin(); iter != marks.end(); iter++){
        cout << (*iter).first << ": "<< ((*iter).second) << endl;
    }
    cout << "The size is: "<<marks.size()<<endl;
    cout << "The max size is: "<<marks.max_size()<<endl;
    
    return 0;
}
