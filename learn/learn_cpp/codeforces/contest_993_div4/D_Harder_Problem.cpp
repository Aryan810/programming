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
    vi a(n);
    unordered_set<int> left;
    for (int i=1;i<=n;i++){
        left.insert(i);
    }
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        if (left.find(x) != left.end()){left.erase(x);}
        a[i] = x;
    }
    unordered_map<int, int> done;
    vector<int> b(n);
    for (int i=0;i<n;i++){
        if (!done[a[i]]){
            b[i] = a[i];
            done[a[i]] = 1;
        }else{
            b[i] = *(left.begin());
            int x = *(left.begin());
            left.erase(x);
        }
    }
    for (int i=0;i<n;i++){
        cout << b[i] << " ";
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