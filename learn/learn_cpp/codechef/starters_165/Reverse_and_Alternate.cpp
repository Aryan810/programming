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
    cin >> s;
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += s[i]-'0';
    }
    if (n%2 == 0 && sum != n/2){
        cout << "No" << endl;return;
    }
    // is alternating
    vector<int> sames;
    for (int i=0;i<n-1;i++){
        if (s[i+1] == s[i]){
            sames.push_back(i);
        }
    }
    if (sames.size() > 2){
        cout << "No" << endl;
    }else if (sames.size() == 1){
        if (s[0] != s[sames[0]] || s[n-1] != s[sames[0]+1]){
            cout << "Yes" << endl;
        }
    }else if (sames.size() == 2){
        sort(all(sames));
        reverse(s.begin()+sames[0]+1, s.begin()+sames[1]+1);
        for (int i=0;i<n-1;i++){
            if (s[i+1] == s[i]){
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }else{
        cout << "Yes" << endl;
        return;
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