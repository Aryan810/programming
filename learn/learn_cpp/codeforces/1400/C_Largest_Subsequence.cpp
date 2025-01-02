#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char, int> > a;
    pair<char, int> mx;
    for (int i=n-1;i>=0;i--){
        if (mx.first <= s[i]){
            mx.first = s[i];
            mx.second = i;
        }
        if (i < n-1){
            if (a.back() != mx){
                a.push_back(mx);
            }
        }else{
            a.push_back(mx);
        }
    }
    int nmax = 0;
    for (int i=a.size()-1;i>=0;i--){
        if (a[i].first != a.back().first){
            break;
        }
        nmax += 1;
    }
    for (int i=0;i<a.size();i++){
        s[a[i].second] = a[a.size()-1-i].first;
    }
    for (int i=0;i<s.size()-1;i++){
        if (s[i+1] < s[i]){
            cout << -1 << endl;
            return;
        }
    }
    cout << a.size()-nmax << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}