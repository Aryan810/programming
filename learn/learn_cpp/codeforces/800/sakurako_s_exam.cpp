#include <iostream>

#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;
    int a, b;
    int s;
    for (int i=0;i<t;i++){
        cin >> a >> b;
        s = a + (2*b);
        if (s%2 == 0){
            if (b%2 == 0){
                cout << "YES" << endl;
            }else{
                if (a >= 2){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }
        }else{
            cout << "NO" << endl;
        }


    }

    return 0;
}