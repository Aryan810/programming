#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    int n;
    cin >> n;

    string s;
    bool right = 1;
    while (s.size() != n){
        if (right){
            int inp;
            // case 1
            cout << "? " << s << "1" << endl;
            cout.flush();
            cin >> inp;
            if (inp){
                s.push_back('1');
                continue;
            }

            // case 2:
            cout << "? " << s << "0" << endl;cout.flush();
            cin >> inp;
            if (inp){
                s.push_back('0');
                continue;
            }else{
                right = 0;
            }
        }else{
            int inp;
            // case 1
            cout << "? 1" << s << endl;cout.flush();
            cin >> inp;
            if (inp == -1){return;}
            if (inp){
                s.insert(s.begin(), '1');
                continue;
            }

            // case 2:
            if (s.size()+1 == n){
                s.insert(s.begin(), '0');
                break;
            }
            cout << "? 0" << s << endl;cout.flush();
            cin >> inp;
            if (inp == -1){return;}
            if (inp){
                s.insert(s.begin(), '0');
                continue;
            }else{
                break;
            }
        }
    }

    cout << "! " << s << endl;
    cout.flush();

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