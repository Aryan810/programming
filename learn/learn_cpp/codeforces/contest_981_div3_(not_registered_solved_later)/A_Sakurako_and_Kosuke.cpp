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
        int n;
        cin >> n;
        int x = 0;
        int i = 1;
        bool sak = 1;
        while (abs(x) <= n){
            if (sak){
                x -= 2*i - 1;
                sak = 0;
            }else{
                x += 2*i - 1;
                sak = 1;
            }
            i++;
        }
        if (!sak){
            cout << "Sakurako" << endl;
        }else{
            cout << "Kosuke" << endl;
        }
        

    }

    return 0;
}