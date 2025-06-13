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
bool flag = 1;
int N = 2e6 + 8;
vector<bool> is_prime(2e6 + 8, true);
vector<int> primes;
int nextprime(int n){
    return *upper_bound(all(primes), n);
}

void logic(int n, vector< pair<int, int> >& ans){
    if (n <= 1){ans.push_back({1, 1});return;}
    int p = nextprime(n);
    // cout << "PRIME: " << p << endl;
    if (p > 2*n){
        flag = 0;return;
    }
    for (int i=n;2*i>=(p+1);i--){
        ans.push_back({i, p-i});
    }

    logic(p-n-1, ans);
}

void solve(){

    int n;
    cin >> n;
    flag = 1;
    vector<pair<int, int> > ans;
    logic(n, ans);
    if (!flag){
        // cout << n << endl;
        cout << -1 << endl;return;
    }else{
        // if (n%2 == 0){
            // for (auto ele: ans){
            //     cout << ele.first << " " << ele.second << endl;
            // }
        // }
        if (n&1 && (ans.back().first == 1 && ans.back().second == 1)){
            for (int i=0;i<ans.size()-1;i++){
                cout << ans[i].first << " ";
            }
            cout << 1 << " ";
            for (int i=ans.size()-2;i>=0;i--){
                cout << ans[i].second << " ";
            }
        }else{
            for (int i=0;i<ans.size()-1;i++){
                cout << ans[i].first << " ";
            }
            for (int i=ans.size()-2;i>=0;i--){
                cout << ans[i].second << " ";
            }
        }
        cout << endl;
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (int)i * i <= N) {
            // if (i != 0){primes.push_back(i);}
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i=2;i<=N;i++){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }
    while(test--){
        solve();
    }
    return 0;
}