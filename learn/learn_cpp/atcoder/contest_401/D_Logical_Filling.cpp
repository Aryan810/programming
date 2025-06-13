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

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
   
    int zeros = 0;
    for (int i=0;i<n;i++){
        if (s[i] == 'o'){
            zeros += 1;
        }
        if (i == 0 && s[i]=='?'){
            if (s[i+1] == 'o'){
                s[i] = '.';
            }
        }else if (i == n-1 && s[i]=='?'){
            if (s[i-1] == 'o'){
                s[i] = '.';
            }
        }else if (s[i] == '?'){
            if (s[i+1] == 'o' || s[i-1]=='o'){
                s[i] = '.';
            }
        }
        
    }
    int i = 0;
    if (zeros == k){
        for (int i=0;i<n;i++){
            if (s[i] == '?'){
                cout << '.';
            }else{
                cout << s[i];
            }
        }
        cout << endl;return;
    }
    while (i < n){
        if (s[i] == '?'){
            int num = 0;
            while (i < n && s[i] == '?'){
                num += 1;
                i += 1;
            }
            zeros += ((num+1)/2);
        }else{
            i += 1;
        }
    }

    if (zeros > k){
        cout << s << endl;
    }else{
        i = 0;
        while (i < n){
            if (s[i] == '?'){
                int num = 0;
                int f = i;
                while (i < n && s[i] == '?'){
                    num += 1;
                    i += 1;
                }
                if (num&1){
                    bool z = 1;
                    while (f < n && s[f] == '?'){
                        if (z){
                            s[f] = 'o';
                            z = 0;
                        }else{
                            s[f] = '.';
                            z = 1;
                        }
                        f += 1;
                    }
                }
            }else{
                i += 1;
            }
        }
        cout << s << endl;
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}