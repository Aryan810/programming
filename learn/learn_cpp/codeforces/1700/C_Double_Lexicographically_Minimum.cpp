// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    string s;
    cin >> s;

    vector<char> a(s.size());
    vector<int> cnt(200, 0);
    for (int i=0;i<s.size();i++){
        a[i] = s[i];
        cnt[a[i]] += 1;
    }
    int n = a.size();
    char mx = mxv(a);
    sort(all(a));
    // for (int i=0;i<n;i++){
    //     cout << cnt[a[i]] << " ";
    // }cout << endl;
    int i = 0;
    vector<char> temp;
    char f = -1;
    char l = -1;
    while (i<n){
        // cout << i << " " << cnt[a[i]] << endl;
        if (f != -1){
            if (a[i] == mx){
                if (cnt[a[i]]&1){
                    for (int j=0;j<cnt[a[i]]/2;j++){
                        temp.push_back(a[i]);
                    }
                    l = a[i];
                    i += cnt[a[i]];
                }else{
                    for (int j=0;j<(cnt[a[i]])/2;j++){
                        temp.push_back(a[i]);
                    }
                    // l = a[i];
                    i += (cnt[a[i]]);
                }
            }else{
                l = a[i];
                i += 1;
            }
            break;
        }else{
            if (cnt[a[i]]%2 == 0){
                for (int j=0;j<cnt[a[i]]/2;j++){
                    temp.push_back(a[i]);
                }
                i += cnt[a[i]];
            }else{
                if (f == -1){
                    for (int j=0;j<cnt[a[i]]/2;j++){
                        temp.push_back(a[i]);
                    }
                    f = a[i];
                    i += cnt[a[i]];
                }
            }
        }
        
    }





    for (int j=0;j<temp.size();j++){
        cout << temp[j];
    }
    
    if (f != -1 && l == -1){
        cout << f;
        while (i < n){
            cout << a[i];
            i += 1;
        }
    }else if (f == -1 && l == -1){
        while (i < n){
            cout << a[i];
            i += 1;
        }
    }else{
        cout << l;
        while (i < n){
            cout << a[i];
            i += 1;
        }
        cout << f;
    }

    for (int j=temp.size()-1;j>=0;j--){
        cout << temp[j];
    }
    cout << endl;
   



}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}