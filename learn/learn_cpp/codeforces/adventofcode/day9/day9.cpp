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
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    inp >> s;

    // cout << s.size() << endl;
    ll j = 0;
    if (s.size()%2 != 0){
        s.push_back('0');
    }
    // for (ll i=0;i<s.size();i++){
    //     cout << s[i] << "";
    // }cout << endl;

    vector<ll> v;
    for (ll i=0;i<s.size()-1;i+=2){
        for (ll k=0;k<(s[i]-'0');k++){
            v.push_back(j);
        }
        j += 1;
        for (ll k=0;k<(s[i+1]-'0');k++){
            v.push_back(-1);
        }
    }
    // for (ll i=0;i<v.size();i++){
    //     cout << v[i] << " ";
    // }cout << endl;
    // cout << ms << endl;
    //     for (ll i=0;i<ms.size();i++){
    //     cout << ms[i] << "";
    // }cout << endl;
    unordered_set<int> done;
    j = v.size()-1;
    while (j > 0){
        ll i = 0;
        // while (v[i] != -1){i+=1;}
        while (v[j] == -1){j-=1;}
        ll length = 0;
        auto x = v[j];
        while (v[j] == x && v[j]!=-1){
            length += 1;
            j-=1;
        }
        for (ll i=0;i<=j;i++){
            if (v[i] == -1){
                ll l = 0;
                while (i <= j && v[i] == -1){
                    l += 1;
                    i += 1;
                }
                if (l >= length && done.find(x)==done.end()){
                    for (ll k=i-l;k<i-l+length;k++){
                        v[k] = x;
                    }
                    for (ll k=j+1;k<(j+length+1);k++){
                        v[k] = -1;
                    }
                    done.insert(x);
                    break;
                }
            }
        }
    }
    
    // cout << ms << endl;
    // cout << ms << endl;
    ll ans = 0;
    ll i = 0;
    while (i<v.size()){
        if (v[i] != -1){
            ans += i*(v[i]);
        }
        i += 1;
    }
    cout << ans << endl;
    inp.close();    
    return 0;
}