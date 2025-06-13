#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--){
        lli m;
        cin >> m;
        vector<lli> a(m);
        for (int i=0;i<m;i++){
            cin >> a[i];
        }
        // bool turtle = 1;
        // while (m > 1){
        //     vector<lli>::iterator iter = (turtle)?(min_element(a.begin(), a.end()-1)):(max_element(a.begin(), a.end()-1));
        //     lli v = turtle?(max(*iter, *(iter+1))):(min(*iter, *(iter+1)));
        //     *iter = v;
        //     a.erase(iter+1);
        //     turtle = (turtle)?0:1;
        //     m-=1;
        // }
        // cout << a[0] << endl;
        lli t, p;
        lli n = m-1;
        if (n%2 == 0){
            t = n/2;
            p = n/2;
        }else{
            t = n/2 + 1;
            p = n/2;
        }
        sort(a.begin(), a.end());
        a.erase(a.end()-p, a.end());
        a.erase(a.begin(), a.begin()+t);
        cout << a[0] << endl;
        
    }

    return 0;
}