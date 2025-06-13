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

void helper(int n, int x, string & s, string & temp){
    // cout << " here " << n << " " << x << endl;
    int deleted = 0;
    multiset<pair<int, int> > minpos;
    // int offset = j;
    for (int i=0;i<=x;i++){
        minpos.insert({s[i], i});
    }
    int i;
    for (i=0;i<(n-x);i++){
        auto mn = *(minpos.begin());
        int delets = 0;
        while (s[i] != mn.first){
            deleted += 1;
            delets += 1;
            minpos.erase({s[i], i});
            i += 1;
            // minpos.insert({s[i+x + offset], i+x});
        }
        temp.push_back(s[i]);
        minpos.erase({s[i], i});
        x -= delets;
        if (i+1 < n-x){
            minpos.insert({s[i+x+1], i+x+1});
        }
    }
    if (x == 0){
        while (i < s.size()){
            temp.push_back(s[i]);
            i += 1;
        }
        return;
    }
    if (x <= 0){return;}
    // if (n-i > x-deleted){
    //     helper(x, i+j, x-deleted, s, temp);
    // }
}

void solve(){

    string s;
    cin >> s;
    int n = s.size();
    int pos;cin >> pos;
    // if (n == 1 && pos == 1){
    //     cout << s[0];return;
    // }
    int b = (n*(n+1))/2 - pos + 1;
    int bk = 0;
    for (int i=0;i<=n;i++){
        if ((i*(i+1))/2 >= b){
            bk = i;
            break;
        }
    }

    int x = n-bk;
    int inpos = pos - ((n*(n+1))/2 - (bk*(bk+1))/2) - 1;
    string temp;
    helper(n, x, s, temp);
    cout << temp[inpos];
    

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