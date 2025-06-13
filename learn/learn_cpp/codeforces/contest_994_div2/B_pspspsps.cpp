#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
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
    if (s.find('s') >= s.size() || (s.find('p') >= s.size())){cout << "YES" << endl;return;}
    if (!(s[0] == 's' && s[n-1] == 'p')){
        if (s[0] == '.' && s[n-1] == '.'){cout << "NO" <<endl;return;}
    }

    int lasts=0, firstp = -1;
    for (int i=0;i<n;i++){
        if (s[i] == 's'){
            if (i > lasts){
                lasts = i;
            }
        }
        if (firstp == -1 && s[i] == 'p'){
            firstp = i;
        }
    }
    // cout << lasts << " " << firstp << endl;
    if (lasts >= firstp){
        cout << "NO" << endl;return;
    }else{
        if (lasts == 0 || firstp == n-1){cout << "YES" << endl;return;}else{
            cout << "NO" << endl;return;
        }
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