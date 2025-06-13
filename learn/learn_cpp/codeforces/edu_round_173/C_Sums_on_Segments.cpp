#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){

    int n;
    cin >> n;
    vi a(n);
    int diff = -1;
    vi cum(n+1);
    cum[0] = 0;
    int sum = 0;
    vi maxtill(n+1);
    vi mintill(n+1);
    maxtill[0] = 0;
    mintill[0] = 0;
    rep(i, n){
        int x;cin >> x;
        if (x != 1 && x != -1){
            diff = i;
        }
        a[i] = x;
        sum += x;
        cum[i+1] = sum;
        maxtill[i+1] = max(maxtill[i], sum);
        mintill[i+1] = min(mintill[i], sum);
    }
    if (diff == -1){
        int maxi = 0;
        int mini = 0;
        for (int i=n-1;i>=0;i--){
            mini = min(cum[i+1] - maxtill[i], mini);
            maxi = max(cum[i+1] - mintill[i], maxi);
        }
        cout << (maxi - mini + 1) << endl;
        for (int i=mini;i<=maxi;i++){
            cout << i << " ";
        }cout << endl;
        return;
    }

    set<int> ans;
    
    // for left part
    sum = 0;
    int l1 = 0;
    int h1 = 0;
    for (int i=diff-1;i>=0;i--){
        sum += a[i];
        l1 = min(sum, l1);
        h1 = max(sum, h1);
    }

    // for right part
    sum = 0;
    int l2 = 0;
    int h2 = 0;
    for (int i=diff+1;i<n;i++){
        sum += a[i];
        l2 = min(sum, l2);
        h2 = max(sum, h2);
    }
    l1 = l1+l2+a[diff];
    h1 = h1+h2+a[diff];
    for (int i=l1;i<=h1;i++){
        ans.insert(i);
    }


    // for both size seperatly

    // for left => 
    l1 = 0;
    h1 = 0;
    for (int i=diff;i>=0;i--){
        l1 = min(cum[i] - maxtill[i], l1);
        h1 = max(cum[i] - mintill[i], h1);
    }

    // for right =>
    l2 = 0;
    h2 = 0;
    sum = 0;
    cum[diff+1] = 0;
    maxtill[diff+1] = 0;
    mintill[diff+1] = 0;
    for (int i=diff+1;i<n;i++){
        sum += a[i];
        cum[i+1] = sum;
        maxtill[i+1] = max(maxtill[i], sum);
        mintill[i+1] = min(mintill[i], sum);
    }
    for (int i=n-1;i>diff;i--){
        l2 = min(cum[i+1]-maxtill[i], l2);
        h2 = max(cum[i+1]-mintill[i], h2);
    }
    for (int i=l2;i<=h2;i++){
        ans.insert(i);
    }
    for (int i=l1;i<=h1;i++){
        ans.insert(i);
    }
    cout << ans.size() << endl;
    for (auto ele: ans){
        cout << ele << " ";
    }cout << endl;


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}