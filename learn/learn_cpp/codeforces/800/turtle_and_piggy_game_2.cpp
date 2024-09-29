#include <iostream>
#include <vector>

using namespace std;

int logic(int m, vector<int>& seq){
    if (m == 1){
        return seq[0];
    }else{
        
    }
}

int main(){

    int t;
    cin >> t;

    int m;
    for (int i=0;i<t;i++){
        cin >> m;
        vector <int> seq(m);
        for (int i=0;i<m;i++){
            cin >> seq[i];
        }
        cout << logic(m, seq) << endl;


    }

    return 0;
}