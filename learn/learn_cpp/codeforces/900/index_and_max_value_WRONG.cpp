#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define lli long long int

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    lli n, m;
    char x;
    lli l, r;
    while(t--){
        cin >> n >> m;
        vector<lli> an(n);
        for(lli i=0ll;i<n;i++){cin >> an[i];}
        sort(an.begin(), an.end());
        for (lli i=0ll;i<m;i++){
            cin >> x >> l >> r;

            // vector<lli>::iterator lower, upper;
            // lower = lower_bound(an.begin(), an.end(), l);
            // upper = upper_bound(lower, an.end(), r); 
            // if (x == '+'){for_each(lower, upper, [](lli &n){n+=1;});}
            // else{for_each(lower, upper, [](lli &n){n-=1;});}
            // cout << an[n-1] << " ";

            // different approach
            vector<lli>::iterator lower, upper;
            lower = lower_bound(an.begin(), an.end(), l);
            upper = upper_bound(lower, an.end(), r);
            if (upper == an.end()){
                if (x == '+'){for_each(lower, upper, [](lli &n){n+=1;});}
                else{for_each(lower, upper, [](lli &n){n-=1;});}
            }
            cout << an[n-1] << " ";

        }
        cout << endl;

    }

    return 0;
}