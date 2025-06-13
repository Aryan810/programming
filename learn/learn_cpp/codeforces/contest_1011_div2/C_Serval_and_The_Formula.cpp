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

void solve(){

    int x, y;
    cin >> x >> y;
    if (x == y){
        cout << -1 << endl;return;
    }
    vi a(63);
    vi b(63);
    string k;
    int p = 1;
    for (int i=0;i<30;i++){
        if (p&x){
            a[i] = 1;
        }else{
            a[i] = 0;

        }

        if (p&y){
            b[i] = 1;

        }else{
            b[i] = 0;

        }
        p = p<<1;
    }
    int i = 0;  
    while (1){
        if (k.size() >= 64){
            cout << -1 << endl;return;
        }
        // cout << i << endl;
        if (a[i] == 1 && b[i] == 1){
            k.push_back('1');
            int carry = 1;
            a[i] = 0;
            for (int j=i+1;j<a.size();j++){
                if (a[j] == 0){
                    a[j] = 1;break;
                }else{
                    a[j] = 0;
                }
            }
            carry = 1;
            b[i] = 0;
            for (int j=i+1;j<b.size();j++){
                if (b[j] == 0){
                    b[j] = 1;break;
                }else{
                    b[j] = 0;
                }
            }
            i += 1;
        }else if (a[i] != b[i]){
            if (i > 35){
                break;
            }
            if (a[i+1] == b[i+1]){
                k.push_back('1');
                int carry = 1;
                if (a[i] == 1){
                    a[i] = 0;
                    for (int j=i+1;j<a.size();j++){
                        if (a[j] == 0){
                            a[j] = 1;break;
                        }else{
                            a[j] = 0;
                        }
                    }
                }
                if (b[i] == 1){
                    carry = 1;
                    b[i] = 0;
                    for (int j=i+1;j<b.size();j++){
                        if (b[j] == 0){
                            b[j] = 1;break;
                        }else{
                            b[j] = 0;
                        }
                    }
                }
            }else{
                k.push_back('0');
            }
            i += 1;
        }else{
            k.push_back('0');
            i += 1;
            if (i > 35){
                break;
            }
            
        }
    }
    int ans = 0;
    p = 1;
    for (auto ele: k){
        if (ele == '1'){
            ans += p;
        }
        p = p << 1;
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