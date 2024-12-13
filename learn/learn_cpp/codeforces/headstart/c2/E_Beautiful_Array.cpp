#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    int x = b + 1;
    int y = 3*a - b - x;
    while (y >= b){
        x += 1;
        y -= 1;
    }
    cout << 3 << endl;
    cout << (y) << " " << b << " " << (x) << endl;

    return 0;
}