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

bool logic(vi & b){
    array<bool, 3> data = {0, 0, 0};
    // for (auto ele: b){cout << ele << " ";}cout << endl;
    if (b[8] > 0){
        return 1;
    }
    if (b[7] > 0){
        if (b[7] > 1){
            return 1;
        }else{
            data = {1, 1, 0};
        }
    }
    if (b[6] > 0){
        if (b[6] > 1){return 1;}
        if (data[0] == 0){
            data = {1, 1, 0};
        }else{
            return 1;
        }
    }
    if (b[5] > 0){
        if (b[5] > 1){return 1;}
        if (data[0] == 0){
            data = {1, 0, 0};
        }else{
            return 1;
        }
    }
    if (b[4] > 0){
        if (b[4] > 1){return 1;}
        if (data[0] == 0){
            data = {1, 0, 0};
        }else{
            return 1;
        }
    }
    if (data[0] == 0){
        return 0;
    }
    if (b[3] > 0){
        if (b[3] > 1){return 1;}
        if (data[1] == 0){
            data[1] = 1;
        }else{
            return 1;
        }
    }
    if (b[2] > 0){
        // cout << data[0] << " " << data[1] << " " << data[2] << endl;

        if (b[2] > 1){return 1;}
        // cout << "here" << endl;
        if (data[1] == 1){
            return 1;
        }
    }
    return 0;
}

void solve(){

    int n;
    cin >> n;
    vi a(1e5 + 7);
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        a[x] += 1;
    }
    vi b(10, 0);
    for (auto ele: a){
        if (ele > 0 && ele < 8){
            b[ele] += 1;
        }else if (ele >= 8){
            b[8] += 1;
        }
    }
    int q;
    cin >> q;
    rep(i, q){
        char c;
        cin >> c;
        bool d = (c == '+')?1:0;
        int x;cin >> x;
        if (a[x] == 0 && d){
            b[1] += 1;
        }
        else if (a[x] == 1){
            if (d){
                b[1] -= 1;
                b[2] += 1;
            }else{
                b[1] -= 1;
            }
        }else if (a[x] > 1 && a[x] < 8){
            if (d){
                b[a[x]] -= 1;
                b[a[x] + 1] += 1;
            }else{
                b[a[x]] -= 1;
                b[a[x] - 1] += 1;
            }
        }else if (a[x] == 8 && !d){
            b[8] -= 1;
            b[7] += 1;
        }
        if (d){
            a[x] += 1;
        }else{
            a[x] -= 1;
        }

        cout << (logic(b)?"YES":"NO") << endl;
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();


    return 0;
}