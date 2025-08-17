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
class segtree{
    public:
        int n;
        vi arr;
        vi leafs;
        vi val;
        int (*comp)(int a, int b) = [](int a, int b){return a+b;};
        int DEF = 0;
        int make(int v, int l, int r){
            if (l < r){
                val[v] = comp(make(2*v+1, l, (l+r)/2), make(2*v + 2, (l+r)/2 + 1, r));
                return val[v];
            }else if (l < n && l == r){
                leafs[l] = v;
                val[v] = arr[l];
                return val[v];
            }else{
                return DEF;
            }
        }
        void update(int i, int newval){
            int j = leafs[i];
            val[j] = newval;
            while (j != 0){
                int k;
                int par;
                if (j&1){
                    k = j + 1;
                    par = j/2;
                }else{
                    k = j - 1;
                    par = j/2 - 1;
                }
                val[par] = comp(val[j], val[k]);
                j = par;
            }
        }
    
        int finder(int j, int l, int r, int ql, int qr){
            if (l >= ql && r <= qr){
                return val[j];
            }else if (l > qr || r < ql){
                return DEF;
            }else{
                return comp(finder(2*j+1, l, (l+r)/2, ql, qr), finder(2*j+2, (l+r)/2+1, r, ql, qr));
            }
        }
    
        int find(int l, int r){
            return finder(0, 0, arr.size()-1, l, r);
        }

