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
vvi grid;
vvi mlev;
vvi lev;
pi a;
vector<pi> mon;
int n, m;
const int INF = 1e15;
void bfs(){
    queue<pi> q;
    for (auto & ele: mon){
        q.push(ele);
        mlev[ele.first][ele.second] = 0;
    }
    vector<pi> poss = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    vector<char> dir = {
        'U', 'D', 'L', 'R'
    };
    while (q.size() > 0){
        auto curr = q.front();
        q.pop();
        for (auto & ele: poss){
            pi nxt = {ele.first + curr.first, ele.second + curr.second};
            if ((nxt.first >= 0 && nxt.first < n) && (nxt.second >= 0 && nxt.second < m) && grid[nxt.first][nxt.second] && mlev[nxt.first][nxt.second] == INF){
                mlev[nxt.first][nxt.second] = mlev[curr.first][curr.second] + 1;
                q.push(nxt);
            }
        }
    }

    q.push(a);
    lev[a.first][a.second] = 0;
    pi boundry = {-1, -1};
    while (q.size() > 0){
        auto curr = q.front();
        if (curr.first == 0 || curr.first == n-1 || curr.second == 0 || curr.second == m-1){
            boundry = curr;
        }
        q.pop();
        for (auto & ele: poss){
            pi nxt = {ele.first + curr.first, ele.second + curr.second};
            if ((nxt.first >= 0 && nxt.first < n) && (nxt.second >= 0 && nxt.second < m) && grid[nxt.first][nxt.second] && lev[nxt.first][nxt.second] == INF){
                if (lev[curr.first][curr.second] + 1 < mlev[nxt.first][nxt.second]){
                    lev[nxt.first][nxt.second] = lev[curr.first][curr.second] + 1;
                    q.push(nxt);
                }
            }
        }
    }

    if (boundry == make_pair(-1ll, -1ll)){
        cout << "NO" << endl;return;
    }

    cout << "YES" << endl;
    string out;
    pi curr = boundry;
    while (lev[curr.first][curr.second] > 0){
        for (int i=0;i<poss.size();i++){
            auto & ele = poss[i];
            pi nxt = {ele.first + curr.first, ele.second + curr.second};
            if ((nxt.first >= 0 && nxt.first < n) && (nxt.second >= 0 && nxt.second < m) && ((grid[nxt.first][nxt.second]) && lev[nxt.first][nxt.second] == lev[curr.first][curr.second] - 1)){
                curr = nxt;
                out.push_back(dir[i]);
                break;
            }
        }
    }

    reverse(all(out));
    cout << out.size() << endl;
    cout << out << endl;

}

void solve(){
    cin >> n >> m;
    grid.assign(n, vector<int>(m, INF));
    mlev.assign(n, vector<int>(m, INF));
    lev.assign(n, vector<int>(m, INF));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;
            cin >> c;
            if (c == 'A'){
                a = {i, j};
            }else if (c == 'M'){
                mon.push_back({i, j});
            }
            if (c == '#'){
                grid[i][j] = 0;
            }else{
                grid[i][j] = 1;
            }
        }
    }

    bfs();
    

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