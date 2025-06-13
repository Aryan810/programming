#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    // logic in note book

    while(t--){
        int n, k;
        cin >> n >> k;
        if (int(ceil(double(n)/2)-ceil(double(n-k)/2))%2 == 0.0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}   