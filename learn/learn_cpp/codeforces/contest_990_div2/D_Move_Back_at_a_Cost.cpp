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

    int t;
    cin >> t;

    while(t--){
        ll n;cin >> n;
        vll a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        multiset< pair<int, int> > s;
        for (int i=0;i<n;i++){
            s.insert({a[i], i});
        }

        int curr = s.begin()->second;
        vi ans;
        ans.push_back(s.begin()->first);
        s.erase(s.begin());
        while (s.size() > 0){
            auto it = s.begin();
            if (it->second < curr){
                auto x = it->first;
                s.erase(it);
                s.insert({x+1, n});
            }else if (it->second > curr){
                curr = it->second;
                ans.push_back(it->first);
                s.erase(it);
            }else if (it->second == curr){
                ans.push_back(it->first);
                s.erase(it);
            }
        }
        for (int i=0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        }

    return 0;
}