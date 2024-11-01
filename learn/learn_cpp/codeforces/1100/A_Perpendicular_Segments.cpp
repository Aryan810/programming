#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void logic(int & x, int & y, int & k){
    // if (x == y){
    //     cout << "0 0 " << x << " " << y << endl;
    //     cout << "0 " << y << " " << x << " 0" << endl;
    // }
    // else if(x > y){
    //     cout << "0 " << y << " " << x << " 0" << endl;
    //     int a = ceil((x*x - y*y)/(double)x);
    //     cout << x << " " << y << " " << a << " 0" << endl;
    // }else{
    //     int b = ceil((y*y - x*x)/(double)y);
    //     cout << "0 " << y << " " << x << " 0" << endl;
    //     cout << x << " " << y << " 0 " << b << endl;
    // }
    cout << "0 0 " << min(x, y) << " " << min(x, y) << endl;
    cout << "0 " << min(x, y) << " " << min(x, y) << " 0" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int x, y, k;
        cin >> x >> y >> k;

        logic(x, y, k);

    }

    return 0;
}