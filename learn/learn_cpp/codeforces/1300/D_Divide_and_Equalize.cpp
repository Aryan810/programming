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
    vi a(n);
    unordered_map<int, int> powerCount;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        auto y = x;
        for (int i=2;i*i<=x;i++){
            while (y%i == 0){
                y /= i;
                powerCount[i] += 1;
            }
        }
        if (y > 1){
            powerCount[y] += 1;
            y = 1;
        }
    }
    bool possible = 1;
    for (auto pCount: powerCount){
        if (pCount.second%n != 0){
            possible = 0;
        }
    }
    cout << (possible?"YES":"NO") << endl;
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