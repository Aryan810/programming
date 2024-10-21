#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

lli logic(lli & n){
    if (n%2 != 0){
        return 1;
    }
    for (lli i=1;;i++){
        if (n%i != 0){
            return (i-1);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        lli n;
        cin >> n;
        cout << logic(n) << endl;
    }

    return 0;
}