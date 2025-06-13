#include <iostream>

#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;
    int n, k;
    for (int i=0;i<t;i++){
        cin >> n >> k;
        vector <string> grid(n);
        string temp;
        // vector<string> new_grid(k);
        for (int i=0;i<n;i++){
            cin >> grid[i];
        }
        for (int i=0;i<n;i+=k){
            for (int j=0;j<n;j+=k){
                temp += grid[i][j];
            }
            cout << temp << endl;
            temp = "";
        }


        

    }

    return 0;
}