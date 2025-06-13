#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ll x, y, k;
        cin >> x >> y >> k;
        // while (k > 0){
        //     // cout << x << endl;
        //     ll p = y - x%y;
        //     // cout << k << endl;
        //     if (x == 1 && k%p == 0){
        //             x += k%p;
        //             break;
        //         }
        //     if (x%y != 0){
        //         k -= p;
        //         if (k < 0){
        //             x += k + p;
        //             break;
        //         }else{
        //             x += p;
        //         }
        //         while (x%y == 0){
        //             x /= y;
        //         }
        //     }else{
        //         // cout <<"here" << endl;
        //         // x += y-1;
        //         // k -= y-1;
        //         if (k >= y-1){
        //             x += y-1;
        //             while (x%y == 0){
        //                 x /= y;
        //             }
        //             k -= y-1;
        //         }else{
        //             x += k;
        //             k = 0;
        //             break;
        //         }
        //     }
        // }
        // cout << "x: " << x << endl;

        while (k > 0){
            ll p = y - x%y;
            if (x == 1){
                x += k%p;
                break;
            }
            if (k < p){
                x += k;
                k -= p;
                break;
            }else{
                x += p;
                while (x%y == 0){
                    x /= y;
                }
                k -= p;
            }
        }

        cout << x << endl;
        

    }

    return 0;
}