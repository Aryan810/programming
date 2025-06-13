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

void solve(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<int, int> > chars;
    vector<int> num(26, 0);
    for (int i=0;i<n;i++){
        num[s[i]-'a'] += 1;
    }

    for (int i=0;i<26;i++){
        if (num[i] > 0){
            chars.push_back({num[i], i});
        }
    }

    sort(all(chars));

    vector<int> cum(chars.size()+1);
    cum[0] = 0;
    int sm = 0;
    for (int i=0;i<chars.size();i++){
        sm += chars[i].first;
        cum[i+1] = sm; 
    }
    pair<int, int> optimal = {1e18, 0};
    for (int i=1;i<=min(26ll, n);i++){
        if (n%i == 0){
            int oper = 0;
            int tobe = n/i;
            int stock = 0;
            string temp;
            if (i<chars.size()){
                stock += cum[chars.size()-i] - cum[0];
                oper += cum[chars.size()-i] - cum[0];
            }
            int m = chars.size();
            for (int j=0;j<i;j++){
                if (m-1-j >= 0){
                    if (chars[m-1-j].first > tobe){
                        stock += chars[m-1-j].first-tobe;
                        oper += chars[m-1-j].first-tobe;
                    }else if (chars[m-1-j].first < tobe){
                        if (stock >= tobe-chars[m-1-j].first){
                            stock -= tobe - chars[m-1-j].first;
                        }
                    }
                }else{
                    stock -= tobe;
                }
            }
            if (oper < optimal.first){
                optimal = {oper, i};
            }
        }
    }
    int tobe = n/optimal.second;
    vector<int> opers(26, 0);
    // for (auto ele: chars){
    //     cout << ele.first << " " << char(ele.second+'a') << endl;
    // }cout << endl;
    for (int i=0;i<(optimal.second);i++){
        if (i < chars.size()){
            opers[chars[chars.size()-1-i].second] = tobe;
        }else{
            for (int j=0;j<26;j++){
                if (opers[j] == 0){
                    opers[j] = tobe;
                    break;
                }
            }
        }
    }



    vector<int> done(n, 0);
    for (int i=0;i<s.size();i++){
        if (opers[s[i]-'a'] > 0){
            opers[s[i]-'a'] -= 1;
            done[i] = 1;
        }
    }
    // for (int i=0;i<26;i++){
    //     cout << char(i+'a') << " " << opers[i] << endl;
    // }
    // for (auto ele: done){
    //     cout << ele << " ";
    // }cout << endl;
    for (int i=0;i<n;i++){
        if (!done[i]){
            for (int j=0;j<26;j++){
                if (opers[j] > 0){
                    s[i] = char(j+'a');
                    opers[j] -= 1;
                    break;
                }
            }
        }
    }
    cout << optimal.first << endl;
    cout << s << endl;

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