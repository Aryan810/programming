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
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct dsu{
    int n;
    vector<int> parent, set_size;
    dsu(int n){
        this->n = n;

        parent.resize(n);

        set_size.resize(n);

        for (int i = 0; i < n; i++){

            parent[i] = i;

            set_size[i] = 1;
        }
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent [v] = find (parent [v]);
    }
    void set_union (int a, int b){
        a = find(a);
        b = find (b);
        if(a != b){
            if(set_size[a] < set_size [b]){
                swap (a, b) ;
            }
            parent[b] = a;
            set_size[a] += set_size[b];
        }   
    }
};

void solve(){

    int n;
    cin >> n;
    string s;
    int zeros = 0;
    // vector<pair<string, array<int, 2> > > poss;
    vector<int> dta;
    // int last = -1; 
    for (int r=2;r<=(n);r++){
        cout << "? " << 1 << " " << r << endl;cout.flush();
        int x;
        cin >> x;
        dta.push_back(x);
        // if (r == 2){
        //     if (x == 0){
        //         poss.push_back({"11", {0, 0}});
        //         poss.push_back({"10", {1, 0}});
        //         poss.push_back({"00", {2, 0}});
        //     }else{
        //         poss.push_back({"01", {1, 1}});
        //     }
        // }else{
        //     vector<pair<string, array<int, 2> > >  toadd;
        //     for (int i=0;i<poss.size();i++){
        //         auto p = poss[i];
        //         if (p.second[1] == -1){continue;}
        //         if (x == p.second[1]){
        //             if (p.second[0] == 0){
        //                  // case 1 -> added a one.
        //                 pair<string, array<int, 2> > q = p;
        //                 q.first.push_back('1');
        //                 toadd.push_back(q);

        //                 // case 2 -> added a zero.
        //                 p.first.push_back('0');
        //                 p.second[0] += 1;

        //             }else{
        //                 p.first.push_back('0');
        //                 p.second[0] += 1;
        //             }
        //         }else if (x == p.second[0] + p.second[1]){
        //             p.first.push_back('1');
        //             p.second[1] += p.second[0];
        //         }else{
        //             p.second[1] = -1;
        //         }
        //         poss[i] = p;
        //     }
        //     for (auto ele: toadd){
        //         poss.push_back(ele);
        //     }
        // }
    }
    int i = 0;
    int j = 0;
    
    // finding first non-zero
    for (i=0;i<dta.size();i++){
        if (dta[i] != 0){
            break;
        }
    }

    if (i >= dta.size()){
        cout << "! IMPOSSIBLE" << endl;cout.flush();return;
    }

    int freqz = dta[i];
    int spaces = i + 1;
    if (freqz > spaces){
        cout << "! IMPOSSIBLE" << endl;cout.flush();return;
    }
    string out;
    for (int k=0;k<(spaces-freqz);k++){
        out.push_back('1');
    }
    for (int k=0;k<(freqz);k++){
        out.push_back('0');
        zeros += 1;
    }
    out.push_back('1');
    j = i;
    while (j < dta.size() && i < dta.size()){
        while (j < dta.size() && dta[j] == dta[i]){
            j += 1;
        }

        if (j >= dta.size()){
            for (int k=0;k<(j-i-1);k++){
                out.push_back('0');
                zeros += 1;
            }
            break;
        }

        int morezerosreq = dta[j] - dta[i] - zeros;
        if (morezerosreq >= 0 && morezerosreq == (j-i-1)){
            for (int k=0;k<(j-i-1);k++){
                out.push_back('0');
                zeros += 1;
            }
            out.push_back('1');
            i = j;
        }else{
            cout << "! IMPOSSIBLE" << endl;cout.flush();return;
        }
    }
    cout << "! " << out << endl;cout.flush();
    // cout << endl;
    // if (possibles.size() > 1 || possibles.size() == 0){
    //     cout << "! IMPOSSIBLE" << endl;cout.flush();
    // }else{
    //     cout << "! " << possibles[0] << endl;cout.flush();
    // }

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