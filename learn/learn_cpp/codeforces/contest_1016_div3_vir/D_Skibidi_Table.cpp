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

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int getNum(int n, int x, int y){
    int l = 1, h = binexpiter(2, 2*n);
    int r1 = 1, r2 = binexpiter(2, n);
    int c1 = 1, c2 = binexpiter(2, n);
    while (l != h){
        int al = (h-l+1)/4;
        int alc = (c2-c1+1)/2;
        int p = !(x <= (r2+r1)/2 && x >= r1), q=!(y <= (c2+c1)/2 && y >= c1);
        // cout << l << " " << h << " (" << r1 << ", " << r2 << ") (" << c1 << ", " << c2 << ") " << p << " " << q << endl;
        if (!p && !q){
            h = l - 1 + al;
        }else if (p && q){
            l = l + al; h = l + al - 1;
        }
        else if (p && !q){
            l = l + 2*al; h = l + al - 1;
        }else{
            l = l + 3*al; h = l + al - 1;
        }
        if (p){
            r1 = r1 + alc;
        }else{
            r2 = (r2+r1)/2;
        }
        if (q){
            c1 = c1 + alc;
        }else{
            c2 = (c1+c2)/2;
        }
    }
    return l;
}

void getCoo(int n, int x){
    int l = 1, h = binexpiter(2, 2*n);
    int r1 = 1, r2 = binexpiter(2, n);
    int c1 = 1, c2 = binexpiter(2, n);
    while (r1 != r2){
        int al = (h-l+1)/4;
        int alc = (c2-c1+1)/2;
        if (x >= l && x <= l+al-1){
            h = l + al;
            c2 = (c1+c2)/2;
            r2 = (r1+r2)/2;
        }else if (x >= l+al && x <= l+2*al-1){
            l = l + al;
            h = l + al - 1;
            r1 += alc;
            c1 += alc;
        }else if (x >= l+2*al && x <= l+3*al-1){
            l = l + 2*al;
            h = l + al - 1;
            r1 += alc;
            c2 = (c1+c2)/2;
        }else{
            l = l + 3*al;
            h = l + al - 1;
            r2 = (r1+r2)/2;
            c1 += alc;
        }
    }
    cout << r1 << " " << c1 << endl;
}

void solve(){

    int n, q;
    cin >> n >> q;

    for (int i=0;i<q;i++){
        string s;
        cin >> s;
        if (s == "->"){
            int x, y;
            cin >> x >> y;
            cout << getNum(n, x, y) << endl;
        }else{
            int x;
            cin >> x;
            getCoo(n, x);
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