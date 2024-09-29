#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;
    int n, k;
    for (int i=0;i<t;i++){
        cin >> n >> k;
        int leaves = 1;
        for (int i=2;i<n+1;i++){
            leaves += pow(i, i);
        }
        // cout << "leaves 1: " << leaves << endl;
        for (int i=1;i<n;i++){
            if ((n - i) >= k){
                leaves -= pow(i, i);
            }
        }
        // cout << "leaves 1: " << leaves << endl;
        if (leaves%2 == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}