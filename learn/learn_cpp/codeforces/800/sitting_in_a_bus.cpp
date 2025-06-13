#include <iostream>
#include <vector>
#include <set>

using namespace std;

int is_right(vector<int> & positions){
    set<int> s;
    s.insert(s.end(), positions[0]);
    for (int i=1;i<positions.size()-1;i++){
        if (!((s.find(positions[i]-1) != s.end()) || (s.find(positions[i]+1) != s.end()))){
            return 0;
        }
        s.insert(s.end(), positions[i]);
    }
    return 1;
}

int main(){
    int t;
    cin >> t;

    int n;
    for (int i=0; i<t;i++){
        cin >> n;
        vector<int> positions(n);
        for (int j = 0; j < n; j++)
        {
            cin >> positions.at(j);
        }
        if (is_right(positions)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    
    return 0;
}