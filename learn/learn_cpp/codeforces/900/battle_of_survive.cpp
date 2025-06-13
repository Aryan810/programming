#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <set>

#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        lli n;
        cin >> n;
        vector<lli> ratings(n);
        for (lli i=0ll;i<n;i++){cin >> ratings[i];}

        cout << ratings[n-1ll]-ratings[n-2ll]+accumulate(ratings.begin(), ratings.end()-2ll, 0ll)<< endl;
    }

    return 0;
}