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
    int n, k, p;cin >> n >> k >> p;
    ll mx=0, sum=0;
    for (int i=0;i<n;i++){
        int c;
        cin >> c;
        if (c > mx){mx = c;}
        sum += c;
    }
    if (mx + k > sum-mx+p){
        cout << "Ved" << endl;
    }else if (mx + k < sum-mx+p){
        cout << "Varun" << endl;
    }else{
        cout << "Equal" << endl;
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