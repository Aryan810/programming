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
    if (n&1){
        if (n < 27){
            cout << -1 << endl;
        }else{
            vector<int> out(n);
            out[0] = 1;
            out[0+9] = 1;
            out[0+25] = 1;
            int j = 2;
            for (int i=1;i<9;i+=2){
                out[i] = j;out[i+1] = j;
                j += 1;
            }
            out[26] = j;
            out[22] = j;
            j+=1;
            out[23] = j;
            out[24] = j;
            j+=1;
            for (int i=10;i<22;i+=2){
                out[i] = j;
                out[i+1] = j;
                j += 1;
            }
            for (int i=27;i<n;i+=2){
                out[i] = j;
                out[i+1] = j;
                j+=1;
            }
            for (int i=0;i<n;i++){
                cout << out[i] << " ";
            }cout << endl;
        }
    }else{
        for (int i=0;i<n-1;i+=2){
            cout << i+1 << " " << i+1 << " ";
        }cout << endl;
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