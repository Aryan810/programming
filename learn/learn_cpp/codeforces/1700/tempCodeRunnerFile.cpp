// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){
    
    int n;
    cin >> n;
    if (n == 2){
        cout << "! " << 0 << " " << 1 << endl;return;
    }
    // first finding which element gives max XOR with first element;
    int i = 0;
    for (int j=1;j<n;j++){
        // for (auto & ele: s){
        cout << "? " << i << " " << i << " " << j << " " << j << endl;cout.flush();
        string st;
        cin >> st;
        char res = st[0];
        if (res == '<'){
            i = j;
        }
    }
    set<int> st;
    for (int j=0;j<n;j++){
        if (j != i){
            st.insert(j);
        }
    }
    int j = *st.begin();
    st.erase(j);
    set<int> maxes;
    while (st.size() > 0){
        int curr = *st.begin();
        cout << "? " << i << " " << j << " " << i << " " << curr << endl;cout.flush();

        string s;cin >> s;

        if (s == "<"){
            maxes.clear();
            maxes.insert(curr);
            j = curr;
        }else if (s == "="){
            maxes.insert(curr);
            j = curr;
        }
        st.erase(curr);
    }

    int smallest = *maxes.begin();
    maxes.erase(smallest);
    while (maxes.size() > 0){
        int curr = *maxes.begin();
        cout << "? " << smallest << " " << smallest << " " << curr << " " << curr << endl;cout.flush();
        string s;
        cin >> s;
        if (s == ">"){
            smallest = curr;
        }
        maxes.erase(curr);
    }



    cout << "! " << i << " " << smallest << endl;cout.flush();

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}
