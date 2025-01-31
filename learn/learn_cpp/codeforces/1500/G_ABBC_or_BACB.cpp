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

    string s;
    cin >> s;
    int n = s.size();
    int a = 0;
    vector<int> sufix_a(n);
    bool alter = 0;
    for (int i=n-1;i>=0;i--){
        sufix_a[i] = a;
        a += s[i]=='A';
        if (i > 0 && (s[i]=='B' && s[i-1]=='B')){
            alter = 1;
        }
    }
    if (s[0] == 'B' || (s[n-1] == 'B' || alter)){cout << a << endl;return;}
    int b = n-a;
    if (b == 0){cout << 0 << endl;return;}
    int i = 0;
    int ans = 0;
    vector<int> A;
    int x = 0;
    for (int i=0;i<n;i++){
        if (s[i] == 'A'){x += 1;}
        else{
            A.push_back(x);
            x = 0;
        }
    }
    A.push_back(x);
    int y = *min_element(all(A));
    cout << (accumulate(all(A), 0ll)-y) << endl;
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