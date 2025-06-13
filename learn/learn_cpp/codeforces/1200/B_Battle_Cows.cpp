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
    int n, k;cin >> n >> k;
    vll a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    int justMore = -1;
    for (int i=0;i<k-1;i++){
        if (a[k-1] < a[i]){
            justMore = i;
            break;
        }
    }

    if (justMore == -1){
        for (int i=0;i<n;i++){
            if (a[i] > a[k-1]){
                cout << i-1 << endl;
                return;
            }
            if (i == n-1){
                cout << i << endl;
                return;
            }
        }
    }else{
        int bef=0, aft=0;
        if (justMore == 0){bef = 0;}else{
            bef = justMore - 1;
        }

        for (int i=justMore+1;i<k-1;i++){
            if (a[i] > a[k-1]){break;}
            aft += 1;
        }
        if (justMore > 0){
            aft += 1;
        }
        cout << max(aft, bef) << endl;
        return;
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