#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    string num;
    for (int i=0;i<t;i++){
        cin >> num;
        cout << stoi(num.substr(0, 1))+stoi(num.substr(1, 2)) << endl;
        num = "";
    }
    

    return 0;
}