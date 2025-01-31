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

    int n, m, k;
    cin >> n >> m >> k;
    stack<int> done;
    unordered_set<int> out;
    vector<int> pos(k+1);
    vector<int> order;
    rep(i, k){
        int x;
        cin >> x;
        pos[x] = i+1;
        order.push_back(x);
    }
    reverse(all(order));
    int toplace = k;
    while (done.size() < k){
        int rem = out.size() + done.size();
        int torem = pos[toplace] - out.size() - done.size() - 1;
        if (torem > 0){
            int left = n*m - 2 - out.size();
            if (left >= torem + 2){
                for (int i=0;i<torem;i++){
                    out.insert(order.back());
                    order.pop_back();
                }
                done.push(order.back());
                order.pop_back();
                toplace -= 1;
            }else{
                cout << "TIDAK" << endl;
                return;
            }
        }else if (torem == 0){
            int left = n*m - 2 - out.size();
            if (left >= 2){
                done.push(toplace);
                toplace -= 1;
            }else{
                cout << "TIDAK" << endl;
                return;
            }
        }else{
            int left = n*m - 2 - out.size();
            if (left >= 1){
                out.erase(toplace);
                done.push(toplace);
                toplace -= 1;
            }else{
                cout << "TIDAK" << endl;
                return;
            }
        }
    }
    cout << "YA" << endl;

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