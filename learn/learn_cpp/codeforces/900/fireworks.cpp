#include <iostream>
#include <vector>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        lli a, b, m;
        cin >> a >> b >> m;
        cout << ((m/a)+(m/b) + 2) << endl;

    }

    return 0;
}