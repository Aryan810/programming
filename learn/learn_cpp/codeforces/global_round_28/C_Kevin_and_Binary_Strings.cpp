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
    string s;
    cin >> s;

    int optsz = s.size();
    for (int i=0;i<s.size();i++){
        if (s[i] == '0'){break;}
        optsz -= 1;
    }
    if (optsz == 0){
        cout << 1 << " " << s.size() << " " << 1 << " " << 1 << endl;
        return;
    }
    int fz = s.size()-optsz;

    int l = 0;
    int r = l+optsz-1;
    vector< pair< pair<int, int> , int> > v;
    set<pair<string, pair<int, int> > > order;
    while (r < s.size()){
        string out;
        for (int i=0;i<(r-l+1);i++){
            out.push_back((char)(((s[l+i]-'0')^(s[fz+i]-'0'))+'0'));
        }
        // cout << "out: " << out << " " << l << " " << r << endl;
        order.insert({out, {l, r}});
        l+=1;
        r+=1;
    }
    auto f = --order.end();
    cout << 1 << " " << s.size() << " " << ((f->second).first + 1) << " " << ((f->second).second + 1) << endl;
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