#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

double dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x1-x2)*(x1-x2)*1ll + (y1-y2)*(y1-y2)*1ll);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;cin >> n;
        vector< pair<int, int> > a(n);
        for (int i=0;i<n;i++){
            int x, y;cin >> x >> y;
            a[i] = {x, y};
        }
        int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
        double m = 1e10;
        for (int i=0;i<n;i++){
            if (m > dist(x2, y2, a[i].first, a[i].second)){
                m = dist(x2, y2, a[i].first, a[i].second);
            }
        }

        double d = dist(x1, y1, x2, y2);
        // cout << "dist: " << d << endl;
        bool ans = 1;
        if (d >= m){
            ans = 0;
        }
        cout << ((ans)?"YES":"NO") << endl;

        

    }

    return 0;
}