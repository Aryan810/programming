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
int M = 1e9 + 7;

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans%M * a%M)%M;
        }
        a = (a%M * a%M)%M;
        b >>= 1;
    }
    return ans;
}

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    int x = s.size()-1;

    int y = 0;
    int curr = 1;   
    for (int i=n-1;i>=0;i--){
        if (s[i] == '1'){
            y = (y%M + curr%M)%M;
        }
        curr = (curr%M * 2)%M;
    }

    int z = binexpiter(2, x*(M-2));
    // cout << x << " " << y << " " << z << endl;
    cout << ((x - 1 + ((y%M)*(z%M))%M)%M) << endl;

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