// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modinth;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto n&x : a)
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

// bool comp(vi & a, vi & b){

// }

void solve(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vecnmtor<int> > a(n, vector<int>(m));
    for (int i=0;i<n;i++){
        vector<int> x(m);
        vector<int> out(m);
        for (int j=0;j<m;j++){
            cin >> x[j];
            out[x[j]-1] = j+1;
        }
        v[i] = out;
        a[i] = x;
    }
    sort(all(v));
    // each(ele, v){
    //     each(e, ele){
    //         cout << e << " ";
    //     }cout << endl;
    // }
    vector<int> output(n);
    for (int i=0;i<n;i++){
        auto it1 = lower_bound(all(v), a[i]);
        auto it2 = it1;

        
        // cout << endl;
        // each(ele, *it){
        //     cout << ele << " ";
        // }cout << endl;
        if (it1 != v.begin()){
            it2 -= 1;
        }

        int ans = 0;
        int temp = 0;
        for (int j=0;it1 != v.end() && j<m;j++){
            if ((*it1)[j] == a[i][j]){
                temp += 1;
            }else{
                break;
            }
        }
        ans = max(ans, temp);
        temp = 0;
        for (int j=0;it2 != v.end() && j<m;j++){
            if ((*it2)[j] == a[i][j]){
                temp += 1;
            }else{
                break;
            }
        }
        ans = max(ans, temp);
        if (it1 != v.end()){
            int tmp = 0;
            auto it3 = it1 + 1;
            for (int j=0;it3 != v.end() && j<m;j++){
                if ((*it3)[j] == a[i][j]){
                    tmp += 1;
                }else{
                    break;
                }
            }
            ans = max(ans, tmp);
        }
     
        output[i] = ans;
    }
    each(ele, output){
        cout << ele << " ";
    }cout << endl;

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