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
    int t;cin >> t;
    string a;cin >> a;
    int n=0, s=0, e=0, w=0;
    map<char, vector<int> > m;
    for (int i=0;i<t;i++){
        if (a[i] == 'N'){n++;}
        else if (a[i] == 'S'){s++;}
        else if (a[i] == 'E'){e++;}
        else if (a[i] == 'W'){w++;}
        m[a[i]].push_back(i);
    }

    if (((max(n, s)-min(n, s))%2 == 0) && ((max(e, w)-min(w, e))%2 == 0)){
        if (n == s && e == w){
            if (n+e <= 1){
                cout << "NO" << endl;
                return;
            }
        }
        vector<char> out(t);
        int rover=0;
        while ((min(m['N'].size(), m['S'].size())>0)){
            out[m['N'].back()] = 'R';
            m['N'].pop_back();
            out[m['S'].back()] = 'R';
            m['S'].pop_back();
            rover += 1;

            if ((min(m['N'].size(), m['S'].size()) <= 0)){
                break;
            }
            out[m['N'].back()] = 'H';
            m['N'].pop_back();
            out[m['S'].back()] = 'H';
            m['S'].pop_back();
        }
        
        while ((min(m['E'].size(), m['W'].size())>0)){
            if (rover == 0){
                out[m['E'].back()] = 'R';
                m['E'].pop_back();
                out[m['W'].back()] = 'R';
                m['W'].pop_back();
            }

            if ((min(m['E'].size(), m['W'].size()) <= 0)){
                break;
            }
            out[m['E'].back()] = 'H';
            m['E'].pop_back();
            out[m['W'].back()] = 'H';
            m['W'].pop_back();
        }
        if (m['S'].size() > 0){
            while (m['S'].size() > 0){
                out[m['S'].back()] = 'R';
                m['S'].pop_back();
                out[m['S'].back()] = 'H';
                m['S'].pop_back();
            }
        }else if (m['N'].size() > 0){
            while (m['N'].size() > 0){
                out[m['N'].back()] = 'R';
                m['N'].pop_back();
                out[m['N'].back()] = 'H';
                m['N'].pop_back();
            }
        }
        if (m['E'].size() > 0){
            while (m['E'].size() > 0){
                out[m['E'].back()] = 'R';
                m['E'].pop_back();
                out[m['E'].back()] = 'H';
                m['E'].pop_back();
            }
        }else if (m['W'].size() > 0){
            while (m['W'].size() > 0){
                out[m['W'].back()] = 'R';
                m['W'].pop_back();
                out[m['W'].back()] = 'H';
                m['W'].pop_back();
            }
        }
        for (auto c: out){
            cout << c << "";
        }cout << endl;
        // cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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