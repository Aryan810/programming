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
        unordered_set<char> m;
        lli ans = 0;
        for (int i=0;i<n;i++){
            m.insert(s[i]);
            ans += m.size();
        }
        cout << ans << endl;
    }

    return 0;
}