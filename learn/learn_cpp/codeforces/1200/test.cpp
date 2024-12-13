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

    vi a = {1, 4, 5, 9};
    cout << *lower_bound(a.begin(), a.end(), 7) << endl;

    return 0;
}