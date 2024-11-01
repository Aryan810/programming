#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

lli logic(vlli & a){
    lli ans = 0;
    for (int i=0;i<a.size()/2;i++){
        lli x = abs(a[i]-a[a.size()-1-i]);
        ans = gcd(ans, x);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<lli> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        cout << logic(a) << endl; 
    }

    return 0;
}