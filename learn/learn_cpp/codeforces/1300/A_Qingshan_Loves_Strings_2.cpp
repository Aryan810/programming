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
    int n;
    cin >> n;
    string s;
    int sum = 0;
    for (int i=0;i<n;i++){
        char c;
        cin >> c;
        sum += c-'0';
        s.push_back(c);
    }
    if (n&1 || sum != n/2){
        cout << -1 << endl;
        return;
    }
    int i = 0;
    int j = n-1;
    vector<int> out;
    while (j > i){ 
        // cout << s << " : " << i << " " << j << endl;
        while (s[i] + s[j] == '1'+'0'){
            i += 1;
            j -= 1;
        }
        if (s[i]+s[j] == 2*'1'){
            out.push_back(i);
            s.insert(i, "01");
            j += 2;
        }else if (s[i]+s[j] == 2*'0'){
            s.insert(j+1, "01");
            out.push_back(j+1);
            j += 2;
        }
    }
    cout << out.size() << endl;
    for (int ele: out){
        cout << ele << " ";
    }cout << endl;
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