#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t;
    // cin >> t;

    // while(t--){
        int n;
        cin >> n;
        vector< pair<ll, ll> > a(n);
        for (int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
        auto c1 = [](pair<ll, ll> a, pair<ll, ll> b){
            return (a.first != b.first)?(a.first<b.first):(a.second>b.second);
        };
        ll m = 1e18, M = 0;
        auto b = a;
        sort(b.begin(), b.end(), c1);
        // auto c3 = [](pair<ll, ll> a, pair<ll, ll> b){
        //     return (a.first == b.first)?(a.second > b.second):(0);
        // };
        // sort(b.begin(), b.end(), c3);

        map< pair<ll, ll>, pair<bool, bool> > ans;
        // for (auto k: b){
        //     cout << k.first << " " << k.second << endl;
        // }
        for (int i=n-1;i>=0;i--){
            if (m <= b[i].second){
                ans[b[i]].first = 1;

            }else{
                ans[b[i]].first = 0;
            }
            if (b[i].second < m){
                m = b[i].second;
            }
            if (b[i].second > M){
                M = b[i].second;
            }
        }
        auto c2 = [](pair<ll, ll> a, pair<ll, ll> b){
            return (a.first != b.first)?(a.first>b.first):(a.second<a.second);
        };
        m = 1e18, M = 0;
        sort(b.begin(), b.end(), c2);
        for (int i=n-1;i>=0;i--){
            if (b[i].second <= M){
                ans[b[i]].second = 1;

            }else{
                ans[b[i]].second = 0;
            }
            if (b[i].second < m){
                m = b[i].second;
            }
            if (b[i].second > M){
                M = b[i].second;
            }
        }

        for (int i=0;i<n;i++){
            cout << ans[a[i]].first << " ";
        }cout << endl;

        for (int i=0;i<n;i++){
            cout << ans[a[i]].second << " ";
        }cout << endl;



    // }

    return 0;
}