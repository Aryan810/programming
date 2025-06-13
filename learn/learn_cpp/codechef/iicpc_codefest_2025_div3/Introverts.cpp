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

    int n;cin >> n;

    vi p(n);
    rep(i, n) cin >> p[i];
    if (n < 3){cout << "YES" << endl;return;}
    if (p[0]+p[n-1] != 3){cout << "NO" << endl;return;}
    if (n < 5){
        cout << "YES" << endl;
        return;
    }
    set<pair<int, int> > gapes;
    gapes.insert({0, n-1});
    int curr = 3;
    while (curr <= n){
        int a = curr, b = curr + gapes.size()-1;
        cout << gapes.size() << endl;
        cout << "A, B: " << a << " " << b << endl;
        // for (auto ele: gapes){
        //     cout << ele.first << " " << ele.second << endl;
        // }
        vector<int> pos;
        for (auto ele: gapes){
            cout << ele.first << " " << ele.second << endl;
            if ((ele.first + ele.second)&1){
                int x = (ele.first + ele.second)/2;
                int y = x+1;
                // cout << "x-y " << x << " " << y << endl;
                if (p[x] >= a && p[x] <= b){
                    if (p[y] >= a && p[y] <= b){
                        cout << "NO" << endl;return;
                    }else{
                        pos.push_back(x);
                    }
                }else if (p[y] >= a && p[y] <= b){
                    if (p[x] >= a && p[x] <= b){
                        cout << "NO" << endl;return;
                    }else{
                        pos.push_back(y);
                    }
                }else{
                    cout << "NO" << endl;return;
                }
            }else{
                if (p[(ele.first+ele.second)/2] <= b && p[(ele.first+ele.second)/2] >= a){
                    pos.push_back((ele.first+ele.second)/2);
                }else{
                    cout << "NO" << endl;return;
                }
            }
        }
        for (auto ele: pos){
            cout << "POS: " << ele << endl;
        }
        auto it = gapes.begin();
        for (int i=0;i<pos.size();i++){
            int x = it->first;
            int y = pos[i];
            int z = it->second;

            if (y-x > 1){
                gapes.insert({x, y});
                if (z-y > 1){
                    gapes.insert({y, z});
                }
            }else{
                if (z-y > 1){
                    gapes.insert({y, z});
                }
            }
            auto t = it;
            it++;
            gapes.erase(t);
        }
        curr = b+1;
    }
    cout << "YES" << endl;
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