#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;
    int n, k;
    for (int i=0;i<t;i++){
        cin >> n >> k;
        int x=0;
        int gold = 0;
        vector<int> golds(n);
        for (int i=0;i<n;i++){
            cin >> golds[i];
        }

        for (int i=0;i<n;i++){
            if (golds[i] >= k){
                gold += golds[i];
            }else if ((golds[i] == 0) && (gold > 0)){
                x += 1;
                gold -= 1;
            }
        }
        cout << x << endl;

    }

    return 0;
}