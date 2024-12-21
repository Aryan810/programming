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

void solve(){
    int n;cin >> n;
    vector< set<int> > v(n);
    vector<int> occurence(51, 0);
    set<int> found;
    for (int i=0;i<n;i++){
        int sz;cin >> sz;
        set<int> x;
        for (int j=0;j<sz;j++){
            int y;
            cin >> y;
            x.insert(y);
            occurence[y] += 1;
            found.insert(y);
        }
        v[i] = x;
    }

    vector<int> scores(51, 0);
    for (int i=1;i<=50;i++){
        if (occurence[i] == 0){continue;}
        auto dupli = occurence;
        for (int j=0;j<n;j++){
            if (v[j].find(i) != v[j].end()){
                for (auto ele: v[j]){
                    dupli[ele] -= 1;
                    if (dupli[ele] == 0){
                        scores[i] += 1;
                    }
                }
            }
        }
        scores[i] = found.size() - scores[i];
    }
    cout << *(max_element(all(scores))) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}