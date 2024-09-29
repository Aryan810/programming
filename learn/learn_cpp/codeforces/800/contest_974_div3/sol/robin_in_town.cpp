#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<long long> w(n);
        for (int i=0;i<n;i++){
            cin >> w[i];
        }

        sort(w.begin(), w.end());

        long long s = accumulate(w.begin(), w.end(), 0LL);

        int lth = int(double(n)/2) + 1;
        
        long long x = (2*n*w[lth-1])-s+1;

        if ((n == 1) || (n == 2)){cout << "-1" << endl;}else{
            if (x <= 0){
                cout << '0' << endl;
            }else{
                cout << x << endl;
            }
        }
            
        

    }

    return 0;
}