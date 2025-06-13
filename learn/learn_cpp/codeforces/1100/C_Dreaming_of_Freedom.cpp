#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(int n, int m){
    if (n == 1 || m == 1){return 1;}
    if (n <= m){return 0;}
 
    while (n % 2 == 0) 
    { 
        if (2 <= m){
            return 0;
        } 
        n = n/2; 
    } 
 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 

        while (n % i == 0) 
        { 
            if (i <= m){
            return 0;
            } 
            n = n/i; 
        } 
    } 
 
    if (n > 2) 
        if (n <= m){
            return 0;
        } 
    return 1;
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