#include <iostream>
#include <vector>
#include <math.h>
#define lli long long int

using namespace std;

lli no_of_operations(lli n, lli k){
    // if (n <= k){
    //     if (n <= 1){
    //         return 0;
    //     }
    //     return 1;
    // }
    // return int(double(n)/k)+1;
    lli operations = (n-1)/(k-1);
    if ((n-((k-1)*operations) > 1)){
        operations += 1;
    }
    return operations;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        lli n, k;
        cin >> n >> k;
        cout << no_of_operations(n, k) << endl;
    
    }

    return 0;
}