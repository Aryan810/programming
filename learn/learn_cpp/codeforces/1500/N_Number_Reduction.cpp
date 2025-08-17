// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
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
struct Node{
    int val;
    struct Node * nxt;
    struct Node * pre;
};
typedef struct Node node;
void solve(){
    

    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
   
    string out;

    int mx = log2(n) + 1;
    vector<vector<int> > stable(n, vector<int>(mx+1));
    for (int i=0;i<n;i++){
        stable[i][0] = s[i]-'0';
    }

    for (int i=1;i<mx;i++){
        for (int j=0;j<=n-(1ll<<i);j++){
            stable[j][i] = min(stable[j][i-1], stable[j+(1ll<<(i-1))][i-1]);
        }
    }

    int i = 0;
    while (i < n){
        int l = i;
        int h = i + k;
        if (h >= n){
            break;
        }
        int mx = log2(k+1);
        if (out.size() == 0){
            int mn = 10;
            int ind = l;
            for (int j=l;j<=h;j++){
                if (s[j] != '0'){
                    if (mn > s[j]-'0'){
                        mn = s[j]-'0';
                        ind = j;
                    }
                }
            }
            while (s[i]-'0' != mn){
                k -= 1;
                i += 1;
            }
            out.push_back(s[i]);
            i += 1;
        }else{
            int mn = min(stable[l][mx], stable[h-(1ll<<mx)+1][mx]);
            while (s[i]-'0' != mn){
                k -= 1;
                i += 1;
            }
            out.push_back(s[i]);
            i += 1;
        }
    }

    cout << out << endl;







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