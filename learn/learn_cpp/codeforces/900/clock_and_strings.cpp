#include <iostream>
#include <vector>
#include <math.h>
#define lli long long int

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        bool found = 0;
        for (int i=a;i!=b;(i == 12)?(i=1):i++){
            if ((i == c) || (i == d)){
                found = found?0:1;
            }
        }
        cout << (found?"YES":"NO") << endl;
    }

    return 0;
}