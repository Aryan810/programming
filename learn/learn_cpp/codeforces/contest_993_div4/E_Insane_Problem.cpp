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
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll power = 1;
    ll ans = 0;
    while (power*l1 <= r2){
        ll miny=l1*power, maxy=r1*power;
        if (miny > r2 || maxy < l2){ans += 0;}
        else if (miny <= l2 && maxy >= r2){
            ll a, b;
            a = (l2%power == 0)?l2:(l2+(power-l2%power));
            b = (r2%power == 0)?r2:(r2 - r2%power);
            ans += (b-a)/power+1;
        }else if (miny >= l2 && maxy <= r2){
            ll a, b;
            a = (miny%power == 0)?miny:(miny+(power-miny%power));
            b = (maxy%power == 0)?maxy:(maxy - maxy%power);
            ans += (maxy-miny)/power+1;
        }else if (miny <= l2 && (maxy>=l2 && maxy <= r2)){
            ll a, b;
            a = (l2%power == 0)?l2:(l2+(power-l2%power));
            b = (maxy%power == 0)?maxy:(maxy - maxy%power);
            ans += (maxy-l2)/power+1;
        }else if (maxy >= r2 && (miny >= l2 && miny <= r2)){
            ll a, b;
            a = (miny%power == 0)?miny:(miny+(power-miny%power));
            b = (r2%power == 0)?r2:(r2 - r2%power);
            ans += (r2-miny)/power+1;
        }
        // cout << "ans: " << ans << endl;
        power *= k;
    }
    cout << ans << endl;
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