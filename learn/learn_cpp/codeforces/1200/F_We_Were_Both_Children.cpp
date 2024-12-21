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
    int n;cin >> n;
    vector<ll> cnt(n+1);
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        if (x <= n){
            cnt[x] += 1;
        }
    }
    vector<ll> v(n+1);
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j+=i){
            v[j] += cnt[i];
        }
    }
    cout << *(max_element(all(v))) << endl;

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