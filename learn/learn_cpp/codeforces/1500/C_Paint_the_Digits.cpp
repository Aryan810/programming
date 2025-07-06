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
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i=1;i<=9;i++){
        set<int> one, two;
        vector<int> sames;
        int lst = -1;
        for (int j=0;j<n;j++){
            if (s[j]-'0' < i){
                lst = j;
                one.insert(j);
            }else if (s[j]-'0' == i){
                sames.push_back(j);
            }else{
                two.insert(j);
            }
        }

        for (int j=0;j<sames.size();j++){
            if (sames[j] > lst){
                one.insert(sames[j]);
            }else{
                two.insert(sames[j]);
            }
        }
        
        int last = -1;
        bool poss = 1;
        auto it1 = one.begin();
        auto it2 = two.begin();
        for (int j=0;j<n;j++){
            int curr;
            if (j < one.size()){
                curr = s[*(it1++)]-'0';
            }else{
                curr = s[*(it2++)]-'0';
            }
            if (last > curr){
                poss = 0;break;
            }
            last = curr;
        }

        if (poss){
            for (int j=0;j<n;j++){
                if (one.find(j) != one.end()){
                    cout << 1;
                }else{
                    cout << 2;
                }
            }cout << endl;
            return;
        }
    }
    cout << "-" << endl;
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