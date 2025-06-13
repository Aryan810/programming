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

    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, vector<int> > ind;
    rep(i, n){
        int x;
        cin >> x;
        ind[x].push_back(i);
        a[i] = x;
    }

    vector<int> dp(n+1, 1e15);
    vector<pair<int, int> > lastm;
    vector<pair<int, int> > lastM;
    pair<int, int> mn = {-1, 1e18};
    for (int i=0;i<n;i++){
        if (a[i] == k){
            // last.push_back(i);
            dp[i] = 0;
            if (mn.second > dp[i]-i){
                mn.second = dp[i]-i;
                mn.first = i;
            }
            lastm.push_back(mn);
        }
    }
    mn = {-1ll, 1e18};
    for (int i=n-1;i>=0;i--){
        if (a[i] == k){
            if (mn.second > dp[i]+i){
                mn.second = dp[i]+i;
                mn.first = i;
            }
            lastM.push_back(mn);
        }
    }
    sort(all(lastM));
    vector<pair<int, int> > tempm;
    vector<pair<int, int> > tempM;
    for (int i=k-1;i>=1;i--){
        mn = {-1, 1e18};
        tempm.clear();
        tempM.clear();
        for (auto j: ind[i]){
            auto f = lower_bound(all(lastm), make_pair(j, -1ll));
            auto s = lower_bound(all(lastM), make_pair(j, -1ll));
            dp[j] = 1e18;
            if (s != lastM.end()){
                dp[j] = min(dp[j], s->second - j);
            }
            if (f != lastm.begin()){
                dp[j] = min(dp[j], (f-1)->second + j);
            }
            if (mn.second > dp[j]-j){
                mn.second = dp[j]-j;
                mn.first = j;
            }
            tempm.push_back(mn);
        }
        mn = {-1, 1e18};
        for (int l=(ind[i].size()-1);l>=0;l--){
            int j = ind[i][l];
            if (mn.second > dp[j] + j){
                mn.second = dp[j]+j;
                mn.first = j;
            }
            tempM.push_back(mn);
        }
        sort(all(tempM));
        lastm = tempm;
        lastM = tempM;
    }

    for (int i=0;i<n;i++){
        if (a[i] == 1){
            cout << dp[i] << " ";
        }else{
            auto f = lower_bound(all(lastm), make_pair(i, -1ll));
            auto s = lower_bound(all(lastM), make_pair(i, -1ll));
            int ans = 1e18;
            if (s != lastM.end()){
                ans = min(ans, s->second - i);
            }
            if (f != lastm.begin()){
                ans = min(ans, (f-1)->second + i);
            }
            cout << ans << " ";
        }
    }cout << endl;



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