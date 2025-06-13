#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t;
    // cin >> t;

    // while(t--){
        int n, s;
        cin >> s >> n;
        multimap<int, int> d;
        for (int i=0;i<n;i++){
            int x, y;
            cin >> x >> y;
            d.insert({x, y});
        }
        bool lost = false;
        for (auto drg: d){
            if (drg.first < s){
                s += drg.second;
            }else{
                cout << "NO" << endl;
                lost = 1;
                break;
            }
        }
        if (!lost){
            cout << "YES" << endl;
        }

    // }

    return 0;
}