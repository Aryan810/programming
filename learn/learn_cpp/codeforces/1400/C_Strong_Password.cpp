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
    string s;
    cin >> s;
    int m;
    cin >> m;
    string l, r;cin >> l >> r;

    vector< set<int> > v(11);
    for (int i=0;i<s.size();i++){
        v[s[i]-'0'].insert(i);
    }
    int maxi = -1;
    for (int i=0;i<m;i++){
        int localMaxi = maxi;
        for (int j=l[i]-'0';j<=(r[i]-'0');j++){
            auto ind = v[j].lower_bound(maxi+1);
            // cout << j << " " << i << " " << localMaxi << endl;
            if (ind == v[j].end()){cout << "YES" << endl;return;}
            if (localMaxi < *ind){
                localMaxi = *ind;
            }
            // cout << i << " " << j << " " << maxi <<  endl;
        }
        if (maxi < localMaxi){
            maxi = localMaxi;
        }
    }
    cout << "NO" << endl;
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