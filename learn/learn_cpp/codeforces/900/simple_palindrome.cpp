#include <iostream>
#include <vector>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int x = n%5;
        string s = "aeiou";

        string pal;
        for (int i=0;i<5;i++){
            for (int j=0;j<n/5;j++){
                pal.push_back(s[i]);
            }
            if (i+1 <= x){
                pal.push_back(s[i]);
            }
        }
        cout << pal << endl;

    }

    return 0;
}