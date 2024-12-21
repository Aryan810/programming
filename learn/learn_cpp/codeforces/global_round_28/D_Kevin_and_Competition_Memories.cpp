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
    int n, m;
    cin >> n >> m;
    vll a(n);
    vll b(m);
    vll rankc(m);
    rep(i, n) cin >> a[i];
    ll kevin = a[0];
    sort(all(a));
    rep(i, m){
        ll x;
        cin >> x;
        if (x <= kevin){rankc[i] = 1;}
        else{
            rankc[i] = (a.end() - lower_bound(all(a), x)) + 1;
        }
    }

    sort(all(rankc));

    for (int i=0;i<m;i++){
        ll sum = 0;
        for (int j=i;j<m;j+=i+1){
            sum += rankc[j];
        }
        cout << sum << " ";
        sum = 0;
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