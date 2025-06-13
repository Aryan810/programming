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
    ll n;
    cin >> n;
    vll a(n);
    unordered_set<int> s;
    for (int i=1;i<=n;i++){
        s.insert(i);
    }
    for (int i=0;i<n-1;i++) cin >> a[i];


    if (a[n-2] != (n*(n+1)/2)){
        a[n-1] = n*(n+1)/2;
        ll sum = 0;
        for (int i=0;i<a.size();i++){
            s.erase(a[i]-sum);
            sum = a[i];
        }
        if (s.size() > 0){
            cout << "NO" << endl;return;
        }else{
            cout << "YES" << endl;return;
        }
    }

    // finding consecutive diffrences
    ll diff = -1;
    for (int i=0;i<n-2;i++){
        if (a[i+1]-a[i] <= n){
            if (s.find(a[i+1]-a[i]) != s.end()){s.erase(a[i+1]-a[i]);}
            else{
                diff = a[i+1] - a[i];
            }
        }else{
            diff = a[i+1]-a[i];
        }
    }
    if (diff == -1){
        if (a[0] == accumulate(all(s), 0ll)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }else{
        if (s.find(a[0]) == s.end()){
            cout << "NO" << endl;
            return;
        }else{s.erase(a[0]);}

        if (diff == accumulate(all(s), 0ll)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
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