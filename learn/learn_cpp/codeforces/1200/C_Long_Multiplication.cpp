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
    string x, y;
    cin >> x >> y;
    int n = x.size();
    // cout << "jL " << n << endl;
    vector< pair<int, int> > v(n);
    for (int i=0;i<n;i++){
        v[i].first = x[i]-'0';
        v[i].second = y[i]-'0';
    }
    for (int i=0;i<n;i++){
        if (i == 0){
            continue;
        }
        int sa=0, sb=0;
        for (int j=0;j<i;j++){
            sa += v[j].first*v[i].second + v[j].second*v[i].first;
            sb += v[j].first*v[i].first + v[j].second*v[i].second;
            // cout << sa << " " << sb << endl;

            if (sa < sb){
                swap(v[i].first, v[i].second);
                break;
            }else if (sa > sb){
                break;
            }
        }
    }

    for (int i=0;i<n;i++){
        cout << char(v[i].first+'0') << "";
    }cout << endl;
    for (int i=0;i<n;i++){
        cout << char(v[i].second+'0') << "";
    }cout << endl;
    

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