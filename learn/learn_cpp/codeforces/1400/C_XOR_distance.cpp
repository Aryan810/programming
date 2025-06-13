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

void printBin(int n){
    int x = 1;
    for (int i=0;i<63;i++){
        if (x&n){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
        x = x << 1;
    }cout << endl;
}

void solve(){

    int a, b, r;
    cin >> a >> b >> r;
    int c = a^b;
    // printBin(a);
    // printBin(b);
    // printBin(c);
    // printBin(r);
    if (c == 0){cout << 0 << endl;return;}
    if (r == 0){
        int ans = 0;
        int x = 1;
        for (int i=0;i<63;i++){
            if (c&x){   
                if (a&x){
                    ans += binexpiter(2, i);
                }else{
                    ans -= binexpiter(2, i);
                }
            }
            x = x<<1;
        }
        cout << abs(ans) << endl;return;
    }

    // if r > 0
    int maxonr = log2(r);
    int fix = 0;
    int maxon = log2(c);
    int y = binexpiter(2, maxon);
    // cout << "c: " << c << endl;
    // cout << maxonr << " " << maxon << endl;
    for (int i=maxon;i>maxonr;i--){
        if (c&y){
            if (a&y){
                fix += y;
            }else{
                fix -= y;
            }
        }
        y = y >> 1;
    }
    // cout << "FIX: " << fix << endl;
    if (fix == 0){
        cout << (binexpiter(2, maxon + 1) - c) << endl;
        return;
    }

    if (fix > 0){
        // to make rest as negative as possible !
        int j = maxonr;
        int x = binexpiter(2, maxonr);
        while (j >= 0){
            while (j>=0 && !(r&x)){
                if (c&x){
                    if (a&x){
                        fix += x;
                    }else{
                        fix -= x;
                    }
                }
                j--;
                x = x>>1;
            }
            if (r&x){
                if (c&x){
                    if (a&x){
                        fix -= x;
                        j--;
                        x = x>>1;
                        continue;
                    }else{
                        for (int i=j;i>=0;i--){
                            if (c&x){
                                fix -= x;
                            }
                            x = x >> 1;
                        }
                        cout << fix << endl;
                        return;
                    }
                }else{
                    x = x>>1;
                    for (int i=j-1;i>=0;i--){
                        if (c&x){
                            fix -= x;
                        }
                        x = x >> 1;
                    }
                    cout << fix << endl;
                    return;
                }
            }
        }
        cout << fix << endl;
        return;
    }else{
        // fix < 0

// to make rest as negative as possible !
        int j = maxonr;
        int x = binexpiter(2, maxonr);
        while (j >= 0){
            while (j>=0 && !(r&x)){
                if (c&x){
                    if (a&x){
                        fix += x;
                    }else{
                        fix -= x;
                    }
                }
                j--;
                x = x>>1;
            }
            if (r&x){
                if (c&x){
                    if (!(a&x)){
                        fix += x;
                        j--;
                        x = x>>1;
                        continue;
                    }else{
                        for (int i=j;i>=0;i--){
                            if (c&x){
                                fix += x;
                            }
                            x = x >> 1;
                        }
                        cout << abs(fix) << endl;
                        return;
                    }
                }else{
                    x = x>>1;
                    for (int i=j-1;i>=0;i--){
                        if (c&x){
                            fix += x;
                        }
                        x = x >> 1;
                    }
                    cout << abs(fix) << endl;
                    return;
                }
            }
        }
        cout << abs(fix) << endl;
        return;

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