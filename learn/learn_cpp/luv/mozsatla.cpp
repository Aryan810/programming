#include <iostream>
#include <vector>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        
        for (int i=1;i<n;i++){
            int x;
            cin >> x;
            if (x){
                if (i == 1){
                    arr[1] = (x == 1)?1:2;
                    arr[2] = (x == 1)?2:1;
                    continue;
                }
                arr[i+1] = (x == 1)?(arr[i]+1):(arr[i]-1);
            }else{  
                if (i == 1){
                    arr[1] = 1;
                    arr[2] = 1;
                }
                arr[i+1] = arr[i];
            }
        }
        for (int i=1;i<(n+1);i++){
            cout << arr[i] << " ";
        }
        cout << endl;

    }

    return 0;
}