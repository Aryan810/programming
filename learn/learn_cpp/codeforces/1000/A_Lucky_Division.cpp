#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool lucky(int n){
    while (n != 0){
        int x = n%10;
        // cout << x << endl;
        n /= 10;
        if (x != 4 && x != 7){
            return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int n;
    cin >> n;
    bool found = false;
    for (int i=1;i<=n;i++){
        if (n%i == 0){
            if (lucky(i)){
                cout << "YES" << endl;
                found = 1;
                break;
            }
        }
    }
    if (!found){
        cout << "NO" << endl;
    }
    

    

    return 0;
}