#include <iostream>
#include <vector>

using namespace std;

int is_all_equal(vector<int> & nums){
    int a = nums[0];
    for (int i=0;i<nums.size();i++){
        if (nums[i] != a){
            return 0;
        }
    }
    return 1;
}

int num_of(vector<int> & nums, int num){
    int a=0;
    for (int i=0;i<nums.size();i++){
        if (num == nums[i]){
            a += 1;
        }
    }
    return a;
}

void show(vector<int> nums){
    cout << "SHOWING: " << endl;
    for (int i=0;i<nums.size();i++){
        cout << nums[i] << endl;
    }
}

int main(){
    int t, n;
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> nums(n);

        for (int j = 0; j < n; j++)
        {
            cin >> nums.at(j);
        }
        int iter=0;
        vector<int> temp = nums;
        int j=0, k=1;
        int a=0;
        while (!is_all_equal(nums)){
            if (a > 5){
                break;
            }
            a += 1;
            // cout << "j: " << j << " k: " << k << endl;
            if (nums[j] < nums[k]){
                // cout << "num of" << num_of(nums, nums[k]) << endl;
                if (num_of(nums, nums[k]) < num_of(nums, nums[j])){
                    temp.erase(temp.begin()+k);
                    iter += 1;
                }else{
                    temp.erase(temp.begin()+j);
                }
                iter += 1;
            }
            if (j == nums.size()-1){
                j = 0;
                k = 1;
            }else if(k == nums.size()-1){
                j = k;
                k = 0;
            }else{
            j += 1;
            k += 1;
            }
        nums = temp;
        // show(nums);
        }
        // cout << "size: " << nums.size() << endl;
        // cout << "iter: " << iter << endl;
        cout << endl << iter << endl;
    }
    
    

    return 0;
}