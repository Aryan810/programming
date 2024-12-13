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
    int n;
    cin >> n;
    vll a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));
    if (a[0] == 1 && a[1] != 1){
        cout << "YES" << endl;return;
    }else if (a[0] == 1 && a[1] == 1){
        cout << "NO" << endl;return;
    }else{
        if (a[0] == a[1]){
            for (int i=1;i<n;i++){
                if (a[i]%a[0] != 0){
                    cout << "YES" << endl;
                    return;
                }
            }
            cout << "NO" << endl;return;
        }else{
            cout << "YES" << endl;return;
        }
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