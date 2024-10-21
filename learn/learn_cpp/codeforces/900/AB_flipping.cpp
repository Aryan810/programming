#include <iostream>
#include <vector>
#include <unordered_map>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

int logic(string s){
    if (s.find("A") >= s.length()){
        return 0;
    }
    unordered_map<int, bool> data;
    bool found = 1;
    while (found){
        int x = data.size();
        found = 0;
        for (int i=0;i<s.size()-1;i++){
            if ((s.at(i)=='A' && s.at(i+1)=='B')&&(data[i] == 0)){
                s.at(i) = 'B';
                s.at(i+1) = 'A';
                data[i] = 1;
                found = 1;
            }
        }
    }
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << logic(s) << endl;
    }

    return 0;
}