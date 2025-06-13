#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

void logic(int & n, int & k){
    if (n == 1){
        cout << 1 << endl << 1 << endl;
    }else if (k == n || k == 1){
        cout << "-1" << endl;
    }else if (k%2 == 0){
        cout << 3 << endl << 1 << " " << k << " " << k+1 << endl;
    }else{
        cout << 5 << endl;
        cout << 1 << " " << 2 << " " << k << " " << k+1 << " " << k+2 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        logic(n, k);
        

    }

    return 0;
}