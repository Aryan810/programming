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
    string a, b;
    cin >> a >> b;
    vector<int> as, cs;
    array<int, 3> bef = {0, 0, 0};
    array<int, 3> aft = {0, 0, 0};
    for (int i=0;i<n;i++){
        if (a[i] == 'a'){bef[0]+=1;}else if (a[i] == 'b'){bef[1]+=1;}else{
            bef[2]+=1;
        }
        if (b[i] == 'a'){aft[0]+=1;}else if (b[i] == 'b'){aft[1]+=1;}else{
            aft[2]+=1;
        }
    }
    if (bef != aft){
        // cout << "here!" << endl;
        cout << "NO" << endl;
        return;
    }
    for (int i=0;i<a.size();i++){
        if (a[i] == 'a'){
            as.push_back(i);
        }else if (a[i] == 'c'){
            cs.push_back(i);
        }
    }
    // for 'a';
    int i=as.size()-1;
    int k = 0;
    for (int j=b.size()-1;j>=0;j--){
        if (b[j] == 'a'){
            if (i >= 0 && as[i] > j){
                cout << "NO" << endl;
                return;
            }
            i--;
        }
    }

    for (int j=0;j<b.size();j++){
        if (b[j] == 'c'){
            if (k < cs.size() && cs[k] < j){
                cout << "NO" << endl;
                return;
            }
            k++;
        }
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