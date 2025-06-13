#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

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
        int ps = 0;
        int M = 0;
        for (int i=0;i<n/2;i++){
            if (s[i] == s[n-1-i]){
                M += 2;
                ps += 1;
            }else{
                M += 1;
            }
        }
        vector<char> ans(n+1);
        for (int i=0;i<n+1;i++) ans[i] = '0';
        ans[M] = '1';
        if (n%2 != 0){
            ans[M+1] = '1';
        }
        for (int i=0;i<ps;i++){
            M -= 2;
            if (M >= 0){
                ans[M] = '1';
                if (n % 2 != 0){
                    ans[M+1] = '1';
                }
            }
        }
        for (auto a: ans){
            cout << a;
        }cout << endl;

    }

    return 0;
}