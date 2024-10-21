#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
	return (a.second > b.second);
}
int main() {
	int n;
	cin >> n;
	map<int, set<string> > m;
    
    for (int i=0;i<n;i++){
        int marks;
        string name;
        cin >> name;
        cin >> marks;
        m[marks].insert(name);
    }
    for (auto it = --m.end();;it--){
        auto & names = it->second;
        int marks = it->first;
        for (auto name: names){
            cout << name << " " << marks << endl;
        }
        if (it == m.begin()){break;}
    }
}