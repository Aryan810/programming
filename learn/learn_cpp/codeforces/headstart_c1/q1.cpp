#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void logic(int n, int m, lli & c){
    c += 1;
    c += n-1 + m-1;
    if (n == 1 || m == 1){
        return;
    }
    logic(n-1, m-1, c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        lli c = 0;
        logic(n, m, c);
        cout << c << endl;
    }

    return 0;
}