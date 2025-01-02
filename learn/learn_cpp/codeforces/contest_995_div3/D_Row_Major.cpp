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

    set<int> s;
    for (int i=1;i*i<=n;i++){
        if (n%i == 0){
            s.insert(i-1);
            s.insert(n/i - 1);
        }
    }
    int i = 0;
    for (auto ele: s){
        if (ele == i){
            i += 1;
        }else{
            break;
        }
    }

    string out;
    rep(l, n){out.push_back('a');}
    int j = 0;
    rep(k, i+1){
        for (int l=k;l<n;l+=i+1){
            out[l] = j+'a';
        }
        j++;
    }
    cout << out << endl;


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