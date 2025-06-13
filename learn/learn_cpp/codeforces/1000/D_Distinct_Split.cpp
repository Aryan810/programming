#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char> r(n+1);
        vector<char> l(n+1);
        r[n] = 0;
        l[0] = 0;
        unordered_set<char> a;
        for (int i=0;i<n;i++){
            a.insert(s[i]);
            l[i+1] = a.size();
        }
        a.clear();
        for (int i=n-1;i>=0;i--){
            a.insert(s[i]);
            r[i] = a.size();
        }
        int ans = 0;
        for (int i=0;i<n-1;i++){
            int x = l[i+1] + r[i+1];
            if (x > ans){
                ans = x;
            }
        }
        cout << ans << endl;
    }

    return 0;
}