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
vector<vector<int> > graph;
vi vis;
vi lev;
void dfs1(int v, int & v1, int & v2, int p){
    vis[v] = 1;
    if (v1 != -1){
        return;
    }
    for (auto & ele: graph[v]){
        if (vis[ele] && ele != p){
            v1 = ele;
            v2 = v;
            continue;
        }
        if (!vis[ele]){
            dfs1(ele, v1, v2, v);
        }
    }
}

int dfs2(int v, int & v1, int & v2, set<int> & lp){
    vis[v] = 1;
    int ret = 0;    
    if (v == v2){
        ret += 1;
    }
    for (auto & ele: graph[v]){
        if (v == v1 && ele == v2){
            continue;
        }
        if (!vis[ele]){
            ret = max(ret, dfs2(ele, v1, v2, lp));
        }   
    }
    if (ret > 0){
        lp.insert(v);
    }
    return ret;
}
int bfs(int v, int & t, int & p, set<int> & lp, int & td){
    queue<int> q;
    q.push(v);
    int tl = -1;
    int pl = -1;
    if (v == t){
        tl = 0;
    }else if (v == p){
        pl = 0;
    }
    while (q.size() > 0){
        int curr = q.front();q.pop();
        // cout << curr << " ";
        vis[curr] = 1;
        for (auto & ele: graph[curr]){
            if (!vis[ele] && lp.find(ele)==lp.end()){
                lev[ele] = lev[curr] + 1;
                if (ele == t){
                    tl = lev[ele];
                }else if (ele == p){
                    pl = lev[ele];
                }
                q.push(ele);
            }
        }
    }
    // cout << "(" << tl << " " << pl << ") ";
    if (tl == -1 && pl == -1){
        return 0;
    }else if (tl == -1 || pl == -1){
        td = max(td, tl);
        if (tl != -1){
            return -2;
        }
        return 0;
    }else{
        if (tl >= pl){
            return -1;
        }else{
            return 1;
        }
    }
}

int bfs2(int p, int tpos){
    queue<int> q;
    q.push(p);
    while (q.size() > 0){
        int curr = q.front();q.pop();
        vis[curr] = 1;
        for (auto & ele: graph[curr]){
            if (!vis[ele]){
                lev[ele] = lev[curr] + 1;
                if (ele == tpos){
                    return lev[ele];
                }
                q.push(ele);
            }
        }
    }
    return 0;
}

void solve(){
    
    int n, a, b;
    cin >> n >> a >> b;
   
    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.assign(n+1, 0);
    lev.assign(n+1, 0);
    for (int i=0;i<n;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (a == b){
        cout << "NO" << endl;return;
    }   
    int v1 = -1;
    int v2 = -1;
    dfs1(1, v1, v2, 0);

    vis.assign(n+1, 0);
    set<int> lp;
    dfs2(v1, v1, v2, lp);
    vis.assign(n+1, 0);
    int td = -1;
    int tpos = -1;
    for (auto & ele: lp){
        int res = bfs(ele, b, a, lp, td);
        if (res == -1){
            cout << "NO" << endl;return;
        }else if (res == 1){
            cout << "YES" << endl;return;
        }else if (res == -2){
            tpos = ele;
        }
    }
    lev.assign(n+1, 0);
    vis.assign(n+1, 0);
    
    int d = bfs2(a, tpos);
    if (d > td){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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