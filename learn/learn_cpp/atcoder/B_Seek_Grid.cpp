#include <iostream>
#include <vector>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator


void solve(){

    int n, m;
    cin >> n >> m;
    vector<vector<int> > s(n, vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char c;
            cin >> c;
            if (c == '#'){
                s[i][j] = 1;
            }else{
                s[i][j] = 0;
            }
        }
    }
    vector<vector<int> > t(m, vector<int>(m));
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            char c;
            cin >> c;
            if (c == '#'){
                t[i][j] = 1;
            }else{
                t[i][j] = 0;
            }
        }
    }

    for (int i=0;i<(n-m+1);i++){
        for (int j=0;j<(n-m+1);j++){
            bool yes = 1;
            for (int i1=0;i1<(m);i1++){
                for (int j1=0;j1<m;j1++){
                    if (s[i+i1][j+j1] != t[i1][j1]){
                        yes = 0;
                        break;
                    }
                }
                if (!yes){break;}
            }
            if (yes){
                cout << i+1 << " " << j+1 << endl;
                return;
            }
        }
    }
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}