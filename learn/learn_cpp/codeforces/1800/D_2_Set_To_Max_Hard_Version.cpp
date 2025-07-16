#include<bits/stdc++.h>

// #pragma GCC optimize("Ofast,unroll-loops")
using namespace std;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>

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
const int INF = 1e15;

void solve(){

    int n;
    cin >> n;
    vi a(n+1), b(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    vi val(n+1, 0);
    for (int t=0;t<2;t++){
        vi nxta(n+1, 0); // nxt larger
        vi prevb(n+1, 0); // prev smaller
        stack<pair<int, int> > st;
        st.push({INF, n+1});

        for (int i=n;i>=1;i--){
            while (st.size() > 0 && st.top().first <= a[i]){
                st.pop();
            }
            nxta[i] = st.top().second;
            st.push({a[i], i});
        }
        
        while (st.size() > 0){
            st.pop();
        }
        
        st.push({0, 0});

        for (int i=1;i<=n;i++){
            while (st.size() > 0 && st.top().first >= b[i]){
                st.pop();
            }
            prevb[i] = st.top().second;
            st.push({b[i], i});
        }

        vi m(n+1, 0);

        for (int i=1;i<=n;i++){
            m[a[i]] = i;
            if (a[i] <= b[i] && m[b[i]]){
                val[i] |= (nxta[m[b[i]]] > i && prevb[i] < m[b[i]]);
            }
        }

        reverse(a.begin()+1, a.end());
        reverse(b.begin()+1, b.end());
        reverse(val.begin()+1, val.end());
    }

    bool ans = 1;

    for (int i=1;i<=n;i++){
        // cout << val[i] << " ";
        ans = ans & val[i];
    }
    // cout << endl;

    cout << (ans?"YES":"NO") << endl;return;
    
    


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