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
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(1), t(1);
    s[0] = 1e9;
    t[0] = 1e9;
    for (int i=0;i<n;i++){
        if (s.back() < t.back()){
            if (a[i] > t.back()){
                s.push_back(a[i]);
            }else if (a[i] <= t.back() && a[i] > s.back()){
                t.push_back(a[i]);
            }else if (a[i] == s.back()){
                s.push_back(a[i]);
            }else{
                s.push_back(a[i]);
            }
        }else{
            if (a[i] > s.back()){
                t.push_back(a[i]);
            }else if (a[i] <= s.back() && a[i] > t.back()){
                s.push_back(a[i]);
            }else if (a[i] == t.back()){
                t.push_back(a[i]);
            }else{
                t.push_back(a[i]);
            }
        }
    }
    int ans = 0;
    for (int i=0;i<(s.size()-1);i++){
        // cout << s[i] << " ";
        if (s[i+1] > s[i]){ans += 1;}
    }
    for (int i=0;i<(t.size()-1);i++){
        // cout << t[i] << " ";
        if (t[i+1] > t[i]){ans += 1;}
    }
    cout << ans << endl;
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