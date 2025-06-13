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

int sums(string s){
    int a=0;
    for(auto ele: s){
        a += ele-'0';
    }
    return a;
}

void solve(){
    int n;
    cin >> n;
    vector<string> odd;
    map<int, int> even2;
    map<int, int> for4;
    vector<string> even4;

    map<int, int> for1;
    map<int, int> for3;
    map<int, int> for5;
    vector<string> odd3;
    vector<string> odd5;
    rep(i, n){
        string s;
        cin >> s;
        if (s.size()&1){
            if (s.size() == 1){
                for1[sums(s)] += 1;
            }else if (s.size() == 3){
                for3[sums(s)] += 1;
                odd3.push_back(s);
            }else{
                for5[sums(s)] += 1;
                odd5.push_back(s);
            }

        }else{
            if (s.size() == 2){
                even2[sums(s)] += 1;
            }else{
                even4.push_back(s);
                for4[sums(s)] += 1;
            }
        }
    }
    int ans = 0;
    
    // for even

    // for 4+4
    for (auto ele: for4){
        if (ele.second > 1){
            ans += (ele.second)*(ele.second - 1);
        }
        ans += ele.second;

    }
    
    // for 2+2
    for (auto ele: even2){
        if (ele.second > 1){
            ans += (ele.second)*(ele.second - 1);
        }
        ans += ele.second;

    }

    // for 2+4 ans 4+2
    for (int i=0;i<even4.size();i++){
        int t = sums(even4[i]);
        int req1 = t-(even4[i][0]-'0')*2;
        int req2 = t-(even4[i].back()-'0')*2;
        ans += even2[req1] + even2[req2];
    }
    
    // for odd sized => 
    // for 1+1
    for (auto ele: for1){
        if (ele.second > 1){
            ans += (ele.second)*(ele.second - 1);
        }
        ans += ele.second;

    }
     // for 3+3
    for (auto ele: for3){
        if (ele.second > 1){
            ans += (ele.second)*(ele.second - 1);
        }
        ans += ele.second;

    }
    // for 5+5
    for (auto ele: for5){
        if (ele.second > 1){
            ans += (ele.second)*(ele.second - 1);
        }
        ans += ele.second;
    }
    // for 1+3 and 3+1
    for (int i=0;i<odd3.size();i++){
        int t = sums(odd3[i]);
        int req1 = t-(odd3[i][0]-'0')*2;
        int req2 = t-(odd3[i].back()-'0')*2;
        ans += for1[req1] + for1[req2];
    }

    // for 5+3, 3+5, 5+1 and 1+5
    for (int i=0;i<odd5.size();i++){
        int t = sums(odd5[i]);
        int req1 = t-(odd5[i][0]-'0' + odd5[i][1] - '0')*2;
        int req2 = t-(odd5[i][4]-'0' + odd5[i][3] - '0')*2;
        int req3 = t-(odd5[i][0]-'0')*2;
        int req4 = t-(odd5[i][4]-'0')*2;
        ans += for1[req1] + for1[req2] + for3[req3] + for3[req4];
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();

    return 0;
}