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
        int speed[n];
        for (int i=0;i<n;i++){
            cin >> speed[i];
        }
        int num_max = 1;
        for (int i=0;i<n-1;i++){
            if (speed[i+1]<=speed[i]){
                num_max += 1;
            }else{
                speed[i+1] = speed[i];
            }
        }
        cout << num_max << endl;

    }

    return 0;
}