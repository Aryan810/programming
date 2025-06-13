#include <iostream>
#include <vector>
#include <map>


// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator


void solve(){

    int n, q;
    cin >> n >> q;

    int ans = 0;
    vector<int> peg_place(n+1);
    for (int i=1;i<=n;i++){
        peg_place[i] = i;
    }
    vector<int> nest_num(n+1, 1);
    
    for (int i=0;i<q;i++){
        int typ;cin >> typ;
        if (typ == 1){
            int p, h;
            cin >> p >> h;
            int init_place = peg_place[p];
            int init_cnt = nest_num[h];
            int init_place_cnt = nest_num[init_place];
            if (init_place_cnt == 2){
                ans -= 1;
            }
            if (init_cnt == 1){
                ans += 1;
            }
            nest_num[h] += 1;
            nest_num[init_place] -= 1;
            peg_place[p] = h;
        }else{
            cout << ans << endl;
        }
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();
    
    return 0;
}