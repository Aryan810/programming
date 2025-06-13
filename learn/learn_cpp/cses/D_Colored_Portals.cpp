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

void solve(){

    int n, q;
    cin >> n >> q;
    vector<vector<vector<int> > > dta(4, vector<vector<int> >(4));
    vector<set<int> > v(4);
    vector<pair<int, int> > a(n+1);
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        switch (s[0])
        {
        case 'B':
            s[0] = 'A';
            break;
        case 'R':
            s[0] = 'B';
            break;
        case 'G':
            s[0] = 'C';
            break;
        case 'Y':
            s[0] = 'D';
            break;
        default:
            break;
        }
        switch (s[1])
        {
        case 'B':
            s[1] = 'A';
            break;
        case 'R':
            s[1] = 'B';
            break;
        case 'G':
            s[1] = 'C';
            break;
        case 'Y':
            s[1] = 'D';
            break;
        default:
            break;
        }
        dta[s[0]-'A'][s[1]-'A'].push_back(i);
        dta[s[1]-'A'][s[0]-'A'].push_back(i);
        a[i] = {s[0]-'A', s[1]-'A'};
        v[s[0]-'A'].insert(i);
        v[s[1]-'A'].insert(i);
    }

    for (auto & ele: dta){
        for (auto &e: ele){
            sort(all(e));
        }
    }

    for (int i=0;i<q;i++){  
        int x, y;
        cin >> x >> y;
        if (v[a[x].first].find(y) != v[a[x].first].end() || v[a[x].second].find(y) != v[a[x].second].end()){
            cout << abs(x-y) << endl;continue;
        }
        vector<pair<int, int> > poss = {
            {a[x].first, a[y].first}, {a[x].first, a[y].second}, {a[x].second, a[y].second},
            {a[x].second, a[y].first}
        };

        int ans = 1e18; 
        for (auto &ele: poss){
            auto & s1 = dta[ele.first][ele.second];
            if (s1.size() == 0){
                continue;
            }
            auto it1 = lower_bound(all(s1), x);
            auto it2 = lower_bound(all(s1), y);
            int a=1e15, b=1e15;
            if (it1 != s1.begin()){
                a = *(it1-1);
            }
            if (it1 != s1.end()){
                b = *it1;
            }
            ans = min(ans, abs(a-x) + abs(a-y));
            ans = min(ans, abs(b-x) + abs(b-y));
            a = 1e15;
            b = 1e15;
            if (it2 != s1.begin()){
                a = *(it2-1);
            }
            if (it2 != s1.end()){
                b = *it2;
            }
            ans = min(ans, abs(a-x) + abs(a-y));
            ans = min(ans, abs(b-x) + abs(b-y));
        }
        if (ans == 1e18){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
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