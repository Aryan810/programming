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
    set<ll> s;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        s.insert(x);
    }
    ll mex = 0;
    for (auto ele:s){
        if (ele == mex){
            mex++;
        }else{
            break;
        }
    }

    if (mex == 0){
        if (*s.begin() >= 1){
            cout << 0 << endl;
            cout.flush();
            ll inp;
            cin >> inp;
            if (inp <= -1){return;}
        }
    }else{
        cout << mex << endl;
        cout.flush();
        s.insert(mex);
        while (1){
            ll inp;
            cin >> inp;
            if (inp == 0){
                cout << 0 << endl;
                cout.flush();
                int inp1;
                cin >> inp1;
                break;
            }else{
                cout << inp << endl;
                cout.flush();
            }
            
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