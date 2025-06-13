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

struct dsu{
    int n;
    vector<int> parent, set_size;
    dsu(int n){
        this->n = n;

        parent.resize(n);

        set_size.resize(n);

        for (int i = 0; i < n; i++){

            parent[i] = i;

            set_size[i] = 1;
        }
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent [v] = find (parent [v]);
    }
    void set_union (int a, int b){
        a = find(a);
        b = find (b);
        if(a != b){
            if(set_size[a] < set_size [b]){
                swap (a, b) ;
            }
            parent[b] = a;
            set_size[a] += set_size[b];
        }   
    }
};

void dfs(int )

void solve(){

    int n, m;
    cin >> n >> m;

    vector<vector<int> > grid(n, vector<int>(m));
    for (int i=0;i<n;i++){
        string s;cin >> s;
        for (int j=0;j<s.size();j++){
            grid[i][j] = s[j];
        }
    }

    vector<vector<int> > outs(n, vector<int>(m, 0));

    int t = 1;
    while (t--){
        vector<vector<int> > vis(n, vector<int>(m, 0));
        int done = 0;
        pair<int, int> st = {0, 0};
        vis[0][0] = 1;
        int face = 0;
        while (done < 2*m*n){
            // cout << st.first << " " << st.second << endl;
            if (grid[st.first][st.second] == '?'){
                int u=1, d=1, r=1, l=1;
                if (st.first == 0 || outs[st.first - 1][st.second]){
                    u = 0;
                }
                if (st.second == 0 || outs[st.first][st.second - 1]){
                    l = 0;
                }
                if (st.second == m-1 || outs[st.first][st.second + 1]){
                    r = 0;
                }
                if (st.first == n-1 || outs[st.first + 1][st.second]){
                    d = 0;
                }
                if ((u+l+r+d) == 0){
                    outs[st.first][st.second] = 1;
                }
            }else{
                    // cout << "HERE " << i << " " << j << " " << char(grid[st.first][st.second]) << endl;
                    switch (char(grid[st.first][st.second]))
                    {
                    case 'U':
                        if (st.first == 0 || outs[st.first - 1][st.second]){
                            outs[st.first][st.second] = 1;
                            // cout << "NOW" << endl;
                        }
                        break;
                    case 'L':
                        if (st.second == 0 || outs[st.first][st.second - 1]){
                            outs[st.first][st.second] = 1;
                        }
                        break;
                    case 'D':
                        if (st.first == n-1 || outs[st.first + 1][st.second]){
                            // cout << "WOW" << endl;
                            outs[st.first][st.second] = 1;
                        }
                        break;
                    case 'R':
                        if (st.second == m-1 || outs[st.first][st.second + 1]){
                            outs[st.first][st.second] = 1;
                        }
                        break;
                    default:
                        break;
                    }
                }
            switch (face)
            {
            case 0:
                if (st.second + 1 >= m || vis[st.first][st.second+1]){
                    face = (face + 1)%4;
                    done += 1;
                }else{
                    st.second += 1;
                    vis[st.first][st.second] = 1;
                }
                break;
            case 1:
                if (st.first + 1 >= n || vis[st.first+1][st.second]){
                    face = (face + 1)%4;
                    done += 1;
                }else{
                    st.first += 1;
                    vis[st.first][st.second] = 1;
                }
                break;
            case 2:
                if (st.second - 1 < 0 || vis[st.first][st.second-1]){
                    face = (face + 1)%4;
                    done += 1;
                }else{
                    st.second -= 1;
                    vis[st.first][st.second] = 1;
                }  
                break;
            case 3:
                if (st.first - 1 < 0 || vis[st.first-1][st.second]){
                    face = (face + 1)%4;
                    done += 1;
                }else{
                    st.first -= 1;
                    vis[st.first][st.second] = 1;
                }
                break;
            default:
                break;
            }
        }
    }


    int ans = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            ans += 1 - outs[i][j];
        }
    }
    cout << ans << endl;
    
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}