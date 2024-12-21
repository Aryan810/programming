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
    string s;
    cin >> s;
    int sum = 0;
    vi cum(n+1);
    cum[0] = 0;
    for (int i=0;i<n;i++){
        sum += s[i]-'0';
        cum[i+1] = sum;
    }
    vector<pair<int, int> > v;
    for (int i=0;i<=n;i++){
        int sr = cum[n] - cum[i];
        int sl = cum[i] - cum[0];
        int r_req_sat = (n-i+1)/2;
        int l_req_sat = (i+1)/2;
        if (sr >= r_req_sat && l_req_sat <= (i-sl)){
            v.push_back({i, abs(n/(double)2 - i)});
        }
    }
    sort(all(v), [](pair<int, int> a, pair<int, int> b){
        if (a.second == b.second){
            return a.first < b.first;
        }else{
            return a.second < b.second;
        }
    });
    cout << v[0].first << endl;
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