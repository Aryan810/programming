#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int logic(int a, int b){
    int l = ((lli)a*(lli)b)/(lli)gcd(a, b);
    int lcf = 1;
    for (int i=2;i*i<=max(a, b);i++){
        if (a%i == 0 || b%i == 0){lcf = i;break;}
    }
    if (lcf == 1){
        lcf = (min(a, b)==1)?max(a, b):min(a, b);
    }
    // cout << lcf << endl;
    // cout << l << endl;
    return ((l == a || l == b)?(l*(lcf)):(l));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        cout << logic(a, b) << endl;
        

    }

    return 0;
}