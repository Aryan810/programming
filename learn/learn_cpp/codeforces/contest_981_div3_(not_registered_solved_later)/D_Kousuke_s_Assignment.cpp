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
        int n;
        cin >> n;
        lli sum = 0;
        vector<lli> cum(n+1);
        cum[0] = 0ll;
        for (int i=1;i<=n;i++){
            int x;
            cin >> x;
            sum += x;
            cum[i] = sum;
        }
        unordered_map<int, int>* m = new unordered_map<int, int>;
        lli ans = 0;
        for (int i=0;i<n+1;i++){
            if ((*m)[cum[i]] == 0){
                (*m)[cum[i]] = 1;
            }else{
                delete m;
                m = new unordered_map<int, int>;
                ans += 1;
            }   
        }
        cout << ans << endl;
        

    }

    return 0;
}