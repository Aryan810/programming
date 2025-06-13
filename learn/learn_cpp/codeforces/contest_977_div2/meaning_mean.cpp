#include <iostream>
#include <algorithm>
#include <vector>
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
        int n;
        cin >> n;
        vector<lli> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        while (a.size() > 1){
            lli mean = (a[0]+a[1])/2;
            a.erase(a.begin());
            a.erase(a.begin());
            vector<lli>::iterator x = a.begin();
            while (*(x) < mean){
                x++;
            }
            a.insert(x, mean);
        }
        cout << a[0] << endl;
    }

    return 0;
}