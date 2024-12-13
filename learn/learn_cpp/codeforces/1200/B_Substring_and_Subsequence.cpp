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
        string a, b;cin >> a >> b;
        pair<int, int> p = {b.size(), 0};
        for (int j=0;j<b.size();j++){
            auto x = a.find(b[j]);
            if (x < a.size()){
                int n = 1;
                for (int i=j+1;i<b.size();i++){
                    auto y = a.substr(x+1, a.size()-x-1).find(b[i]);
                    if (y >= a.size()){break;}
                    x += y+1;
                    n += 1;
                }
                if (p.second < n){
                    p = {j, n};
                }
            }
        }
        cout << (a.size() + b.size()-p.second) << endl;

    }

    return 0;
}