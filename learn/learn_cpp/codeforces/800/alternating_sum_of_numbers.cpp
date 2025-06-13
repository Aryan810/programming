#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t, n, temp=0, temp1;
    bool alter = true;
    cin >> t;

    for (int i=0;i<t;i++){
        cin >> n;
        vector<int> nums(n);
        temp = 0;
        alter = true;
        for (int j=0;j<n;j++){
            cin >> temp1;
            if (alter){
                temp += temp1;
                alter = false;
            }else{
                alter = true;
                temp -= temp1;
            }
        }
        cout << temp << endl;

    }

    return 0;
}