        segtree(int n, vi arr, int default_val=0, int (*comp)(int a, int b)=NULL){
            int sz = 0;
            int x = 1;
            if (comp){this->comp = comp;}
            while (1){
                sz += x;
                if (x >= n){break;}
                x *= 2;
            }
            this->n = n;
            this->DEF = default_val;
            this->arr = arr;
            this->leafs.resize(sz);
            this->val.assign(sz, this->DEF);
            make(0, 0, arr.size()-1);
        }
};
void solve(){
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);
    rep(i, n) cin >> b[i];
    int dsum = 0;
    set<int> dets;
    for (int i=0;i<n;i++){
        if (abs(a[i]-b[i]) > k){
            dets.insert(i);
            dsum += max(a[i], b[i]);
        }
    }

    segtree sa(n, a, 0ll);
    segtree sb(n, b, 0ll);
    int curr = 1;
    int ans = 0;
    for (int i=0;i<n;i++){
        // cout << curr << endl;
        // cout << a[i] << " " << b[i] << endl;
        if (curr){
            if (a[i] + k < b[i]){
                curr = 1 - curr;
            }
        }else{
            if (b[i] + k < a[i]){
                curr = 1 - curr;
            }
        }
        if (curr){
            // cout << a[i] << endl;
            ans += a[i];
        }else{
            // cout << b[i] << endl;
            ans += b[i];
        }
    }
    int q;
    cin >> q;
    // cout << ans << endl;
    for (int j=0;j<q;j++){
        int t;cin >> t;
        int p, x;cin >> p >> x;
        int i = p-1;

        if (t == 1){
            auto lst = dets.lower_bound(i);
            auto it = dets.upper_bound(i);
            int nxt = n;
            if (it != dets.end()){
                nxt = *it;
            }
            int curr = 1;
            if (lst != dets.begin()){
                lst--;
                if (b[*lst] > a[*lst]){
                    curr = 0;
                }
            }

            int nbef = 0;
            if (abs(a[i]-b[i]) <= k){
                nbef = 1;
            }

            int naft = 1;
            if (abs(x-b[i]) > k){
                naft = 0;
            }

            if (nbef && naft){
                if (curr){
                    ans += x - a[i];
                }
                a[i] = x;
                sa.update(i, x);
            }else if (nbef){
                int caft = 1;
                // cout << "mai yaha" << endl;
                // cout << curr << " " << nxt << endl;
                // cout << a[i] << " " << x << endl;
                if (b[i] > x){caft = 0;}
                int cbef = curr;
                // cout << ans << " ";
                if (cbef){
                    ans -= sa.find(i, nxt-1);
                }else{
                    ans -= sb.find(i, nxt-1);
                }
                // cout << ans << " ";
                a[i] = x;
                sa.update(i, x);
                if (caft){
                    ans += sa.find(i, nxt-1);
                }else{
                    ans += sb.find(i, nxt-1);
                }
                // cout << ans << endl;
                dets.insert(i);
            }else if (naft){
                int caft = curr;
                int cbef = 1;
                if (b[i] > a[i]){
                    cbef = 0;
                }
                if (cbef){
                    ans -= sa.find(i, nxt-1);
                }else{
                    ans -= sb.find(i, nxt-1);
                }

                a[i] = x;
                sa.update(i, x);

                if (caft){
                    ans += sa.find(i, nxt-1);
                }else{
                    ans += sb.find(i, nxt-1);
                }
                if (dets.find(i) != dets.end()) dets.erase(i);
            }else{
                int caft = 1;
                int cbef = 1;
                if (b[i] > a[i]){
                    cbef = 0;
                }
                if (b[i] > x){
                    caft = 0;
                }
                if (cbef){
                    ans -= sa.find(i, nxt-1);
                }else{
                    ans -= sb.find(i, nxt-1);
                }

                a[i] = x;
                sa.update(i, x);

                if (caft){
                    ans += sa.find(i, nxt-1);
                }else{
                    ans += sb.find(i, nxt-1);
                }
            }
        }else{
            // cout << "here" << endl;
            auto lst = dets.lower_bound(i);
            auto it = dets.upper_bound(i);
            int nxt = n;
            if (it != dets.end()){
                nxt = *it;
            }
            int curr = 1;
            if (lst != dets.begin()){
                lst--;
                if (b[*lst] > a[*lst]){
                    curr = 0;
                }
            }

            int nbef = 0;
            if (abs(a[i]-b[i]) <= k){
                nbef = 1;
            }

            int naft = 1;
            if (abs(x-a[i]) > k){
                naft = 0;
            }

            if (nbef && naft){
                if (!curr){
                    ans += x - b[i];
                }
                b[i] = x;
                sb.update(i, x);
            }else if (nbef){
                int cbef = curr;
                int caft = 1;
                if (b[i] > a[i]){
                    caft = 0;
                }
                if (cbef){
                    ans -= sa.find(i, nxt-1);
                }else{
                    ans -= sb.find(i, nxt-1);
                }

                b[i] = x;
                sb.update(i, x);

                if (caft){
                    ans += sa.find(i, nxt-1);
                }else{
                    ans += sb.find(i, nxt-1);
                }
                dets.insert(i);
            }else if (naft){
                int caft = curr;
                int cbef = 1;
                if (b[i] > a[i]){
                    cbef = 0;
                }
                if (cbef){
                    ans -= sa.find(i, nxt-1);
                }else{
                    ans -= sb.find(i, nxt-1);
                }

                b[i] = x;
                sb.update(i, x);

                if (caft){
                    ans += sa.find(i, nxt-1);
                }else{
                    ans += sb.find(i, nxt-1);
                }
                if (dets.find(i)!=dets.end()){
                    dets.erase(i);
                }
            }else{
                // cout << "ab" << endl;
                int caft = 1;
                int cbef = 1;
                if (b[i] > a[i]){
                    cbef = 0;
                }
                if (x > a[i]){
                    caft = 0;
                }
                if (cbef){
                    ans -= sa.find(i, nxt-1);
                }else{
                    ans -= sb.find(i, nxt-1);
                }

                b[i] = x;
                sb.update(i, x);

                if (caft){
                    ans += sa.find(i, nxt-1);
                }else{
                    ans += sb.find(i, nxt-1);
                }
            }
        }
        cout << ans << endl;
    }



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