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

void solve(){

    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vector<vector<int> > grid(n, vector<int>(m, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    // for (auto ele: grid){
    //     for (auto e: ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }cout << endl;
    int ans = 1e18;
    for (int i=0;i<n-k+1;i++){
        int temp = 0;
        for (int j=i;j<k+i;j++){
            vector<int> dp(m);
            dp[0] = 1;
            multiset<int> smallest_in_last_d;
            smallest_in_last_d.insert(1);
            queue<int> q;
            q.push(1);
            for (int l=1;l<m;l++){
                int smallest = *(smallest_in_last_d.begin());
                // cout << l << " " << q.front() << " " << smallest << endl;
                dp[l] = smallest + grid[j][l] + 1;
                if (q.size() < d+1){
                    q.push(dp[l]);
                    smallest_in_last_d.insert(dp[l]);
                }else{
                    q.push(dp[l]);
                    smallest_in_last_d.erase(smallest_in_last_d.lower_bound(q.front()));
                    smallest_in_last_d.insert(dp[l]);
                    q.pop();
                }
            //     cout << "QUEUE: ";
            // for (int i=0;i<q.size();i++){
            //     cout << q.front() << " ";
            //     q.push(q.front());
            //     q.pop();
            // }cout << endl;
            }
            temp += dp[m-1];
            
        }
        ans = min(temp, ans);
    }
    cout << ans << endl;
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