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
    vector< pair<int, int> > v(n);
    for (int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(all(v), [](pair<int, int> a, pair<int, int> b){
        if (max(a.first,a.second) != max(b.first, b.second)){
            return max(a.first,a.second) < max(b.first, b.second);
        }else{
            return min(a.first,a.second) < min(b.first, b.second) ;
        }
    });
    for (int i=0;i<n;i++){
        cout << v[i].first << " " << v[i].second << " ";
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