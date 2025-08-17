#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// 1 7
// 7 6
// 6 1
// 1 5
// 5 4
// 4 1
// 1 3
// 3 2
// 2 1
// 1 1
// 1 0
// 0 1

// 1 6


// 7 22
// 22 15
// 15 7
// 7 8
// 8 1
// 0 1

void solve(){

    int a, b;
    cin >> a >> b;

    int cnt = 0;
    int oper = 0;
    while (a != 0 && b != 0){
        cnt += 1;
        if (a > b){
            int val = a/b;
            if (val&1){
                oper += 2 + (val/2)*3;
                a = a%b;
                swap(a, b);
            }else{
                oper += (val/2)*3;
                a = a%b;
            }
        }else{
            int val = b/a;
            if (val&1){
                oper += 2 + (val/2)*3;
                b = b%a;
                swap(b, a);
            }else{
                oper += (val/2)*3;
                b = b%a;
            }
        }
    }
    cout << a << " " << b << endl;
    if (a != 0){oper += 1;}
    cout << cnt << " " << oper << endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}
