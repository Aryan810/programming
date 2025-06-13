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

    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    int x = 0;
    vector<int> temp(k, 0);
    vector<int> fullpos;
    fullpos.push_back(-1);
    string out;
    for (int i=0;i<m;i++){
        temp[s[i]-'a'] += 1;
        bool full = 1;
        for (int j=0;j<k;j++){
            if (temp[j] == 0){
                full = 0;
            }
        }
        if (full){
            for (int j=0;j<k;j++){
                temp[j] = 0;
            }
            // out.push_back('a');
            fullpos.push_back(i);
            x += 1;
        }
    }
    for (int j=0;j<k;j++){
        temp[j] = 0;
    }
    if (x >= n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
        for (int i=fullpos.back()+1;i<m;i++){
            temp[s[i]-'a'] += 1;
        }
        for (int i=0;i<fullpos.size();i++){
            if (fullpos[i] >= 0){
                out.push_back(s[fullpos[i]]);
            }
        }
        int y = -1;
        for (int i=0;i<k;i++){
            if (temp[i] == 0){
                y = i;
            }
        }
        // cout << "y " << y << endl;
        if (y != -1){
            for (int i=0;i<(n-x);i++){
                out.push_back(y+'a');
            }
        }
        cout << out << endl;
    }

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