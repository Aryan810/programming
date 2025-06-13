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
    int n;
    cin >> n;
    if (n%2 == 0){cout << -1 << endl;return;}
    vll cum(n+1);
    cum[0] = 0;
    ll sum = 0;
    vi a;
    for (int i=1,j=n-1;i<=n;){
        a.push_back(i);
        if (j > 0){a.push_back(j);}
        i += 2;
        j -= 2;
    }
    // for (int i=0;i<a.size();i++){
    //     cout << a[i] << " ";
    // }cout << endl;
    for (int i=0;i<n;i++){
        sum += a[i+1];
        cum[i+1] = sum;
    }
    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++){
            if ((cum[j]-cum[i-1])%(n+1) == 0){
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int i=1;i<=n;i++){cout << i << " ";}cout << endl;
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