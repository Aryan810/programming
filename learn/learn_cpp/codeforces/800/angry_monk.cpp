#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void show(vector<int> nums){
//     cout << "SHOWING: " << endl;
//     for (int i=0;i<nums.size();i++){
//         cout << nums[i] << endl;
//     }
// }

int main(){

    int t;
    cin >> t;

    int n, k;
    int min, max, min_val;
    int iter=0;

    for (int i=0;i<t;i++){
        iter = 0;
        cin >> n >> k;
        vector<int> pieces(k);
        for (int j=0;j<k;j++){
            cin >> pieces.at(j);
        }

        while (pieces.size() != 1){
            if (find(pieces.begin(), pieces.end(), 1) == pieces.end()){
                min = min_element(pieces.begin(), pieces.end())-pieces.begin();
                min_val = pieces[min];
                pieces.erase(pieces.begin() + min);
                pieces.push_back(min_val-1);
                pieces.push_back(1);
            }else{
                pieces.erase(find(pieces.begin(), pieces.end(), 1));
                max = max_element(pieces.begin(), pieces.end())-pieces.begin();
                pieces[max] = pieces[max] + 1;
            }
            // if (iter > 20){break;}
            // show(pieces);
            iter += 1;
        }
        cout << iter << endl;

    }

    return 0;
}