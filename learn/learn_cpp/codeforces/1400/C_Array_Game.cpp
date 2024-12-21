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
    ll n, k;cin >> n >> k;
    vll a(n);
    for (int i=0;i<n;i++){cin >> a[i];}
    sort(all(a));

    if (k >= 3){cout << 0 << endl;return;}
    
    if (k == 1){
        ll minDiff = 1e18;
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                if (minDiff > abs(a[i]-a[j])){
                    minDiff = abs(a[i]-a[j]);
                }
            }
        }
        cout << min(minDiff, *min_element(all(a))) << endl;
        return;
    }else{ // k == 2
        unordered_set<ll> diffs;
        ll minDiff = 1e18;
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                diffs.insert(abs(a[i] - a[j]));
                if (minDiff > abs(a[i]-a[j])){
                    minDiff = abs(a[i]-a[j]);
                }
            }
        }
        if (minDiff == 0){cout << 0 << endl;return;}
        for (auto ele: diffs){
            auto closest = lower_bound(all(a), ele);
            if (*closest == ele){
                cout << 0 << endl;
                return;
            }else{
                if (closest == a.begin()){
                    if (minDiff > abs(*closest - ele)){
                        minDiff = abs(*closest - ele);
                    }
                }else if (closest == a.end()){
                    if (minDiff > abs(*(closest-1) - ele)){
                        minDiff = abs(*(closest-1) - ele);
                    }
                }else if (closest == a.end()-1){
                    if (minDiff > abs(*(closest) - ele)){
                        minDiff = abs(*(closest) - ele);
                    }
                    if (minDiff > abs(*(closest-1) - ele)){
                        minDiff = abs(*(closest-1) - ele);
                    }
                }else{
                    if (minDiff > abs(*(closest-1) - ele)){
                        minDiff = abs(*(closest-1) - ele);
                    }
                    if (minDiff > abs(*(closest+1) - ele)){
                        minDiff = abs(*(closest+1) - ele);
                    }
                    if (minDiff > abs(*(closest) - ele)){
                        minDiff = abs(*(closest) - ele);
                    }
                }
            }
        }
        cout << minDiff << endl;
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