#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> color_times(m);
        for (int i=0;i<m;i++){
            color_times[i] = (n/m)  + ((i<((n%m)))?1:0);
        }
        color_times.erase(max_element(color_times.begin(), color_times.end()));
        lli sum = accumulate(color_times.begin(), color_times.end(), 0ll);
        cout << (((lli)k >= sum)?"NO":"YES") << endl;


    }

    return 0;
}