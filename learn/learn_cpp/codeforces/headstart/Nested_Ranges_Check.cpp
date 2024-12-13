#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool comp(array<int, 3> & a, array<int, 3> & b){
    if (a[0] == b[0]){
        return a[1] > b[1];
    }else{
        return a[0] < b[0];
    }
}

bool comp1(array<int, 3> & a, array<int, 3> & b){
    if (a[0] == b[0]){
        return a[1] < b[1];
    }else{
        return a[0] > b[0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    oset< pair<int, int> > s;
    vector< array<int, 3> > a(n);

    for (int i=0;i<n;i++){
        int l, r;cin >> l >> r;
        a[i] = {l, r, i};
    }
    vector<int> ans(n);
    sort(all(a), comp1);
    for (int i=0;i<n;i++){
        if (s.empty()){
            ans[a[i][2]] = 0;
        }else{
            auto x = s.order_of_key({a[i][1] + 1, 0});
            ans[a[i][2]] = x;
        }
        s.insert({a[i][1], i});
    }
    
    // number of intervals which are its superset.
    rep(i, n){
        cout << ans[i] << " ";
    }cout <<endl;
    ans.clear();
    s.clear();
    sort(all(a), comp);
    // for (int i=0;i<n;i++){
    //     cout << a[i].first << " " << a[i].second << endl;
    // }
    for (int i=0;i<n;i++){
        if (s.empty()){
            ans[a[i][2]] = 0;
        }else{
            auto x = s.order_of_key({a[i][1], 0});
            ans[a[i][2]] = s.size() - x;
        }
        s.insert({a[i][1], i});
    }


    // number of intervals which are its superset.
    rep(i, n){
        cout << ans[i] << " ";
    }cout <<endl;

    return 0;
}
