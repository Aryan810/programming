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
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve(){

    int n;
    cin >> n;
    if (n == 3){
        cout << "2 1 3" << endl;
        return;
    }
    vector<int> even, odd;
    if (n&1){
        odd.push_back(0);
        n -= 1;
    }
    int a=0,b=0;
    for (int i=1;i<=n/2;i++){
        odd.push_back(i);
        even.push_back(i);
    }
    int c = log2(n/2);
    a = 1 << (c+1);
    b = 1 << (c+2);
    bool isa = 1;
    for (int i=0;i<even.size()-1;i++){
        if (isa){
            even[i] += a;
            even[i+1] += a;
            isa = 0;
        }else{
            even[i] += b;
            even[i+1] += b;
            isa = 1;
        }
    }
    
    while (even.size() > 0 || odd.size() > 0){
        if (even.size() > 0){
            cout << even.back() << " ";
            even.pop_back();
        }
        if (odd.size() > 0){
            cout << odd.back() << " ";
            odd.pop_back();
        }
    }cout << endl;



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