#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        vector<int> abc(3);
        for (int i=0;i<3;i++){cin >> abc[i];}

        for (int i=0;i<3;i++){
            int m = max(abc[(i+1)%3], abc[i+2]%3)-min(abc[(i+1)%3], abc[(i+2)%3]);
            // cout << " M: " << m << endl;
            if (m%2 == 0){
                cout << "1 " << endl;
            }else{
                cout << "0 ";
            }

        }
        cout << endl;

    }

    return 0;
}