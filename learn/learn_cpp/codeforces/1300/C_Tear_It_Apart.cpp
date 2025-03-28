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
    string s;cin >> s;
    int minOfMax = 1e9;
    for (int i=0;i<26;i++){
        int maxgap = 0;
        int temp=0;
        int j = 0;
        // cout << (char)(i+'a') << " ";
        while (j < s.size()){
            while (j < s.size() && s[j] != i+'a'){
                j++;
                temp++;
            }
            // temp = 0;

            if (temp > maxgap){maxgap = temp;}
            temp = 0;
            j++;
        }
        // cout << maxgap<< endl;
        if (minOfMax > maxgap){
            minOfMax = maxgap;
        }
    }
    // cout << "-> " << minOfMax << endl;
    if (minOfMax <= 1){
        cout << minOfMax << endl;
    }else{

        cout << (int(log2(minOfMax)) + 1) << endl;
    }
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