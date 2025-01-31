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
    vi a(n);
    int mone = 0, one = 0;
    rep(i, n){
        int x;cin >> x;
        if (x == -1){
            mone += 1;
        }else if (x == 1){
            one += 1;
        }
        a[i] = x;
    }

    if ((mone + one)%2 != 0){
        cout << -1 << endl;return;
    }

    int i=0;
    ordered_set<pair<int, int> > zero_one;
    ordered_set<pair<int, int> > seg;
    while (i < n){
        if (i < n && (a[i] == 0 && a[i+1] != 0)){
            zero_one.insert({i, i+1});
            i += 2;
        }else{
            i += 1;
        }
    }
    i = 0;
    // cout << "SIZE: " << zero_one.size() << endl;
    while (i < n){
        if (i == n-1){
            if (zero_one.size() > 0){
                if (i < n){seg.insert({i, i});}
                auto it = zero_one.begin();
                if (a[it->second] == a[i]){
                    if (it->first < n && it->second < n){
                        seg.insert({it->first, it->first});
                        seg.insert({it->second, it->second});
                    }
                }else{
                    if (it->second < n){seg.insert(*it);}
                }
                zero_one.erase(it);
            }else{
                seg.insert({i, i});
            }
            break;
        }
        if (zero_one.find({i, i+1}) != zero_one.end()){
            i += 2;
        }
        if (a[i] != 0){
            if (i < n && a[i+1] != 0){
                if (a[i] == a[i+1]){
                    if (i+1 < n){seg.insert({i, i+1});}
                    i += 2;
                }else{
                    if (i < n){seg.insert({i, i});}
                    if (i+1 < n){seg.insert({i+1, i+1});}
                    i += 2;
                }
            }else if (i < n && zero_one.size() > 0){
                auto it = zero_one.begin();
                if (i < n){seg.insert({i, i});}
                if (a[it->second] == a[i]){
                    if (it->second < n){seg.insert(*it);}
                }else{
                    if (it->first < n && it->second < n){
                        seg.insert({it->first, it->first});
                        seg.insert({it->second, it->second});
                    }
                }
                zero_one.erase(it);
                i += 1;
            }
        }else{
            if (i == n-1 || (i < n && a[i+1] == 0)){
                if (i < n){seg.insert({i, i});}
                i += 1;
                // cout << "HERE" << endl;
            }else{
                i += 2;
            }
        }
    }
    bool pos = 0;
    for (auto ele: zero_one){
        if (pos){
            if (a[ele.second] == 1){if (ele.second < n){seg.insert(ele);}}
            else{
                if (ele.first < n && ele.second < n){
                    seg.insert({ele.first, ele.first});
                    seg.insert({ele.second, ele.second});
                }
            }
            pos = 0;
        }else{
            if (a[ele.second] == 1){
                if (ele.first < n && ele.second < n){
                    seg.insert({ele.first, ele.first});
                    seg.insert({ele.second, ele.second});
                }
            }else{
                if (ele.second < n){seg.insert(ele);}
            }
            pos = 1;
        }
    }
    cout << seg.size() << endl;
    
    for (auto ele: seg){
        if (ele.second+1 <= n){ 
            cout << ele.first + 1 << " " << ele.second + 1 << endl;
        }
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