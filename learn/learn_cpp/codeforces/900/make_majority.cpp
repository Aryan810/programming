#include <iostream>
#include <vector>
#include <numeric>

#define lli long long int

using namespace std;
// ACCEPTED !
void show(vector<int>& a){
    for (int i=0;i<a.size();i++){
        cout << a[i] << endl;
    }
    cout << endl;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        char c;
        cin >> n;
        int size = 0;
        int sum = 0;
        int last_zero = 0;
        for (int i=0;i<n;i++){
            cin >> c;
            if (!((c == '0') && (last_zero))){
                last_zero = (c == '0')?1:0;
                sum += int(c) - 48;
                size += 1;
            }
        }
        // show(data);
        if (double(sum) > double(size)/2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }

    return 0;
}