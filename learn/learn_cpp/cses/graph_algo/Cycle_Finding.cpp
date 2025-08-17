// #include<atcoder/modint>
#include<bits/stdc++.h>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
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
const int INF = 1e18;
void solve(){
    
    int n, m;
    cin >> n >> m;
    vector<array<int, 3> > edges(m);
    for (int i=0;i<m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = {x, y, w};
    }
  
    vi lev(n+1, INF);
    for (int i=1;i<=n;i++){
        edges.push_back({0, i, 0});
    }
    lev[0] = 0;
    vi relaxant(n+1, -1);
    for (int i=0;i<n-1;i++){
        for (int j=0;j<edges.size();j++){
            auto curr = edges[j];
            if (lev[curr[0]] + curr[2] < lev[curr[1]]){
                relaxant[curr[1]] = curr[0];
                lev[curr[1]] = lev[curr[0]] + curr[2];
            }
        }
    }
    
    vector<int> eles;
    int f = -1;
    for (int j=0;j<edges.size();j++){
        auto curr = edges[j];
        if (lev[curr[0]] + curr[2] < lev[curr[1]]){
            f = curr[1];
            break;
            lev[curr[1]] = lev[curr[0]] + curr[2];
        }
    }


    if (f == -1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        set<int> done;
        int curr = f;
        while (done.find(curr) == done.end()){
            // cout << curr << " ";
            done.insert(curr);
            curr = relaxant[curr];
        }
        done.clear();
        stack<int> st;
        while (done.find(curr) == done.end()){
            st.push(curr);
            done.insert(curr);
            curr = relaxant[curr];
        }st.push(curr);
        while (st.size() > 0){
            cout << st.top() << " ";st.pop();
        }cout << endl;
    }

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}