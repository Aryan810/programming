#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool check(ll sum, vi & k){
    ll s = sum;
    for (int i=0;i<k.size();i++){
        s -= sum/k[i] + 1;
    }
    return (s >= 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vi k(n);
        for (int i=0;i<n;i++){
            cin >> k[i];
        }

        vll x(n, 1);

        ll low = n;
        ll high = 50*10e9;
        while (low < high){
            ll mid = (low + high)/2;
            if (check(mid, k)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        if(!check(high, k)){
            cout << -1 << endl;
        }else{
            ll s = high;
            for (int i=0;i<n-1;i++){
                cout << (high/k[i] + 1) << " ";
                s -= high/k[i] + 1;
            }
            cout << s << " ";
            cout <<endl;
        }
    }

    return 0;
}