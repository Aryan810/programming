#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5+10;
vector<array<int, 3> > edges;
int parent[N];
int sz[N];

void make(int v){
	parent[v] = v;
	sz[v] = 1;
}

int find(int v){
	if (v == parent[v]){return v;}
	return parent[v] = find(parent[v]);
}

void Union(int i, int j){
    int p = find(i);
    int q = find(j);
	if (p != q){
		if (sz[p] > sz[q]){
            parent[q] = p;
            sz[p] += sz[q];
        }else{
            parent[p] = q;
            sz[q] += sz[p];
        }
	}
}


void solve(){

    int n;
    cin >> n;
    int m;
    cin >> m;

    edges.clear();
    for (int i=0;i<n;i++){
        make(i+1);
    }
    for (int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(all(edges));
    vector<array<int, 3> > mytree;
    int treeCost = 0;
    for (int i=0;i<edges.size();i++){
        auto curr = edges[i];
        if (find(curr[1]) != find(curr[2])){
            mytree.push_back(curr);
            Union(curr[1], curr[2]);
            treeCost += curr[0];
        }
    }
    cout << endl << treeCost << endl;
    for (auto ele: mytree){
        cout << ele[1] << " " << ele[2] << " " << ele[0] << endl;
    }

    


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

        solve();


    return 0;
}