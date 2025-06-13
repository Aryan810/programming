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
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(){

    int x, y, k;
    cin >> x >> y >> k;

    vector<int> pf_x;
    vector<int> pf_y;
    // prime factors of x
    int n = x;
    for (int i=2;i*i<=n;i++){
        while (n%i == 0){
            pf_x.push_back(i);
            
            n /= i;
        }
    }
    if (n > 1){
        pf_x.push_back(n);
       
    }

    n = y;
    for (int i=2;i*i<=n;i++){
        while (n%i == 0){
            pf_y.push_back(i);
            
            n /= i;
        }
    }

    if (n > 1){
        pf_y.push_back(n);
        
    }

    sort(rall(pf_x));
    sort(rall(pf_y));
    for (auto ele: pf_x){
        cout << ele << " ";
    }cout << endl;
    for (auto ele: pf_y){
        cout << ele << " ";
    }cout << endl;
    int i = pf_x.size()-1;
    int j = pf_y.size()-1;
    int oper = 0;
    while (i >= 0 && j >= 0){
        if (pf_x[i] < pf_y[j]){
            int temp = 1;   
            while (i >= 0 && pf_x[i] < pf_y[j]){
                if (temp * pf_x[i] <= k){
                    temp *= pf_x[i];
                    i -= 1;
                }else{
                    break;
                }
            }
            if (temp == 1){
                cout << -1 << endl;return;
            }
            oper += 1;
        }else if (pf_x[i] > pf_y[j]){
            int temp = 1;
            while (j >= 0 && pf_x[i] > pf_y[j]){
                if (temp * pf_y[j] <= k){
                    temp *= pf_y[j];
                    j -= 1;
                }else{
                    break;
                }
            }
            if (temp == 1){
                cout << -1 << endl;return;
            }
            oper += 1;
        }else{
            i -= 1;
            j -= 1;
        }
    }
    if (j >= 0){
        while (j >= 0){
            int temp = 1;
            while (j >= 0){
                if (temp * pf_y[j] <= k){
                    temp *= pf_y[j];
                    j -= 1;
                }else{
                    break;
                }
            }
            if (temp == 1){
                cout << -1 << endl;return;
            }
            oper += 1;
        }
    }else if (i >= 0){
        int temp = 1;   
        while (i >= 0){
            if (temp * pf_x[i] <= k){
                temp *= pf_x[i];
                i -= 1;
            }else{
                break;
            }
        }
        if (temp == 1){
                cout << -1 << endl;return;
            }
        oper += 1;
    }
    
    cout << oper << endl;

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