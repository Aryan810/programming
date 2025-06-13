#include <iostream>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

int operations(int n, int k){
    if (k == 1){
        return n;
    }
    int x = 0;
    while (n != 0){
        x += n%k;
        n = n/k;
    }
    return x;
}
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        cout << operations(n, k) << endl;

    }

    return 0;
}
