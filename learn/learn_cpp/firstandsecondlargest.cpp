#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for (int i=0;i<n;i++) cin >> a[i];
    
    int l = a[0];
    int sl = -1e9;
    // possible that l and sl are the same.
    for (int i=0;i<n;i++){
        if (a[i] > l){
            sl = l;
            l = a[i];
        }else{
            sl = max(sl, a[i]);
        }
    }

    cout << l << " " << sl << endl;
    


    return 0;
}