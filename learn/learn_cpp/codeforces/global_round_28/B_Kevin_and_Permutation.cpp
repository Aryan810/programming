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
    if (k == 1){
        for (int i=1;i<=n;i++){cout << i << " ";}cout << endl;
        return;
    }

    vector<int> s(n);
    for (int i=1;i<=n;i++) s[i-1] = i;
    vector<int> out(n, 0);
    if (n > 2*k-1){
        int pos = 0;
        for (int i=k-1;i<n;i+=k){
            out[i] = s[pos];
            pos += 1;
        }
        for (int i=0;i<n;i++){
            if (out[i] == 0){
                out[i] = s[pos];
                pos += 1;
            }
        }
    }else{
        int pos = n-1;
        if (n%2 == 0){
            for (int i=0;i<n/2;i++){
                out[i] = s[pos];
                pos -= 1;
                out[n-1-i] = s[pos];
                pos -= 1;
            }
        }else{
            for (int i=0;i<n/2;i++){
                out[i] = s[pos];
                pos -= 1;
                out[n-1-i] = s[pos];
                pos -= 1;
            }
            out[n/2] = s[pos];
        }
    }
    for (int i=0;i<n;i++){
        cout << out[i] << " ";
    }cout << endl;

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