#include <iostream>
#include <vector>
#include <string>
#include <set>

#define lli long long int

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string output;
        for (int i=0;i<n;i++){
            for (int k=1;k<=4;k++){
                char a;
                cin >> a;
                if (a == '#'){
                    output = to_string(k) + " " + output;
                }
            }
        }
        cout << output << endl;

    }

    return 0;
}