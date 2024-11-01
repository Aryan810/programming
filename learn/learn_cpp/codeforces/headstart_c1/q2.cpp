#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, b;
        cin >> n >> b;

        lli c=0, d=0;
        if (n%b > b/2){
            c = n/b + 1 + (b-n%b);
        }else{
            c = n/b + n%b;
        }

        if (1000%b > b/2){
            d = 1000/b + 1 + (b-1000%b);
        }else{
            d = 1000/b + 1000%b;
        }
        cout << c+d << endl;

    }

    return 0;
}