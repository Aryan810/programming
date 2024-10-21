#include <iostream>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

lli sum(lli a, lli b){
    return (a + b)*(b - a + 1)/2;
}

bool logic(lli n, lli k, lli x){
    lli m = sum(1, k);
    lli M = sum(n-k+1, n);
    if (x >= m && x <= M){
        // if (M-x <= x-m){
            lli gape = M-x;
            for (lli i=n-k+1;i<=n;i++){
                if (gape <= n-k){
                    return 1;
                }else{
                    gape -= n-k;
                }
            }
        // }
        // else{
        //     lli gape = M-x;
        //     for (lli i=n-k+1;i<=n;i++){
        //         if (gape <= n-k){
        //             return 1;
        //         }else{
        //             gape -= n-k;
        //         }
        //     }
        // }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        lli n, k, x;
        cin >> n >> k >> x;
        cout << (logic(n, k, x)?"YES":"NO") << endl;
    }

    return 0;
}