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
const int N = 2*(1e5) + 2;
vector<int> prime(N, 1);

void solve(){

    int n;
    cin >> n;
    vector<int> primes;
    vector<vector<int> > primeafter;
    vector<int> temp;
    for (int i=1;i<=n;i++){
        if (prime[i]){
            primes.push_back(i);
            primeafter.push_back(temp);
            temp.clear();
        }else{
            temp.push_back(i);
        }
    }
    // if (n == 2){
    //     cout << "2 1\n";
    // }else if (n == 3){
    //     cout << "2 1 3\n";
    // }else if (n == 4){
    //     cout << "2 1 3 4\n";
    // }else if ()

    for (int i=0;i<primes.size();i++){
        cout << primes[i] << " ";
        for (auto ele: primeafter[i]){
            cout << ele << " ";
        }
    }
    for (int i=primes.back()+1;i<=n;i++){
        cout << i << " ";
    }cout << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime[0] = 0;
    prime[1] = 0;
    prime[2] = 1;

    for (int i=2;i<=N;i++){
        if (prime[i]){
            for (int j=2*i;j<=N;j+=i){
                prime[j] = 0;
            }
        }
    }
    // for (int i=2;i<20;i++){
    //     cout << prime[i] << " ";
    // }cout << endl;

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}