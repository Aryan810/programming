#include <iostream>
#include <math.h>

#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        lli l, r;
        cin >> l >> r;
        lli n = (1+sqrt(1+8*(r-l)))/double(2);
        cout << n << endl; 

        // It works because a 'n' is fixed to be a long long int, 
        // even that, that formula gives a double and ceil of that will not be solution 
        // and floor of that will be a solution, it formula gives a integer exactly then that is a exact solution one can find by solving a diffrence series
        // by considering that the difference between terms is in AP of d=1, as we want size of array to be maximum.

    }

    return 0;
}