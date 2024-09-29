#include <iostream>
#include <vector>
#include <math.h>
#include <set>

#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        lli n, x, y;
        cin >> n >> x >> y;
        
        if (y >= x){
            cout << (lli)ceil(double(n)/x) << endl;
        }else{
            cout << (lli)(ceil(double(n)/y)) << endl;
        }

    }

    return 0;
}