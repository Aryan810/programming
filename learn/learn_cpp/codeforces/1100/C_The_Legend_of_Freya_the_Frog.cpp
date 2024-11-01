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
        lli x, y, k;
        
        cin >> x >> y >> k;
        lli cx = ceil(x/(double)k);
        lli cy = ceil(y/(double)k);
        if (cy == cx){
            cout << 2*cx << endl;
        }else if(cx > cy){
            cout << 2*cx - 1 << endl;
        }else{
            cout << 2*cy << endl;
        }
        
    }

    return 0;
}