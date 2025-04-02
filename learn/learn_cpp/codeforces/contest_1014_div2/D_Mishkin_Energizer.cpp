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

void helper(int & a, int & b, int & c, int & sz, int i, vector<int> & out, int l, int r){
    // cout << l << " " << 6-l-r << " " << r << " " << a << " " << b << " " << c << endl;

    if (a == 0 && (b == 0 && c == 0)){
        return;
    }
    // cout << "I: " << i << endl;
    if (l == 1 && r == 2){
        if (b >= a){
            b -= 1;
            sz += 1;
            out.push_back(i);
            helper(a, b, c, sz, i, out, 1, 3);
        }else{
            a -= 1;
            sz += 1;
            out.push_back(i+1);
            helper(a, b, c, sz, i+1, out, 3, 2);
        }
    }else if (l == 2 && r == 1){
        if (b >= a){
            b -= 1;
            sz += 1;
            out.push_back(i+1);
            helper(a, b, c, sz, i+1, out, 3, 1);
        }else{
            a -= 1;
            sz += 1;
            out.push_back(i);
            helper(a, b, c, sz, i, out, 2, 3);
        }
    }else if (l == 1 && r == 3){
        if (a >= c){
            a -= 1;
            sz += 1;
            out.push_back(i+1);
            helper(a, b, c, sz, i+1, out, 2, 3);
        }else{
            c -= 1;
            sz += 1;
            out.push_back(i);
            helper(a, b, c, sz, i, out, 1, 2);
        }
    }else if (l == 3 && r == 1){
        if (a >= c){
            a -= 1;
            sz += 1;
            out.push_back(i);
            helper(a, b, c, sz, i, out, 3, 2);
        }else{
            c -= 1;
            sz += 1;
            out.push_back(i+1);
            helper(a, b, c, sz, i+1, out, 2, 1);
        }
    }else if (l == 2 && r == 3){
        if (b >= c){
            b -= 1;
            sz += 1;
            out.push_back(i+1);
            helper(a, b, c, sz, i+1, out, 1, 3);
        }else{
            c -= 1;
            sz += 1;
            out.push_back(i);
            helper(a, b, c, sz, i, out, 2, 1);
        }
    }else if (l == 3 && r == 2){
        if (b >= c){
            b -= 1;
            sz += 1;
            out.push_back(i);
            helper(a, b, c, sz, i, out, 3, 1);
        }else{
            c -= 1;
            sz += 1;
            out.push_back(i+1);
            helper(a, b, c, sz, i+1, out, 1, 2);
        }
    }
}

void solve(){

    int n;
    cin >> n;
    int a=0,b=0,c=0;
    string s;
    cin >> s;
    vi v(n);
    for(int i=0;i<n;i++){
        if (s[i] == 'T'){
            v[i] = 1;
            a += 1;
        }else if (s[i] == 'L'){
            v[i] = 2;
            b += 1;
        }else{
            v[i] = 3;
            c += 1;
        }
    }

    if (a == n || (b == n || c == n)){
        cout << -1 << endl;
        return;
    }
    a = n-a;
    b = n-b;
    c = n-c;
    vector<int> out;
    int sz = n;
    for (int i=0;i<n-1;i++){
        if (v[i] != v[i+1]){
            if (v[i] + v[i+1] == 3){
                out.push_back(i+1);
                c -= 1;
                n += 1;
                if (v[i] == 1){helper(a, b, c, n, i+1, out, 1, 2);}else{
                    helper(a, b, c, n, i+1, out, 2, 1);
                }
            }else if (v[i] + v[i+1] == 5){
                out.push_back(i+1);
                a -= 1;
                n += 1;
                if (v[i] == 2){helper(a, b, c, n, i+1, out, 2, 3);}else{
                    helper(a, b, c, n, i+1, out, 3, 2);
                }
            }else{
                out.push_back(i+1);
                b -= 1;
                n += 1;
                if (v[i] == 1){helper(a, b, c, n, i+1, out, 1, 3);}else{
                    helper(a, b, c, n, i+1, out, 3, 1);
                }
            }
            break;
        }
    }
    cout << out.size() << endl;
    for (int i=0;i<out.size();i++){
        cout << out[i] << endl;
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