#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(int n, vi p, string & s){
    vector<int> lrs;
    // vector<int> cps;
    for (int i=1;i<n-2;i++){
        if (s[i] == 'L' && s[i+1] == 'R'){
            lrs.push_back(i);
        }
    }
    if (lrs.size()==0){return 1;}
    int m=1e9;
    int M = 0;
    auto it = lrs.begin();
    for (int i=0;i<n;i++){
        if (p[i] > M){
            M = p[i];
        }
        if (*it == i && it != lrs.end()){
            if (M != *it+1){
                return 0;
            }
            it++;
        }
    }
    
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> p(n);
        for (int i=0;i<n;i++) cin >> p[i];
        string s;
        cin >> s;
        for (int i=0;i<q;i++){
            int x;
            cin >> x;
            (s[x-1] == 'L')?(s[x-1]='R'):(s[x-1]='L');
            // cout << s << endl;
            cout << (logic(n, p, s)?"YES":"NO") << endl;
        }
    }
    return 0;
}