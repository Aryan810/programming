#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int logic(int a, int b){
    if (a >= b){
        return a;
    }
    int ans = (2*a)-b;
    if (ans > 0){return ans;}
    else{
        return 0;
    }
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