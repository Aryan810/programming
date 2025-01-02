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

vi oper(vi s, int l, int r){
    vi out;
    for (int i=r+1;i<s.size();i++){
        out.push_back(s[i]);
    }
    for (int i=r;i>=l;i--){
        out.push_back(s[i]);
    }
    for (int i=0;i<l;i++){
        out.push_back(s[i]);
    }
    return out;
}

void ifmaxatend(vi & a, set<vi> & possibles){
    int r = a.size() - 1;
    for (int i=0;i<=r;i++){
        possibles.insert(oper(a, i, r));
    }
}

void solve(){

    int n;
    cin >> n;

    vi a(n);
    rep(i, n)cin >> a[i];
    set<vector<int> > possibles;
    if (max_element(all(a)) == a.begin()){
        int r = (max_element(a.begin()+1, a.end()) - a.begin())-1;
        for (int i=0;i<=r;i++){
            possibles.insert(oper(a, i, r));
        }
        if (max_element(a.begin()+1, a.end()) == a.end()-1){
            ifmaxatend(a, possibles);
        }

    }else{
        if (max_element(all(a)) == a.end()-1){
            ifmaxatend(a, possibles);
        }
        int r = (max_element(all(a)) - a.begin())-1;
        for (int i=0;i<=r;i++){
            possibles.insert(oper(a, i, r));
        }
    }
    a = *(--possibles.end());
    for (auto ele: a){
        cout << ele << " ";
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