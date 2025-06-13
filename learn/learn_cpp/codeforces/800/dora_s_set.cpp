#include <iostream>

#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;
    int l, r, n;
    int k;
    for (int i=0;i<t;i++){
        cin >> l >> r;
        n = r - l + 1;
        // cout << "l: " << l << " r: " << r << " n: " << n << endl;
        if (n < 3){
            k = 0;
        }else{
            if (l%2 == 0){
                n -= 1;
                // cout << "yes" << endl;
            }
            // cout << "test " << float(n)/4 << " " << (float(n)/4 - int(float(n)/4)) << endl;
            if ((float(n)/4 - int(float(n)/4)) <= 0.5){
                k = int(float(n)/4);
            }else{
                k = int(float(n)/4) + 1;
            }
        }
        cout << k << endl;
    }

    return 0;
}