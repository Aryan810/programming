#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b)
{
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    vector<int> n(t);
    vector<int> k(t);
    for (int i=0;i<t;i++){
        cin >> n[i];
    }
    for (int i=0;i<t;i++){
        cin >> k[i];
    }

    for (int i=0;i<t;i++){
        cout << power(2, k[i]) << endl;
    }
    return 0;
}