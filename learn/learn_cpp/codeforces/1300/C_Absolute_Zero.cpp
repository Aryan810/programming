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
    int n;
    cin >> n;
    vll a(n);
    ll M = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i] > M){M = a[i];}
    }
    if (M == 0){
        cout << 0 << endl;cout << endl;
        return;
    }
    bool odd = (a[0]&1);
    for (int i=0;i<n;i++){
        if (odd && !(a[i]&1)){
            cout << -1 << endl;
            return;
        }else if (!odd && a[i]&1){
            cout << -1 << endl;
            return;
        }
    }
    int Mpower = log2(M);
    for (int i=Mpower;i>=0;i--){
        ll tosub = binexpiter(2, i);
        for (int j=0;j<n;j++){
            a[j] = abs(a[j]-tosub);
        }
    }
    bool areSame = 1;
    for (int i=0;i<n;i++){
        if (a[i] != a[0]){
            areSame = 0;
        }
    }

    if (areSame){
        cout << Mpower + 1 + ((a[0] != 0)?1:0) << endl;
        for (int i=Mpower;i>=0;i--){
            cout << binexpiter(2, i) << " ";
        }
        if (a[0] != 0){
            cout << 1 << " ";
        }cout << endl;

    }else{
        cout << -1 << endl;
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