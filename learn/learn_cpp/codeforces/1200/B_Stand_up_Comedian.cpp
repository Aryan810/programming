#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll a, b, c, d;cin >> a >> b >> c >> d;
    ll ans = 0;
    int al=0, bo=0;
    
    // 1
    al += a;bo += a;
    ans += a;

    // 2
    if (al == 0){
        ans += 1;
        cout << ans << endl;
        return;
    }
    ans += 2*(min(b, c));
    int x = min(b, c);
    b -= x;
    c -= x;

    if (b > c){
        if (bo+1 <= b){
            ans += bo+1;
            cout << ans << endl;
            return;
        }else{
            ans += b;
            bo -= b;
            al += b;
        }
    }else if (b < c){
        if (al+1 <= c){
            ans += al+1;
            cout << ans << endl;
            return;
        }else{
            ans += c;
            bo += c;
            al -= c;
        }
    }else{
        if (d >= al+1){
            ans += al+1;
            cout << ans << endl;
            return;
        }else{
            ans += d;
            cout << ans << endl;
            return;
        }
    }

    if (al >= 0 && bo >= 0){
        int x = min(al, bo);
        if (d >= x+1){
            ans += x+1;
        }else{
            ans += d;
        }
        cout << ans << endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}