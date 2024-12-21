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

bool check(vll & a, ll lmgap, ll c){
    int i = 0;
    c-=1;
    int j=1;
    while (j < a.size() && c > 0){
        while (a[j]-a[i] < lmgap){
            j++;
            if (j >= a.size()){
                return 0;
            }
        }
        c-=1;
        i = j;
        j+=1;
    }
    if (c <= 0){return 1;}else{
        return 0;
    }
}   

void solve(){
    ll n, c;cin >> n >> c;
    vll a(n);
    rep(i, n)cin >> a[i];
    sort(all(a));

    ll mingap = 1e10;
    for (int i=0;i<n-1;i++){
        if (abs(a[i]-a[i+1]) < mingap){
            mingap = abs(a[i]-a[i+1]);
        }
    }
    ll low = mingap;
    ll high = a[n-1]-a[0];
    while (high - low > 1){
        ll mid = (high + low)/2;
        if (check(a, mid, c)){
            low = mid;
        }else{
            high = mid-1;
        }
    }
    if (check(a, high, c)){
        cout << high << endl;
    }else{
        cout << low << endl;
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