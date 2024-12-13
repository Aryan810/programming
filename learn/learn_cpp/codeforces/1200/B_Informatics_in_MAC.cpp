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
    unordered_map<int, int> m;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        m[x] += 1;
        a[i] = x;
    }

    if (m[0] == 0){
        cout << 2 << endl;
        cout << "1 1" << endl;
        cout << "2 " << a.size() << endl;
    }else{
        if (m[0] == 1){cout << -1 << endl;return;}
        int k = 0;
        while (1){
            if (m[k+1] != 0){
                if (m[k+1] > 1){
                    k += 1;
                    continue;
                }else{
                    cout << -1 << endl;
                    return;
                }
            }else{
                break;
            }
        }
        // cout << k << endl;
        int i = 0;
        unordered_set<int> s;
        for (int j=0;j<=k;j++){s.insert(j);}
        auto s1 = s;
        while (1){
        // cout << "13: " << s.size() << endl;

            if (i == n && s.size()>0){
                cout << -1 << endl;
                return;
            }
        // cout << "13: " << s.size() << endl;

            if (s.find(a[i]) != s.end()){
                s.erase(a[i]);
            }
            if (s.size() <= 0){
                break;
            }
            i += 1;
        }
        int j = i+1;
        while (1){
            if (j == n && s1.size()>0){
                cout << -1 << endl;
                return;
            }

            if (s1.find(a[j]) != s1.end()){
                s1.erase(a[j]);
            }
            if (s1.size() <= 0){
                break;
            }
            j += 1;
        }
        cout << 2 << endl;
        cout << 1 << " " << i+1 << endl;
        cout << i+2 << " " << n << endl;
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