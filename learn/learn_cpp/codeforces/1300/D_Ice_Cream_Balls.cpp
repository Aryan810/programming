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

ll findp(ll n){
    ll low = 0;
    ll high = sqrt(2)*1e9 + 2;
    while (high - low > 1){
        ll mid = (low + high)/2;
        if (2*n < mid*((mid-1))){
            high = mid - 1;
        }else{
            low = mid;
        }
    }
    // cout << high << " " << low << endl;
    if (high*(high-1)/2 > n){
        return low;
    }else{
        return high;
    }
}

void solve(){
    ll n;cin >> n;
    ll p = findp(n);
    // cout << "p: "<< p << endl;
    if (2*n == p*(p-1)){
        cout << p << endl;
        // cout << "there: " << endl;
    }else{
        // cout << "here: " << endl;
        cout << (3*p + 2*n - p*p)/2 << endl;
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