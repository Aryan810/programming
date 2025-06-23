// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve(){
    
    int n;
    cin >> n;
    if (n == 1){
        cout << 1e4 - 1 << endl;
        for (int i=2;i<=10000;i++){
            cout << i << " " << i-1 << endl;
        }
        return;
    }
    string s = to_string(n);
    vector<pair<int, int> > out;    
    for (int x=0;x<=7;x++){
        int fl = (x-x%s.size())/s.size();
        int pa = x%s.size();
        int num = 0;
        int a, b;
        for (int i=0;i<x;i++){
            num += (s[i%s.size()]-'0')*(binexpiter(10, x-1-i));
        }
        if ((num-x)%(n-s.size()) == 0){
            a = (num-x)/(n-s.size());
            b = (s.size()*a-x);
            if ((a > 0 && a <= 10000) && (b > 0 && b <= 10000)){
                out.push_back({a, b});
            }
        }
    }
    cout << out.size() << endl;

    for (auto ele: out){
        cout << ele.first << " " << ele.second << endl;
    }



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}