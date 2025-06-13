#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector<lli> arr(n);
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        lli max = *max_element(arr.begin(), arr.end());
        for (int i=0;i<m;i++){
            lli l, r;
            char c;
            cin >> c >> l >> r;
            if ((max >= l)&&(max <= r)){
                max += (c == '+')?1ll:-1ll;
            }
            cout << max << " ";
        }
        cout << endl;

    }

    return 0;
}