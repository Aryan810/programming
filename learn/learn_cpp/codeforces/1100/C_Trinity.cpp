#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vll a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int msize = 0;
        for (int i=0;i<n-1;i++){
            ll sum = a[i] + a[i+1];
            int low = i+1;
            int high = n-1;
            int index = i+1;
            while (high >= low){
                int mid = (low + high)/2;
                // cout << i<< " " << mid << endl;
                if (a[mid] < sum){
                    index = mid;
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            if (msize < index-i+1){
                msize = index-i+1;
            }
        }
        cout << n-msize << endl;
        

    }

    return 0;
}