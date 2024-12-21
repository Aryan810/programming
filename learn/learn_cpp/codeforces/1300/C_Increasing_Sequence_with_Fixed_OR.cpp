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

ll binexpiter(ll a, ll b){
    ll ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

void solve(){
    ll n;cin >> n;
    auto x = n; 
    int i=0;
    vector<ll> out;
    while (x > 0){
        if (x&1){
            ll topush = n-binexpiter(2, i);
            if (topush > 0){
                out.push_back(topush);
            }
        }
        i += 1;
        x = x/2;
    }
    sort(all(out));
    out.push_back(n);
    cout << out.size() << endl;
    for (auto num: out){
        cout << num << " ";
    }cout << endl;
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