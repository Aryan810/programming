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
    vi a(n);
    bool alleq = 1;
    int ele = -1;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        if (ele == -1){ele = x;}
        if (x != ele){alleq = 0;}
        a[i] = x;
    }

    if (alleq){cout << -1 << endl;return;}

    set<int> s;
    int cnt = 0;
    int x = 0;
    for (int i=0;i<n;i++){
        if (a[i] != a[0]){
            s.insert(i - cnt - x);
            cnt += i - cnt - x;
            x += 1;
        }
    }
    s.insert(n - cnt - x);
    cnt += n - cnt - x;
    cout << *(s.begin()) << endl;
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