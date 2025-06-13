#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n;
    cin >> n;

    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    unordered_map<int, int> m;
    map<pair<int, int>, int> place;
    vector<pair<int, int> > oper;
    if (n&1){
        int cmn = -1;
        int ci = -1;
        int nc = 0;
        for (int i=0;i<n;i++){
            if (m[a[i]] == 0 && m[b[i]] == 0){
                m[a[i]] = b[i];
                m[b[i]] = a[i];
                if (a[i] == b[i]){
                    if (nc > 0){
                        cout << -1 << endl;return;
                    }
                    cmn = a[i];
                    ci = i;
                    nc += 1;
                }
                place[{a[i], b[i]}] += i;
                place[{b[i], a[i]}] += i;
            }else{
                if (m[a[i]] != b[i] || m[b[i]] != a[i]){
                    cout << -1 << endl;return;
                }else{
                    place[{a[i], b[i]}] += i;
                    place[{b[i], a[i]}] += i;
                }
            }
        }
        if (ci != n/2){
            int j = ci;
            int i = n/2;
            oper.push_back({i, j});
            place[{a[i], b[i]}] += j - (i);
            place[{b[i], a[i]}] += j - (i);
            place[{a[j], b[j]}] -= j - (i);
            place[{b[j], a[j]}] -= j - (i);
            swap(a[j], a[i]);
            swap(b[j], b[i]);
        }

        for (int i=(n/2 + 1);i<n;i++){
            int j = place[{a[i], b[i]}] - i;

            // cout << "cje: " << i << " " << j << endl;
            if (j != (n-1-i)){
                oper.push_back({n-1-i, j});
                place[{a[n-1-i], b[n-1-i]}] += j - (n-1-i);
                place[{b[n-1-i], a[n-1-i]}] += j - (n - 1- i);
                place[{a[j], b[j]}] -= j - (n-1-i);
                place[{b[j], a[j]}] -= j - (n - 1- i);
                swap(a[j], a[n-1-i]);
                swap(b[j], b[n-1-i]);
            }
        }

    }else{
        for (int i=0;i<n;i++){
            if (m[a[i]] == 0 && m[b[i]] == 0){
                m[a[i]] = b[i];
                m[b[i]] = a[i];
                if (a[i] == b[i]){
                    cout << -1 << endl;return;
                }
                place[{a[i], b[i]}] += i;
                place[{b[i], a[i]}] += i;
            }else{
                if (m[a[i]] != b[i] || m[b[i]] != a[i]){
                    cout << -1 << endl;return;
                }else{
                    place[{a[i], b[i]}] += i;
                    place[{b[i], a[i]}] += i;
                }
            }
        }
        for (int i=(n/2);i<n;i++){
            int j = place[{a[i], b[i]}] - i;
            if (j != (n-1-i)){
                oper.push_back({n-1-i, j});
                place[{a[n-1-i], b[n-1-i]}] += j - (n-1-i);
                place[{b[n-1-i], a[n-1-i]}] += j - (n - 1- i);
                place[{a[j], b[j]}] -= j - (n-1-i);
                place[{b[j], a[j]}] -= j - (n - 1- i);
                swap(a[j], a[n-1-i]);
                swap(b[j], b[n-1-i]);
            }
        }
    }
    cout << oper.size() << endl;
    for (auto ele: oper){
        cout << ele.first + 1 << " " << ele.second + 1 << endl;
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