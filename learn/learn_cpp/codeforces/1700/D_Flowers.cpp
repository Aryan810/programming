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
const int M = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int k;
const int N = 1e5+1;
vector<int> ans(N, 0);
vector<int> cum(N+1, 0);


struct Node {
    int val;
    struct Node * nxt;
    struct Node * prev;
};
typedef struct Node Node;

void solve(){
    
    int a, b;
    cin >> a >> b;

    cout << (cum[b+1]-cum[a]+M)%M << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;
    cin >> k;

    Node lst[k];
    Node * f = &lst[0];
    Node * l = &lst[k-1];

    for (int i=0;i<k;i++){
        lst[i].nxt = &(lst[(i+1)%k]);
        lst[i].prev = &(lst[(i-1+k)%k]);
        lst[i].val = 0;
    }
    lst[0].val = 1;
    ans[0] = 0;
    cum[0] = 0;
    int sm = 0;
    for (int i=1;i<N;i++){
        int x = (f->val + l->val)%M;
        l->val = x;
        f = l;
        l = l->prev;
        ans[i] = x;
        sm += x;
        sm %= M;
        cum[i+1] = sm;
    }

    while(test--){
        solve();
    }

    return 0;
}