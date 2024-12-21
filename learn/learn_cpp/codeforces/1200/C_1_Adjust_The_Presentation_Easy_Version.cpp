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
    int n, m, q;cin >> n >> m >> q;
    vi a(n);
    vector<int> v;
    for (int i=0;i<n;i++) cin >> a[i];
    int last = -1;
    for (int i=0;i<m;i++){
        int bi;
        cin >> bi;
        if (last != bi){
            last = bi;
            v.push_back(bi);
        }
    }

    int i = 0, j = 0;
    unordered_set<int> presented;
    bool possible = 1;
    while (i < n && j < v.size()){
        if (presented.find(v[j]) == presented.end()){
            if (a[i] != v[j]){
                possible = 0;
                break;
            }else{
                presented.insert(a[i]);
                i += 1;
                j += 1;
            }
        }else{
            j += 1;
        }
    }
    cout << (possible?"YA":"TIDAK") << endl;
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