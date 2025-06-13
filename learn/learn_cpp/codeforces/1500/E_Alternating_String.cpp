#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1){
        cout << 1 << endl;return;
    }
    if (n%2 == 0){
        int even = 0;int odd = 0;
        vector<int> ve(26, 0), vo(26, 0);
        for (int i=0;i<n;i++){
            if(i&1){vo[s[i]-'a'] += 1;}else{
                ve[s[i]-'a'] += 1;
            }
        }
        for (int i=0;i<26;i++){
            even = max(even, ve[i]);
            odd = max(odd, vo[i]);
        }
        cout << (n - even - odd) << endl;
        return;
    }

    vector<vector<int> > preOdd(n, vector<int>(26, 0));
    vector<vector<int> > preEven(n, vector<int>(26, 0));
    vector<vector<int> > sufOdd(n, vector<int>(26, 0));
    vector<vector<int> > sufEven(n, vector<int>(26, 0));
    int ans = 1e18;
    vector<int> tempE(26, 0);
    vector<int> tempO(26, 0);
    for (int i=0;i<n;i++){
        if (i&1){
            tempO[s[i]-'a'] += 1;
        }else{
            tempE[s[i]-'a'] += 1;
        }
        preOdd[i] = (tempO);
        preEven[i] = (tempE);
    }
    tempE.assign(26, 0);
    tempO.assign(26, 0);
    for (int i=n-1;i>=0;i--){
        if (i&1){
            tempO[s[i]-'a'] += 1;
        }else{
            tempE[s[i]-'a'] += 1;
        }
        sufOdd[i] = tempO;
        sufEven[i] = tempE;
    }
    
    for (int i=0;i<n;i++){
        int even=0, odd=0;
        if (i == 0){
            for (int j=0;j<26;j++){
                even = max(even, sufOdd[1][j]);
            }
            for (int j=0;j<26;j++){
                odd = max(odd, sufEven[1][j]);
            }
            ans = min(ans, (n/2 - even + n/2 - odd));

        }else if (i == n-1){
            for (int j=0;j<26;j++){
                even = max(even, preEven[n-2][j]);
            }
            for (int j=0;j<26;j++){
                odd = max(odd, preOdd[n-2][j]);
            }
            ans = min(ans, (n/2 - even + n/2 - odd));
        }else{

            for (int j=0;j<26;j++){
                even = max(even, preEven[i-1][j]+sufOdd[i+1][j]);
            }
            for (int j=0;j<26;j++){
                odd = max(odd, preOdd[i-1][j]+sufEven[i+1][j]);
            }
            ans = min(ans, (n/2 - even + n/2 - odd));
        }
    }
    cout << ans+1 << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}