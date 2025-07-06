// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

// struct Node{
//     int val;
//     struct Node * nxt;
//     struct Node * pre;
// };

// typedef struct Node Node;

// void insertEnd(Node * start, val){

// }

int ask(int a, int b){
    cout << "? " << a << " " << b << endl;cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve(){
    
    int n;
    cin >> n;
    vector<int> out(n, 0);
    vector<int> lst(n, 0);
    ordered_set<int> st;
    st.insert(1);   
    int curr = 2;
    while (curr < n){
        int res = ask(1, curr);
        if (res == 1){
            lst[curr] = curr;
            st.insert(curr++);
        }else if (res == 0){
            out[curr] = 1;
            lst[1] = curr++;
            break;
        }else{return;}
    }

    if (curr >= n){
        cout << "! ";
        for (int i=1;i<n;i++){
            cout << out[i] << " ";
        }cout << endl;cout.flush();
        return;
    }
    int i = 1;
    while (curr < n){
        i = i % st.size();
        auto it = st.find_by_order(i%st.size());
        if (st.size() == 1){
            while (curr < n){
                out[curr] = lst[*it];
                lst[*it] = curr++;
            }
            break;
        }
        int res = ask(curr, *it);
        if (res == 0){
            out[curr] = lst[*it];
            lst[*it] = curr++;
            i += 1;
        }else if (res == 1){
            st.erase(*it);
        }else{return;}
    }

    cout << "! ";
    for (int i=1;i<n;i++){
        cout << out[i] << " ";
    }cout << endl;cout.flush();



    
    

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}