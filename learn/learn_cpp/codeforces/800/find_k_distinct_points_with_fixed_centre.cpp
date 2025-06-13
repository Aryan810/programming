#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sum_n(int sum){
    return int((sqrt(1+8*sum) - 1)/2);
}

int pseudo_pts(int n){
    for (int i=1;i<(n+1);i++){
        cout << -1*(100 + i) <<  " " << (100 + i) << endl;
    }
}

int main(){
    int t;
    cin >> t;
    int x, y, k;
    int sum_x, sum_y;
    int temp_x, temp_y;
    for (int i=0;i<t;i++){
        cin >> x >> y >> k;
        sum_x = x*k;
        sum_y = y*k;
        vector<int> xs, ys;

        // for xs.
        if (sum_x > 0){
            temp_x = sum_n(sum_x);
            
        }
        
        
    }

    return 0;
}