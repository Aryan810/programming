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

bool comp(array<ll, 3> & a, array<ll, 3> & b){
    if (a[0] == b[0]){
        if (a[1] != b[1]){return a[1] > b[1];}else{
            return a[2] < b[2];
        }
    }else{
        return a[0] < b[0];
    }
}

bool comp1(array<ll, 3> & a, array<ll, 3> & b){
    if (a[1] == b[1]){
        if (a[0] != b[0]){return a[0] < b[0];}else{
            return a[2] < b[2];
        }
    }else{
        return a[1] > b[1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        
        // taking input
        int n;cin >> n;
        vector< array<ll, 3> > a(n);
        for (int i=0;i<n;i++){
            ll l, r;
            cin >> l >> r;
            a[i][0] = l;
            a[i][1] = r;
            a[i][2] = i;
        }
        auto b = a;
        //sorting
        sort(all(a), comp);
        // cout << 1 << endl << endl;
        // for (int i=0;i<n;i++){
        //     cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
        // }
        set< pair<ll, ll> > s;
        vector<pair<ll, ll> > out(n);
        for (int i=0;i<n;i++){
            if (!s.empty()){
                auto x = s.lower_bound({a[i][1], 0});
                if (x == s.end()){
                    out[a[i][2]] = {0, 0};
                }else{
                    if (i+1 < n && (a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1])){
                        out[a[i][2]] = {0, 0};
                    }else{
                        out[a[i][2]] = {0, x->first};
                    }
                }
            }else{
                out[a[i][2]] = {0, 0};
            }
            s.insert({a[i][1], i});
        }

        s.clear();
        sort(all(a), comp1);
        // cout << 2 << endl << endl;
        // for (int i=0;i<n;i++){
        //     cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
        // }
        for (int i=0;i<n;i++){
            if (!s.empty()){
                auto x = s.lower_bound({a[i][0], 0});
                if (x->first != a[i][0] && x == s.begin()){
                    out[a[i][2]] = {0, 0};
                }else{
                    // if (a[i][0] < x->first){x--;}
                    if ((x == s.end() || x->first != a[i][0]) && (x != s.begin())){
                        x--;
                    }

                    // x--;
                    if (out[a[i][2]].first + out[a[i][2]].second != 0){
                        if (i+1 < n && (a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1])){
                            out[a[i][2]] = {0, 0};
                        }else{
                            out[a[i][2]] = {x->first, out[a[i][2]].second};
                        }
                    }
                }
            }else{
                out[a[i][2]] = {0, 0};
            }
            s.insert({a[i][0], i});
        }

        for (int i=0;i<n;i++){
            // cout << out[i].first << " " << out[i].second << endl;
            cout << ((out[i].first + out[i].second != 0)?(out[i].second - out[i].first - (b[i][1]-b[i][0])):0)<< endl;
        }
    }

    return 0;
}