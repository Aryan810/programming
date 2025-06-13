#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(vi& a, int& m, string& s){
    if (s.size() != a.size()){
        return 0;
    }
    unordered_map <int, char> ic;
    unordered_map <char, int> ci;
    for (int i=0;i<s.size();i++){
        if (ic.find(a[i])==ic.end() && ci.find(s[i]) == ci.end()){
            ic[a[i]] = s[i];
            ci[s[i]] = a[i];
        }else{
            if (ic[a[i]] != s[i] || ci[s[i]]!=a[i]){
                return 0;
            }
        }
        // cout << a[i] << " " << d[a[i]] << endl;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        int m;
        cin >> m;
        for (int i=0;i<m;i++){
            string s1;
            cin >> s1;
            cout << (logic(a, m, s1)?"YES":"NO") << endl;
        }
    }

    return 0;
}