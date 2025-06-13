#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

// Coding binary

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ans = 1;
    int k = 5;
    int X = 9;
    for (int i=0;i<k;i++){
        ans = (ans * 2)%X;
    }
    cout << ans << endl;
    return 0;
}