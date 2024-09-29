#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define lli long long int
using namespace std;

void show(vector<lli> nums){
    cout << "SHOWING: " << endl;
    for (int i=0;i<nums.size();i++){
        cout << nums[i] << endl;
    }
}

int main(){
    int t;
    cin >> t;
    lli l, r;
    lli t1, t2;
    while(t--){
        lli n, d, k;
        cin >> n >> d >> k;
        vector<lli> work(n+1);
        work[0] = 0;
        // it will will fill 'work' such that we get how many tasks are there on a perticular day.
        for (int i=0;i<k;i++){
            cin >> l >> r;
            t1 = l-d+1;
            if (t1 < 1){
                t1 = 1;
            }
            for (int j=t1;j<=r;j++){
                work[j] += 1;
            }
        }

        // show(work);
        cout << (max_element(work.begin()+1, work.begin()+n-d+1)-work.begin()) << " ";
        cout << (min_element(work.begin()+1, work.begin()+n-d+1)-work.begin()) << endl;




        

    }

    return 0;
}