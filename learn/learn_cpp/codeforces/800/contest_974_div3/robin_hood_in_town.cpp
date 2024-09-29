#include <bits/stdc++.h>

using namespace std;

// FOR DEBUGING
// void show(vector<int> nums){
//     cout << "SHOWING: " << endl;
//     for (int i=0;i<nums.size();i++){
//         cout << nums[i] << endl;
//     }
// }


int main(){

    int t;
    cin >> t;
    int n;
    int lth;
    long max_;
    bool is_correct;
    long int temp;
    long double half_avg;
    for (int i=0;i<t;i++){
        cin >> n;
        vector<long long> wealth(n);
        vector<long long> p_x;
        lth = int(n/2) + 1;
        // cout << "lth: " << lth << endl;
        for (int j=0;j<n;j++){
            cin >> wealth[j];
        }
        sort(wealth.begin(), wealth.end());
            // show(wealth);
        
        // getting sum of wealth
        long long s = accumulate(wealth.begin(), wealth.end(), 0);

            // cout << "S: " << s << endl;

        
        for (int j=0;j<lth;j++){
            p_x.push_back((2*n*(wealth[j])) - s);
        }

        // show(p_x);
        max_ = (*max_element(p_x.begin(), p_x.end())) + 1;
        // cout << "max_: " << max_ << " max_ele: " << (*max_element(p_x.begin(), p_x.end())) << endl;
        is_correct = true;

        // FINDING HALF of AVERAGE
        half_avg = double(s+max_)/double(2*n);
        
        // cout << "AVG: " << half_avg << endl;
        for (int j=0;j<lth;j++){
            temp = wealth[j];
            if (j == n-1){
                temp += max_;
            }
            if (temp >= half_avg){
                is_correct = false;
            }
        }
        if (is_correct){
            if ((max_) <= 0){
                cout << 0 << endl;
            }else{
                cout << max_ << endl;
            }
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}