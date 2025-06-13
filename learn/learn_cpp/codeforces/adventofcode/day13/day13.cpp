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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    vector< array<pair<ll, ll>, 3> > v;
    while (1){
        string s1, s2, s3;
        getline(inp, s1);
        getline(inp, s2);
        getline(inp, s3);
        string emt;
        getline(inp, emt);
        if (s1 == ""){break;}
        cout << s1 << " " << s2 << " " << s3 << endl;
        array< pair<ll, ll>, 3> a;
        a[0] = {stoi(s1.substr(12, 2)), stoi(s1.substr(18, 2))};
        a[1] = {stoi(s2.substr(12, 2)), stoi(s2.substr(18, 2))};
        ll x = 9;
        string px, py;
        while (s3[x] <= '9' && s3[x] >= '0'){
            px.push_back(s3[x]);
            x += 1;
        }
        x += 4;
        py = s3.substr(x, s3.size()-x);
        a[2] = {stoi(px), stoi(py)};
        v.push_back(a);
    }
    for (int i=0;i<v.size();i++){
        v[i][2].first += 10000000000000;
        v[i][2].second += 10000000000000;
    }
    ll ans = 0;
    for (auto a: v){
        if (a[1].second == a[0].second && a[1].first == a[0].first){
            if (a[2].second*(a[0].first + a[1].first) == a[2].first*(a[0].second + a[1].second)){
                auto x = (a[2].first)/(a[0].first + a[1].first);
                if (x*(a[0].first + a[1].first) == a[2].first){
                    ans += x;
                }
            }
        }else{
            ll a1 = ((a[1].first)*(a[2].second) - (a[2].first)*(a[1].second))/((a[1].first)*(a[0].second) - (a[0].first)*(a[1].second));
            ll b1 = ((a[0].second)*(a[2].first) - (a[2].second)*(a[0].first))/((a[1].first)*(a[0].second) - (a[0].first)*(a[1].second));
            if ((a1*(((a[1].first)*(a[0].second) - (a[0].first)*(a[1].second))) == (((a[1].first)*(a[2].second) - (a[2].first)*(a[1].second)))) && 
                (b1*(((a[1].first)*(a[0].second) - (a[0].first)*(a[1].second))) == (((a[0].second)*(a[2].first) - (a[2].second)*(a[0].first))))){
                ans += 3*a1 + b1;
            }
        }
    }
    cout << ans << endl;
    inp.close();
    return 0;
}