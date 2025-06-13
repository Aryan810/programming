#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(int n, int m){
    if (m > n){
        return 0;
    }else if(m == n){return 1;}
    else{
        if (n%3 == 0){
            return (logic(n/3, m) || logic(2*n/3, m));
        }else{
            return 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        cout << (logic(n, m)?"YES":"NO") << endl;
        

    }

    return 0;
}