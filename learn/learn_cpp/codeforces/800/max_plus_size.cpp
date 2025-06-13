#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        int score = ceil(double(n)/2);
        int M = *max_element(arr.begin(), arr.end());
        if (n%2 == 0){
            score += M;
        }else{
            int max=arr[0];
            for (int i=2;i<n;i+=2){
                if (arr[i] > max){
                    max = arr[i];
                }
            }
            score += (max > M-1)?(max):(M-1);
        }
        cout << score << endl;

    }

    return 0;
}