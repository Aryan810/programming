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
        vi arr(n);
        for (int i=0;i<n;i++) cin >> arr[i];
        int n_good = 0;
        int max_ele = arr[0];
        lli sum = 0;
        for (int i=0;i<n;i++){
            sum += arr[i];
            if (arr[i] > max_ele){
                max_ele = arr[i];
            }
            if (2ll*(max_ele) == sum){
                n_good += 1;
            }
        }
        cout << n_good << endl;
        

    }

    return 0;
}