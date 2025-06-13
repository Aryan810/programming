#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// DSU
const int N = 1e5+10;
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
    int n, m;cin >> n >> m;
    string str;
    cin >> str;
    
    vector<array<int, 3> > f, s, t;
    array<int, 3> fa = {0, 0, 0};
    array<int, 3> sa = {0, 0, 0};
    array<int, 3> ta = {0, 0, 0};
    f.push_back(fa);
    s.push_back(sa);
    t.push_back(ta);
    for (int i=0;i<n;i++){
        if (i%3 == 0){
            fa[str[i]-'a'] += 1;
        }else if ((i+1)%3 == 0){
            sa[str[i]-'a'] += 1;
        }else{
            ta[str[i]-'a'] += 1;
        }
        f.push_back(fa);
        s.push_back(sa);
        t.push_back(ta);
    }
    // for (auto ele: s){
    //     cout << ele[0] << " ";
    // }cout << endl;

    for (int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        if (r-l == 1){
            if (str[l-1] == str[r-1]){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
            continue;
        }else if (r == l){
            cout << 0 << endl;continue;
        }
        l -= 1;
        r -= 1;
        int ans = 1e18;
        int nf, ns, nt;
        if (l%3 == 0){
            nf = (r-l+3)/3;
            ns = (r-l+2)/3;
            nt = (r-l+1)/3;
            int sm = nf+ns+nt;
            // 1
            int a = f[r+1][0] - f[l][0];
            int b = s[r+1][1] - s[l+2][1];
            int c = t[r+1][2] - t[l+1][2];
            ans = min(ans, sm -a-b-c);
            // 2
            a = s[r+1][0] - s[l+2][0];
            b = t[r+1][1] - t[l+1][1];
            c = f[r+1][2] - f[l][2];
            ans = min(ans, sm -a-b-c);
            // 3
            a = f[r+1][0] - f[l][0];
            b = t[r+1][1] - t[l+1][1];
            c = s[r+1][2] - s[l+2][2];
            ans = min(ans, sm -a-b-c);
            // 4
            a = s[r+1][0] - s[l+2][0];
            b = f[r+1][1] - f[l][1];
            c = t[r+1][2] - t[l+1][2];
            ans = min(ans, sm -a-b-c);
            // 5
            a = t[r+1][0] - t[l+1][0];
            b = s[r+1][1] - s[l+2][1];
            c = f[r+1][2] - f[l][2];
            // cout << a << " " << b << " " << c << endl;
            // cout << "HERE: " << sm-a-b-c << endl;
            ans = min(ans, sm -a-b-c);
            // 6
            a = t[r+1][0] - t[l+1][0];
            b = f[r+1][1] - f[l][1];
            c = s[r+1][2] - s[l+2][2];
            ans = min(ans, sm -a-b-c);
            
        }else if ((l+2)%3 == 0){
            nf = (r-l+1)/3;
            ns = (r-l+3)/3;
            nt = (r-l+2)/3;
            int sm = nf+ns+nt;
            // 1
            int a = f[r+1][0] - f[l+2][0];
            int b = s[r+1][1] - s[l+1][1];
            int c = t[r+1][2] - t[l][2];
            ans = min(ans, sm -a-b-c);
            // 2
            a = s[r+1][0] - s[l+1][0];
            b = t[r+1][1] - t[l][1];
            c = f[r+1][2] - f[l+2][2];
            ans = min(ans, sm -a-b-c);
            // 3
            a = f[r+1][0] - f[l+2][0];
            b = t[r+1][1] - t[l][1];
            c = s[r+1][2] - s[l+1][2];
            ans = min(ans, sm -a-b-c);
            // 4
            a = s[r+1][0] - s[l+1][0];
            b = f[r+1][1] - f[l+2][1];
            c = t[r+1][2] - t[l][2];
            ans = min(ans, sm -a-b-c);
            // 5
            a = t[r+1][0] - t[l][0];
            b = s[r+1][1] - s[l+1][1];
            c = f[r+1][2] - f[l+2][2];
            ans = min(ans, sm -a-b-c);
            // 6
            a = t[r+1][0] - t[l][0];
            b = f[r+1][1] - f[l+2][1];
            c = s[r+1][2] - s[l+1][2];
            ans = min(ans, sm -a-b-c);
        }else{
            nf = (r-l+2)/3;
            ns = (r-l+1)/3;
            nt = (r-l+3)/3;
            int sm = nf+ns+nt;
            // 1
            int a = f[r+1][0] - f[l+1][0];
            int b = s[r+1][1] - s[l][1];
            int c = t[r+1][2] - t[l+2][2];
            ans = min(ans, sm -a-b-c);
            // 2
            a = s[r+1][0] - s[l][0];
            b = t[r+1][1] - t[l+2][1];
            c = f[r+1][2] - f[l+1][2];
            ans = min(ans, sm -a-b-c);
            // 3
            a = f[r+1][0] - f[l+1][0];
            b = t[r+1][1] - t[l+2][1];
            c = s[r+1][2] - s[l][2];
            ans = min(ans, sm -a-b-c);
            // 4
            a = s[r+1][0] - s[l][0];
            b = f[r+1][1] - f[l+1][1];
            c = t[r+1][2] - t[l+2][2];
            ans = min(ans, sm -a-b-c);
            // 5
            a = t[r+1][0] - t[l+2][0];
            b = s[r+1][1] - s[l][1];
            c = f[r+1][2] - f[l+1][2];
            ans = min(ans, sm -a-b-c);
            // 6
            a = t[r+1][0] - t[l+2][0];
            b = f[r+1][1] - f[l+1][1];
            c = s[r+1][2] - s[l][2];
            ans = min(ans, sm -a-b-c);
        }
        cout << ans << endl;
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int test;
    // cin >> test;

    // while(test--){
        solve();
    
    return 0;
}