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
    int n, m;
    cin >> n >> m;
    if (m == 1){
        cout << 0 << endl;
        for (int i=0;i<n;i++){
            cout << 0 << endl;
        }
        return;
    }

    if (n >= m-1){
        cout << m << endl;
        int start = 0;
        for (int j=0;j<(m-1);j++){
            for (int i=0;i<m;i++){
                cout << (start+i)%m << " ";
            }cout << endl;
            start += 1;
        }
        start = 0;
        for (int j=0;j<(n-m+1);j++){
            for (int i=0;i<m;i++){
                cout << (start+i)%m << " ";
            }cout << endl;
        }
    }else if (n < m-1){
        cout << n+1 << endl;
        int start = 0;
        for (int j=0;j<(n);j++){
            for (int i=0;i<m;i++){
                cout << (start+i)%m << " ";
            }cout << endl;
            start += 1;
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