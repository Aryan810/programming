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

    int n, m, x;cin >> n >> m >> x;
    multiset<pair<int, int> > s;
    vi a(n);
    rep(i, n) cin >> a[i];
    map<int, vector<int> >  num;
    auto b = a;
    for (int i=0;i<m;i++){
        s.insert({a[i], i});
        num[a[i]].push_back(i);
    }
    for (int i=m;i<n;i++){
        auto it = *(s.begin());
        s.erase(s.begin());
        it.first += a[i];
        num[a[i]].push_back(it.second);
        s.insert(it);
    }
    auto f = s.begin();
    auto l = ++s.begin();
    while (l != s.end()){
        if (l->first - f->first > x){
            cout << "NO" << endl;
            return;
        }
        l++;f++;
    }
    cout << "YES" << endl;
    for (auto ele: b){
        cout << num[ele].back()+1 << " ";
        num[ele].pop_back();
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