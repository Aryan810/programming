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

struct dsu{
    int n;
    vector<int> parent, set_size;
    dsu(int n){
        this->n = n;

        parent.resize(n);

        set_size.resize(n);

        for (int i = 0; i < n; i++){

            parent[i] = i;

            set_size[i] = 1;
        }
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent [v] = find (parent [v]);
    }
    void set_union (int a, int b){
        a = find(a);
        b = find (b);
        if(a != b){
            if(set_size[a] < set_size [b]){
                swap (a, b) ;
            }
            parent[b] = a;
            set_size[a] += set_size[b];
        }   
    }
};

void solve(){

    int n;
    cin >> n;
    int a, b, c;
    int ans = 0;
    a = n;
    b = n;
    if (n&1){
        ans += n/2;
        c = 1;
    }else{
        ans += n/2;
        c = 0;
    }

    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(n+1, vector<int>(2, 0)));
    dp[0][0][0] = 0;
    for (int i=0;i<=n;i++){ // 18
        for (int j=0;j<=n;j++){ // 21
            for (int k=0;k<=1;k++){ // 25
                if (i == 0 && (j == 0 && k == 0)){
                    continue;
                }
                int temp = 1e18;
                if (j >= 2){
                    temp = min(temp, dp[i][j-2][k] + 1);
                }
                if (i >= 3){
                    temp = min(temp, dp[i-3][j][k] + 1);
                }
                if (i >= 2 && j >= 1){
                    temp = min(temp, dp[i-2][j-1][k] + 1);
                }
                if (j >= 1 && k >= 1){
                    temp = min(temp, dp[i][j-1][k-1] + 1);
                }
                if (j >= 2 && i >= 1){
                    temp = min(temp, dp[i-1][j-2][k] + 1);
                }
                if (i >= 1 && k >= 1){
                    temp = min(temp, dp[i-1][j][k-1] + 1);
                }
                if (i >= 1){
                    temp = min(temp, dp[i-1][j][k] + 1);
                }
                if (j >= 1){
                    temp = min(temp, dp[i][j-1][k] + 1);
                }
                if (k >= 1){
                    temp = min(temp, dp[i][j][k-1] + 1);
                }
                // cout << "TEMP: " << temp << endl;
                dp[i][j][k] = temp;
            }
        }
    }

    cout << dp[a][b][c] + ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}