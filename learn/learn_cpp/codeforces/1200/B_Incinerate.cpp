#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

// here main part where i was lagging was to find minimum power of monsters after a certain index of health vector (when sorted)


bool logic(int & n, int & k, vector< pair<ll, ll> > & h, vll & mtill){
    ll dp = 0;
    vll h1(n);
    for (int i=0;i<h.size();i++){
        h1[i] = h[i].first;
    }
    while (k >= 0){
        dp += k;
        auto f = upper_bound(h1.begin(), h1.end(), dp);
        if (f == h1.end()){
            return 1;
        }
        // cout << (f-h.begin())<< " " << k << " " << *f << " " << m[*f] << endl;
        // auto comp = [&m](ll a, ll b){
        //     return (m[a] < m[b]);
        // };
        k -= mtill[f-h1.begin()];
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector< pair<ll, ll> > h(n);
        for (int i=0;i<n;i++){cin >> h[i].first;}
        for (int i=0;i<n;i++){
            ll p;
            cin >> p;
            h[i].second = p;
        }
        auto comp = [](pair<ll, ll> a, pair<ll, ll> b){
            return a.first < b.first;
        };
        sort(h.begin(), h.end(), comp);
        ll mn = 1e10;
        vll mtill(n);
        for (int i=n-1;i>=0;i--){
            if (h[i].second < mn){
                mn = h[i].second;
            }
            mtill[i] = mn;
        }
        cout << (logic(n, k, h, mtill)?"YES":"NO") << endl;

        

    }

    return 0;
}