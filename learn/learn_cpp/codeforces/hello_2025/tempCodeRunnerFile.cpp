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

int giveVal(string s){
    int x = 1;
    int ans = 0;
    for (int i=0;i<s.size();i++){
        ans += (s[i]-'0')*x;
        x = x << 1;
    }
    return ans;
}

void solve(){

    int l, r;
    cin >> l >> r;
    string a="", b="";
    int x = 1;
    for (int i=0;i<31;i++){
        if (x&l){
            a.push_back('1');
        }else{
            a.push_back('0');
        }
        x = x << 1;
    }
    x = 1;
    for (int i=0;i<31;i++){
        if (x&r){
            b.push_back('1');
        }else{
            b.push_back('0');
        }
        x = x << 1;
    }

    int aa=0, bb=0, cc=0;
    int i = a.size()-1;
    while (a[i] == b[i]){
        if (a[i] != '0'){
            aa += 1<<i;
            bb += 1<<i;
            cc += 1<<i;
        }
        i--;
    }
    // a->l b->r
    int diff = 0;
    int sz = 0;
    int j = i;
    while (i >= 0 && diff <= 1){
        diff = 2*(diff) + (b[i]-a[i]);
        i -= 1;
        sz += 1;
    }
    // cout << i << " " << diff << endl;
    string y = a.substr(i+1, sz);
    string z = b.substr(i+1, sz);
    int p = (giveVal(y)+giveVal(z))/2;
    bb += p*(1<<(i+1)) ;
    aa = l;
    cc = r;
    while (i >= 0){
        if (a[i] == b[i]){
            if (a[i] == '0'){
                bb += 1<<i;
            }
        }
        i--;
    }
    cout << aa << " " << bb << " " << cc << endl;





    
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