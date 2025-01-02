#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

bool checkPrime(int n){
    if (n == 2){return 1;}
    else if (n <= 1){return 0;}
    int div = 0;
    for (int i=2;i*i<=n;i++){
        while (n%i == 0){
            n /= i;
            div ++;
        }
    }
    if (div == 0){
        return 0;
    }else{
        return 1;
    }
}

void solve(){
    int n, m;cin >> n >> m;
    if (checkPrime(n)){
        for (int i=1;i<=n;i++){
            for (int j=0;j<m;j++){
                cout << (i + n*(j)) << " ";
            }
            cout << endl;
        }
    }else if (checkPrime(m)){
        for (int i=0;i<n;i++){
            for (int j=1;j<=m;j++){
                cout << (j + i*m) << " ";
            }
            cout << endl;
        }
    }else{
        vector<vector<int> > v(n, vector<int>(m));
        int i = 0;
        int k = 0;
        for (int j=0;j<m;j++){
            k = i%7;    
            for (int t=0;t<(n-k);t++){
                v[t][j] = t+1 + j*(n+1);
            }
            int f = -1;
            if (k!=0){f = v[n-k][j-1] + 1;}
            int s = 1 + j*(n+1);
            for (int t=0;t<(k);t++){
                v[n-k+t][j] = f;
                f++;
            }
            i++;
        }
        i=0;
        for (i=0;i<n;i++){
            for (int l=0;l<m;l++){
                cout << v[i][l] << " ";
            }cout << endl;
        }
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}