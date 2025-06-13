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
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int dp[3001][3001];
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int go(string & s, string & t, int i, int j, string temp, string & out){
    if (dp[i][j] != -1){
        return dp[i][j];
    }

    if (i >= s.size() || j >= t.size()){
        if (temp.size() > out.size()){out = temp;}
        return 0;
    }

    int ret = 0;
    if (s[i] != t[j]){
        ret = max(ret, go(s, t, i+1, j, temp, out));
        ret = max(ret, go(s, t, i, j+1, temp, out));
    }else{
        ret = max(ret, 1 + go(s, t, i+1, j+1, temp + s[i], out));
    }
    return dp[i][j] = ret;
}

void solve(){

    string s;
    string t;
    cin >> s >> t;

    for (int i=0;i<3001;i++){
        for (int j=0;j<3001;j++){
            dp[i][j] = -1;
        }
    }
    string out = "";
    go(s, t, 0, 0, "", out);
    cout << out << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 
    solve();


    return 0;
}