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

    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<lli> a(n);
        // unordered_map<int, int> s;
        for (int i=0;i<n;i++) cin >> a[i];
        // vector<lli> inter;
        int ans = 0;
        for (int i=0;i<m;i++){
            lli e1, e2;
            cin >> e1 >> e2;
            (a[e1-1] > a[e2 - 1])?(a[e1-1] = 1e9+7):(a[e2-1]=1e9+7);
            // inter.push_back(a[j-1]);
            // if (s[j] == 0){
            //     s[j] = 1;
            // }
        }
        // for (int i=0;i<n;i++){
        //     if (s[i+1] != 0){
        //         inter.push_back(a[i]);
        //     }
        // }
        sort(a.begin(), a.end());
        auto it = a.begin();
        while (k > 0 && it != a.end()){
            if (k >= *it){
                ans += 1;
                k-= *it;
            }else{
                break;
            }
            
            it++;
        }
        cout << ans << endl;
        

    }

    return 0;
}