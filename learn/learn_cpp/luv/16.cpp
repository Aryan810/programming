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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        ll n, q;cin >> n >> q;
        string s;
        cin >> s;

        vector< vector<int> > cum(n+1, vector<int>(26, 0));
        vector<int> x(26, 0);
        for (int i=0;i<n;i++){
            x[s[i]-'a'] += 1;
            cum[i+1] = x;
        }

        for (int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;

            vector<int> v(26);
            for (int j=0;j<26;j++){
                v[j] = cum[r][j] - cum[l-1][j];
            }
            int odds = 0;
            int sz = 0;
            for (int j=0;j<26;j++){
                if (v[j] != 0){
                    sz += 1;
                }
                if (v[j]&1){
                    odds += 1;
                }
            }
            if (odds > 1){
                cout << "NO" << endl;
            }else if (odds == 1){
                cout << ((sz&1)?"YES":"NO") << endl;
            }else{
                cout << "YES" << endl;
            }
        }

    }

    return 0;
}