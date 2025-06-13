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
    int n;cin >> n;
    if (n%2 == 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> right;
    vector<int> left;
    for (int i=1;i<=n;i++){
        left.push_back(i);
    }
    for (int i=n+1;i<=2*n;i++){
        right.push_back(i);
    }

    int i=n-1, j=0;
    while (j < n){
        cout << left[i] << " " << right[j] << endl;
        if (j == n-1){break;}
        i-=1;
        j+=2;
    }

    for (int k=0;k<i;k++){
        cout << left[k] << " " << right[n-2-2*k] << endl;
    }

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