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

void logic(int a, int b, int sm, int i, int A, int B, int & ans, int smi, int t1, int t2, int taken){
    // cout << i << " " << "a: " << a << " b: " << b << " " << sm << endl;
    if ((a == A && b == B) || (a >= t1 && b >= t2)){
        ans = min(ans, sm);
        // cout << "HERE! " << ans << endl;
        return;
    }
    if (smi > (114)){return;}
    // giving i to a
    logic(a+i, b, sm+binexpiter(2, i), i+1, A, B, ans, smi+i, t1, t2, 1);

    // giving i to b
    logic(a, b+i, sm+binexpiter(2, i), i+1, A, B, ans, smi+i, t1, t2, 1);

    // give to nothing.
    if (taken){logic(a, b, sm, i+1, A, B, ans, smi, t1, t2, 0);}
}

void solve(){

    int x, y;
    cin >> x >> y;
    // if (x == 0 || y == 0){
    //     int z = max(x, y);
    //     int ans = 0;
    //     int i=1;
    //     while (z > 0){
    //         ans += (1 << i);
    //         z = z >> i;
    //         i += 1;
    //     }
    //     cout << ans << endl;return;
    // }
    string bx, by;
    int c = 1;  
    for (int i=0;i<63;i++){
        if (c&x){
            bx.push_back('1');
        }else{
            bx.push_back('0');
        }
        if (c&y){
            by.push_back('1');
        }else{
            by.push_back('0');
        }
        c = c << 1;
    }
    // cout << bx << endl << by << endl;
    int i=62,j=62;
    while (i >= 0 && bx[i] == '0'){
        i -= 1;
    }

    while (j >= 0 && by[j] == '0'){
        j -= 1;
    }
    int t1 = i + 1;
    int t2 = j + 1;
    // cout << t1 << " " << t2 << endl;
    int sames = 0;
    while ((i>=0 && j>=0) && bx[i] == by[j]){
        i -= 1;
        j -= 1;
        sames += 1;
    }
    // cout << i << " " << j << endl;

    int A = t1 - sames;
    int B = t2 - sames;

    // cout << A << " " << B << endl;
    int sm = 0;
    int ans = 1e18;
    // for(int i=1;i<=(max(A, B));i++){
    //     sm += i;
    //     if (sm >= (A+B)){
    //         logic(0, 0, 0, 1, )
    //     }
    // }
    // int l = 0;
    // while (ans == 1e18){
    //     cout << "NOT FOUND! now " << "A: " << A+l << " " << B+l << endl;
        // if (A+l >= t1)
        logic(0, 0, 0, 1, A, B, ans, 0, t1, t2, 1);
        // l += 1;
    // }

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