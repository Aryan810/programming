#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void logic(unordered_map<lli, unordered_set<lli> > & b, lli siz, lli & ans){
    if (siz > ans){
        ans = siz;
    }
    auto k = b.find(siz);
    if (k != b.end()){
        auto c = b[siz];
        b.erase(k);
        for (auto x: c){
            logic(b, x, ans);
        }
    }else{
        return;
    }
}       

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vlli a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        unordered_map<lli, unordered_set<lli> > b;
        for (int i=1;i<n;i++){
            b[a[i]+i].insert(a[i] + 2*i);
        }
        // for (auto x: b){
        //     cout << x.first << endl;
        //     for (auto y: x.second){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        lli siz = n;
        lli ans = 0;
        logic(b, siz, ans);
        cout << ans << endl;
    }
    return 0;
}