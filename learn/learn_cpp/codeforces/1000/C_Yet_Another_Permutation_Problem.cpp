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
        // vector<int> p;
        unordered_map<int, int> a;
        cout << 1 << " ";
        for (int i=2;i<n+1;i++){
            for (int expo=i;expo<=n;expo*=2){
                if (a[expo] != 1){
                    cout << expo << " ";
                    a[expo] = 1;
                }
            }
        }
        // p.push_back(1);
        // a[1] = 1;
        // int end = n;
        // int mid = n/2;
        // for (int i=mid;i>=2;i--){    
        //     int conj = i*min((mid/i)+1, (end/i));
        //     // cout << "CONJ: " << conj << endl;
        //     p.push_back(i);
        //     if (a[conj] != 1){
        //             p.push_back(conj);
        //     }
        //     a[conj] = 1;
        //     a[i] = 1;
        // }
        // for (int i=mid+1;i<=n;i++){
        //     if (a[i] != 1){
        //         p.push_back(i);
        //         a[i] = 1;
        //     // cout << i << endl;

        //     }
        // }
        
        cout << endl;
    }

    return 0;
}