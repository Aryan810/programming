#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int logic(vll & a, int n, int twos){
    if (twos >= n){
        return 0;
    }
    int x = log2(n);
    int ext = (x*(x+1))/2;
    int oper = 0;
    int req = n-twos;
    // cout << req<< " " << x << endl;
    unordered_set<int> s;
    for (int i=1;i<=n;i++){s.insert(i);}
    for (int i=x;i>=1;i--){
        for (auto lft: s){
            if (lft%((ll)pow(2, i)) == 0){
                req -= i;
                s.erase(lft);
                oper += 1;
                if (req <= 0){
                    break;
                }
                
            }
        }
        if (req <= 0){
                    break;
                }
    }
    if (req <= 0){return oper;}
    else{return -1;}
    // if (ext >= n-twos){
    //     int req = n-twos;
    //     while (req > 0){
    //         req -= x;
    //         x--;
    //         oper += 1;
    //     }
    //     return oper;
    // }else{
    //     int left = n-twos-ext;
    //     for (int i=1;i<=n;i++){
    //         if ((i/2)%2 != 0 && i%2 == 0){
    //             left -= 1;
    //             oper += 1;
    //         }
    //     }
    //     if (left <= 0){
    //         return oper;
    //     }else{
    //         return -1;
    //     }
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vll a(n);
        int twos = 0;
        for (int i=0;i<n;i++){
            ll x;
            cin >> x;
            a[i] = x;
            while (x > 0){
                if (x%2 == 0){
                    twos += 1;
                }else{
                    break;
                }
                x = x/2;
            }
        }
        cout << logic(a, n, twos) << endl;

        

    }

    return 0;
}