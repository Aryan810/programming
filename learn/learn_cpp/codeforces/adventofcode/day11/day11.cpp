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
map<pair<ll, ll>,ll> dp;
ll rep = 0;
ll solve(ll x, ll t){
    ll ret;
    if (dp.find({x, t}) != dp.end()){
        rep += 1;
        return dp[{x, t}];
    }
    if (t == 0){
        ret = 1;
    }else if (x == 0){
        ret = solve(1, t-1);
    }else if(to_string(x).size()%2 == 0){
        string s = to_string(x);
        ret = solve(stol(s.substr(0, s.size()/2)), t-1) + solve(stol(s.substr(s.size()/2, s.size()/2)), t-1);
    }else{
        ret = solve(x*2024, t-1);
    }
    dp[{x, t}] = ret;
    // cout << "{" << x << ", " << t << "}" << endl;;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    int num = 8;
    vector<ll> v(num);

    ll ans = 0;
    int n = 75;
    for (ll i=0;i<num;i++){
        inp >> v[i];
    }

    for (int i=0;i<v.size();i++){
        ans += solve(v[i], n);
    }
    // cout << v.size() << endl;
    // cout << v.size() << endl;
    cout << ans << endl;
    cout << rep << endl;
    cout << dp.size() << endl;
    inp.close();

    return 0;
}