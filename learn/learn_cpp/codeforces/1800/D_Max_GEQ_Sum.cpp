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
const int INF = 1e15;

class s_table{
    public:
        vvi stable;
        int n;
        vi arr;
        int mx;
        int DEF;
        // default comparator.
        int (*comp)(int a, int b) = [](int a, int b){return max(a, b);};
        void calc_table(){
            for (int i=0;i<n;i++){
                stable[i][0] = arr[i];
            }
            for (int i=1;i<=mx;i++){
                for (int j=0;j<=(n-(1ll<<i));j++){
                    stable[j][i] = comp(stable[j][i-1], stable[j+(1ll<<(i-1))][i-1]);
                }
            }
        }
        int find(int l, int h){
            if (h < l){
                return this->DEF;
            }
            int x = log2(h-l+1);
            int f = stable[l][x];
            int s = stable[h-(1ll<<x)+1][x];
            return this->comp(f, s);
        }
        s_table(int n, vi & arr, int DEF = 0, int (*comp)(int a, int b) = NULL){
            this->arr = arr;
            this->n = n;
            if (comp != NULL){
                this->comp = comp;
            }
            this->mx = log2(n);
            this->DEF = DEF;
            stable.assign(n+1, vector<int>(mx+1, DEF));
            calc_table();
        }
};


int comp(int a, int b){
    return max(a, b);
}

int comp1(int a, int b){
    return min(a, b);
}
void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    vector<pi> eles;
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        eles.push_back({x, i});
    }


    vi cum(n+1);
    cum[0] = 0;
    rep(i, n){
        cum[i+1] = cum[i] + a[i];
    }

    sort(rall(eles));
    
    stack<pi> ms;
    vi right(n);
    vi left(n);
    ms.push({INF, -1});

    for (int i=0;i<n;i++){
        while (ms.top().first <= a[i]){
            ms.pop();
        }

        left[i] = ms.top().second;
        ms.push({a[i], i});
    }

    while (ms.size() > 0){
        ms.pop();
    }

    ms.push({INF, n});
    for (int i=n-1;i>=0;i--){
        while (ms.top().first <= a[i]){
            ms.pop();
        }

        right[i] = ms.top().second;
        ms.push({a[i], i});
    }
    s_table sg(n+1, cum, -1e18, comp);
    s_table sgm(n+1, cum, 1e18, comp1);
    // for (auto & ele: cum){
    //     cout << ele << " ";
    // }cout << endl;
    for (int i=0;i<n;i++){
        int r = right[i];
        int l = left[i];
        // cout << a[i] << " -> " << l << " " << r << endl;
        int p1 = i+1, q1 = r;
        int p2 = l+1, q2 = i;

        int mr = sg.find(p1, q1);
        int ml = sgm.find(p2, q2);

        int val = mr - ml;
        
        // cout << a[i] << " " << val << endl;
        // cout << ml << " " << mr << endl;
        if (a[i] < val){
            cout << "NO" << endl;return;
        }
    }

    cout << "YES" << endl;

    

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