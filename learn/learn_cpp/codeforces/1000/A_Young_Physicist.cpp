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

    int n;
    cin >> n;
    int sumx = 0;
    int sumy = 0;
    int sumz = 0;
    for (int i=0;i<n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        sumx += x;
        sumy += y;
        sumz += z;
    }
    
    if (sumx == 0 && sumy == 0 && sumz == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}