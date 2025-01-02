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
    string s;
    cin >> s;
    vector<int> out(n);
    stack<int> a, b;
    bool o = 0, t = 0;
    for (int i=0;i<n;i++){
        if (a.empty()){
            if (b.empty()){
                if (s[i] == '('){
                    a.push(i);
                }else{
                    b.push(i);
                }
            }else{
                if (s[i] == ')'){
                    b.push(i);
                }else{
                    out[b.top()] = 2;
                    out[i] = 2;
                    t = 1;
                    b.pop();
                }
            }
        }else if (b.empty()){
            if (s[i] == ')'){
                out[a.top()] = 1;
                out[i] = 1;
                o = 1;
                a.pop();
            }else{
                a.push(i);
            }
        }else{
            if (s[i] == '('){
                out[b.top()] = 2;
                out[i] = 2;
                t = 1;
                b.pop();
            }else{
                out[a.top()] = 1;
                out[i] = 1;
                o = 1;
                a.pop();
            }
        }
    }
    if (a.size() == 0 && b.size() == 0){
        cout << (o+t) << endl;
        for (auto ele: out){
            if (o+t >= 2){cout << ele << " ";}else{
                cout << o+t << " ";
            }
        }cout << endl;
    }else{
        cout << -1 << endl;
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