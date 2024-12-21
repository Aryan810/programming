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

int N = 998244353;

ll moduloFactorial(ll sumN){
    ll ans = 1;
    for (int i=1;i<=sumN;i++){
        ans = (ans * i)%N;
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    ll ans = 1;
    ll sumN = 0;
    int i = 0;
    while (i < s.size()){
        int j = i;
        while (i <= s.size() && s[i] == s[j]){
            i++;
        }
        // cout << i << " j: "<< j << endl;
        if (i-j > 1){
            sumN += i-j-1;
            ans = (ans * (i-j))%N;
            // cout << ans << " " << i << " " << j << endl;

        }

    }
    // cout << ans << " " << sumN << endl;
    ans = (ans*moduloFactorial(sumN))%N;
    cout << sumN << " " << ((ans == 0)?1:ans) << endl;
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