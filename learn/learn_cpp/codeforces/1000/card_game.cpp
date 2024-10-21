#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int comp(int a, int b){
    if (a == b){
        return 0;
    }
    return ((a > b)?1:-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        int ways = 0;

        ways += (comp(a1, b1) + comp(a2, b2) <= 0)?0:1;
        ways += (comp(a1, b2) + comp(a2, b1) <= 0)?0:1;
        ways += (comp(a2, b1) + comp(a1, b2) <= 0)?0:1;
        ways += (comp(a2, b2) + comp(a1, b1) <= 0)?0:1;
        cout << ways << endl;

    }

    return 0;
}