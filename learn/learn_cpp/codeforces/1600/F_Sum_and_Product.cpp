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

int bsqrt(int n){
    int l = 1ll;
    int h = n;
    while (h - l > 1ll){
        int mid = (l + h)/2ll;

        if (mid * mid == n){
            return mid;
        }else if (mid*mid > n){
            h = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    if (l * l == n){
        return l;
    }else if (h * h == n){
        return h;
    }else{
        return -1;
    }
}

void solve(){

    int n;
    cin >> n;
    vi a(n);
    unordered_map<int, int, custom_hash> cnt;
    rep(i, n){
        int x;
        cin >> x;
        cnt[x] += 1;
    }
    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        if (x*x - 4*y < 0){
            cout << 0 << endl;continue;
        }
        int p = bsqrt(x*x - 4*y);
        if (p == -1){
            cout << 0 << endl;continue;
        }
        int f = (x + p);
        int s = (x - p);
        if (abs(x+p)  & 1 || abs(x-p) & 1){
            cout << 0 << endl;continue;
        }
        f = f/2;
        s = s/2;
        if (f*s != y || f+s != x){
            cout << 0 << endl;
            continue;;
        }
        if (f == s){
            cout << (cnt[f]*(cnt[f]-1))/2 << endl;
        }else{
            cout << (cnt[f]*cnt[s]) << endl;
        }
    }
    cout << endl;

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