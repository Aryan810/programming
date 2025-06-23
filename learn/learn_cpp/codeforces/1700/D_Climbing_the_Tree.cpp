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

void solve(){
//  cout << "here" << endl;
    int q;
    cin >> q;
    int l = 0;
    int h = 1e18+1;
    bool setted = 0;
    for (int i=0;i<q;i++){
        // cout << "there" << endl;
        int t;
        cin >> t;
        if (t == 1){
            int a, b, n;cin >> a >> b >> n;
            int tl = l, th = h;
            setted = 1;
            if (n == 1){
                tl = max(0ll, tl);
                th = min(th, a);
                if (th >= tl){
                    cout << 1 << " ";
                    h = th;
                    l = tl;
                }else{
                    cout << 0 << " ";
                }
            }else{
                tl = max(a + 1 + (a-b)*(n-2), tl);
                th = min(th, a + (a-b)*(n-1));
                if (th >= tl){
                    cout << 1 << " ";
                    h = th;
                    l = tl;
                }else{
                    cout << 0 << " ";
                }
            }
        }else{
            int a, b;
            cin >> a >> b;
            if (!setted){
                cout << -1 << " ";continue;
            }
            // cout << l << " " << h << endl;
            int ld = 1;
            int hd = 1e18/(a-b) + 1;
            bool found = 0;
            while (hd - ld > 1){
                int mid = (hd + ld)/2;
            
                int f, s;
                if (mid == 1){
                    f = 0;
                    s = a;
                }else{
                    f = a + 1 + (a-b)*(mid-2);
                    s = a + (a-b)*(mid-1);
                }
                // cout << f << " " << s << endl;
                if (l > s){
                    ld = mid + 1;
                }else if (f > h){
                    hd = mid - 1;
                }else if ((f <= l && s >= h)){
                    found = 1;
                    cout << mid << " ";break;
                }else{
                    found = 1;
                    cout << -1 << " ";break;
                }
            }
            if (!found){
                int f, s;
                if (ld == 1){
                    f = 0;
                    s = a;
                }else{
                    f = a + 1 + (a-b)*(ld-2);
                    s = a + (a-b)*(ld-1);
                }
                if ((f <= l && s >= h)){
                    cout << ld << " ";
                    found = 1;
                }
                if (!found){
                    if (hd == 1){
                        f = 0;
                        s = a;
                    }else{
                        f = a + 1 + (a-b)*(hd-2);
                        s = a + (a-b)*(hd-1);
                    }
                    if ((f <= l && s >= h)){
                        cout << hd << " ";
                    }else{
                        cout << -1 << " ";
                    }
                }
            }

        }
        // cout << "(" << l << " " << h << ")" << endl;
    }
    cout << endl;

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