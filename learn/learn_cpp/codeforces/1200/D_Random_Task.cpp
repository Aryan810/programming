#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

ll binexpiter(ll a, ll b){
    ll ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

ll factorial(ll a){
    ll ans = 1;
    for (int i=1;i<=a;i++){
        ans *= i;
    }
    return ans;
}

ll func(ll x, ll k){
    ll a, b;
    a = log2(x);
    ll ans = 0;

    if (a >= k){
        ans += factorial(a)/(factorial(5-k)*factorial(k));
    }
    b = log2(x-binexpiter(2, a));
    
    if (b >= k-1){
        ans += factorial(b)/(factorial(k-1)*factorial(b-k+1));
    }
}

ll kinbin(ll n, ll k){
    return func(2*n, k) - func(n, k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll m, k;
    cin >> m >> k;

    ll low = 1;
    ll high = 1e18;

    while (low < high){
        ll mid = (low + high)/2;
        if (kinbin(mid, k) > m){
            high = mid-1;
        }else if(kinbin(mid, k) < m){
            low = mid + 1;
        }else{
            high = mid;
            break;
        }
    }
    cout << high << endl;

    return 0;
}