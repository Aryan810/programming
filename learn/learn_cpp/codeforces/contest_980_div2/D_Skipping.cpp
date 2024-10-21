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
        vector< pair<int, pair<int, bool> > > prob(n);
        vector<lli> cum(n+1);
        cum[0] = 0;
        lli sum = 0ll;
        for (int i=0;i<n;i++){
            int sc;
            cin >> sc;
            sum += sc;
            cum[i+1] = sum;
            prob[i] = {sc, {0, 0}};
        }
        int max_rch;
        cin >> max_rch;
        prob[0].second.first = max_rch;
        for (int i=1;i<n;i++){
            int x;
            cin >> x;
            prob[i].second.first = x;
            if (i <= max_rch){
                if (x > max_rch){
                    max_rch = x;
                }
            }
        }
        cout << max_rch << endl;



        

    }

    return 0;
}