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

const int M = 1e10 + 61;

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}

int hasher(string & s){
    int hash = 0;
    for (int i=0;i<s.size();i++){
        hash = (hash + (s[i]-'a')*(binexpiter(31, i)))%M;
    }
    return hash;
}

void solve(){

    string s1, s2;
    cin >> s1 >> s2;

    set<int> diff;
    for (int i=0;i<s1.size();i++){
        if (s1[i] != s2[i]){
            diff.insert(i);
        }
    }
    int t, q;cin >> t >> q;
    queue<pair<int, int> > blocks;
    vector<int> isblocked(s1.size(), 0);
    for (int i=0;i<q;i++){
        // cout << h1 << " " << h2 << " " << blocks.size() << endl;
        if (blocks.size() > 0){
            auto last = blocks.front();
            // cout << i << "  -  " << last.second << endl;
            if (i-last.second >= t){
                if (s2[last.first - 1] != s1[last.first - 1]){
                    diff.insert(last.first-1);
                }
                blocks.pop();
                isblocked[last.first-1] = 0;
            }
        }
        int type;cin >> type;
        if (type == 1){
            int pos;cin >> pos;
            blocks.push({pos, i});
            if (s1[pos-1] != s2[pos-1]){
                diff.erase(pos-1);
            }
            isblocked[pos-1] = 1;
        }else if (type == 2){
            int a, pos1;cin >> a >> pos1;
            int b, pos2;cin >> b >> pos2;
            if (isblocked[pos1-1] || isblocked[pos2-1]){continue;}
            if (a == 1 && b == 1){
                int f = s1[pos1-1]-'a';
                int s = s1[pos2-1]-'a';
                swap(s1[pos1-1], s1[pos2-1]);
                if (s1[pos1-1] == s2[pos1-1]){
                    if (diff.find(pos1-1) != diff.end()){
                        diff.erase(pos1-1);
                    }
                }else{
                    diff.insert(pos1-1);
                }
                if (s1[pos2-1] == s2[pos2-1]){
                    if (diff.find(pos2-1) != diff.end()){
                        diff.erase(pos2-1);
                    }
                }else{
                    diff.insert(pos2-1);
                }
            }else if (a == 2 && b == 2){
                int f = s2[pos1-1]-'a';
                int s = s2[pos2-1]-'a';
                swap(s2[pos1-1], s2[pos2-1]);

                if (s1[pos1-1] == s2[pos1-1]){
                    if (diff.find(pos1-1) != diff.end()){
                        diff.erase(pos1-1);
                    }
                }else{
                    diff.insert(pos1-1);
                }
                if (s1[pos2-1] == s2[pos2-1]){
                    if (diff.find(pos2-1) != diff.end()){
                        diff.erase(pos2-1);
                    }
                }else{
                    diff.insert(pos2-1);
                }

            }else if (a == 1 && b == 2){
                int f = s1[pos1-1]-'a';
                int s = s2[pos2-1]-'a';
                swap(s1[pos1-1], s2[pos2-1]);
                if (s1[pos1-1] == s2[pos1-1]){
                    if (diff.find(pos1-1) != diff.end()){
                        diff.erase(pos1-1);
                    }
                }else{
                    diff.insert(pos1-1);
                }
                if (s1[pos2-1] == s2[pos2-1]){
                    if (diff.find(pos2-1) != diff.end()){
                        diff.erase(pos2-1);
                    }
                }else{
                    diff.insert(pos2-1);
                }

            }else{
                int f = s2[pos1-1]-'a';
                int s = s1[pos2-a]-'a';
                swap(s2[pos1-1], s1[pos2-1]);
                if (s1[pos1-1] == s2[pos1-1]){
                    if (diff.find(pos1-1) != diff.end()){
                        diff.erase(pos1-1);
                    }
                }else{
                    diff.insert(pos1-1);
                }
                if (s1[pos2-1] == s2[pos2-1]){
                    if (diff.find(pos2-1) != diff.end()){
                        diff.erase(pos2-1);
                    }
                }else{
                    diff.insert(pos2-1);
                }
            }
        }else{
            if (diff.size() == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
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