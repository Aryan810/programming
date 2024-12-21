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
    int n, a, b, c;cin >> n >> a >> b >> c;
    int maxa = n/a;
    int maxb = n/b;
    int maxc = n/c;
    // cout << maxa << " " << maxb << " " << maxc << endl;
    int ans = 0;
    for (int i=0;i<=maxa;i++){
        for (int j=0;j<=maxb;j++){
            int k = n - a*i - b*j;
            if (k < 0){break;}
            // if (j == 0){cout << k << " " << (i+j+k/c) << endl;}
            // cout << i << " " << j << endl;
            if (k >= 0 && k%c == 0){
                k /= c;
                if (ans < (i+j+k)){
                    ans = i+j+k;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}