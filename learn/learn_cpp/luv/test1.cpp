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
void dfs(int v, vector<int> & subTreeSum, vector<int> & visited, vector<vector<int> > & graph){
    visited[v] = 1;
    int sm = v;
    for (int i=0;i<graph[v].size();i++){
        if (!visited[graph[v][i]]){
            dfs(graph[v][i], subTreeSum, visited, graph);
            sm += subTreeSum[graph[v][i]];
        }
    }
    subTreeSum[v] = sm;
}

void solve(){
    int n;cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    vector<vector<int> > B(n-1, vector<int>(2));
    rep(i, n-1) cin >> B[i][0] >> B[i][1];
    int M = 1e9+7;
    int n1 = A.size();
    long long sm = 0;
    for (auto ele: A){
        sm += ele;
    }
    vector<int> subTreeSum(n1+1, 0);
    vector<int> visited(n1+1, 0);
    vector<vector<int> > graph(n1+1);
    for (int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    // cout << "HERE" << endl;
    dfs(1, subTreeSum, visited, graph);
    for (auto ele: subTreeSum){
        cout << ele << " ";
    }cout << endl;
    long long ans = 0;
    for (int i=2;i<=n1;i++){
        long long sm1 = subTreeSum[i];
        long long sm2 = sm - subTreeSum[i];
        cout << sm1*sm2 << " i: " << i << endl;
        ans = max(ans, sm1*sm2);
    }
    cout << ans%M << endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);



        solve();


    return 0;
}