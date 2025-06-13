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

bool good(ll mid, vector<ll> & h, ll m){
    ll total = 0;
    for (auto ele: h){
        if (mid < ele){
            total += ele-mid;
        }
    }
    return (total >= m);
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for (int i=0;i<n;i++) cin >> h[i];
    ll low = 0;
    ll high = 1e9;
    while (high - low > 1){
        ll mid = (low + high)/2;
        if (good(mid, h, m)){
            low = mid;
        }else{
            high = mid-1;
        }
    }
    if (good(high, h, m)){
        cout << high << endl;
    }else{
        cout << low << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        solve();

    return 0;
}