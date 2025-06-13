#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool logic(vector<ll> & a, int n){
    if (n == 3){
        return (2*a[1] == (a[0]+a[2]));
    }
    ll odd = (ll)ceil(n/double(2));
    ll even = n/2;
    ll s1 = 0;
    ll s2 = 0;
    for (int i=0;i<n;i+=2){
        s1 += a[i];
        // cout << "s1: " << s1 << endl;

    }
    for (int i=1;i<n;i+=2){
        s2 += a[i];
        // cout << "s2: " << s1 << endl;

    }
    // cout << s1 << " " << s2 << endl;
    // cout << odd << " " << even << endl;
    if (s2*odd != s1*even){
        return 0;
    }
    if (s1 != (ll)(s1/odd)*odd || s2 != (ll)(s2/even)*even){
        return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;cin >> n;
        vll a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        cout << ((logic(a, n)?"YES":"NO")) << endl;
        

    }

    return 0;
}