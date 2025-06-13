#include <iostream>

using namespace std;
#define lli long long int
const int M = 1e9 + 7;
// binary exp by recursion ->
int bexp(int a, int b){
    if (b == 0){return 1;}
    if (a == 1){return 1;}
    int res = bexp(a, b/2); 
    if (b % 2 != 0){
        return (a * ((res * 1ll * res)%M))%M;
    }else{
        return (res*1ll*res)%M;
    }
}

int main(){
    int a = 2;
    int b = 400000;
    cout << bexp(a, b) << endl;
    return 0;
}