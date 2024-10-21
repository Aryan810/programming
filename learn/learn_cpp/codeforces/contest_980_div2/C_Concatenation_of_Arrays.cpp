#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return (a.first + a.second)<(b.first + b.second);
}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector< pair<int, int> > a(n);
        for (int i=0;i<n;i++){
            int x, y;
            cin >> x >> y;
            a[i] = {x, y};
        }
        sort(a.begin(), a.end(), comp);
        for (auto e: a){
            cout << e.first << " " << e.second << " ";
        }
        cout << endl;

    }

    return 0;
}