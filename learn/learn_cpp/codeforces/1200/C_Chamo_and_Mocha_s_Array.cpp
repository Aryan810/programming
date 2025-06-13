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
    vll a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    ll maxt = 0;
    for (int i=0;i<n-1;i++){
        maxt = max(maxt, min(a[i], a[i+1]));
    }
    for (int i=0;i<n-2;i++){
        array<ll, 3> x = {a[i], a[i+1], a[i+2]};
        sort(all(x));
        maxt = max(maxt, x[1]);
    }
    cout << maxt << endl;
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