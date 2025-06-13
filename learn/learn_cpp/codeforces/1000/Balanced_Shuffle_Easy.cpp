#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool comp(pair<int, pair<int, char> > a, pair<int, pair<int, char> > b){
    if (a.first == b.first){
        return (a.second.first > b.second.first);
    }else{
        return (a.first < b.first);
    }
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    vector < pair<int, pair<int, char> > > v(s.size());
    int pb = 0;
    for (int i=0;i<s.size();i++){
        v[i] = {pb, {i, s[i]}};
        pb +=  (s[i] == ')')?-1:1;
    }
    // cout << v.size() << endl;
    sort(v.begin(), v.end(), comp);
    // cout << v.size() << endl;
    for (int i=0;i<v.size();i++){
        cout << v[i].second.second;
    }
    cout << endl;
    return 0;
}