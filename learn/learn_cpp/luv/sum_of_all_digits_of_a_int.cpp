#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        //LOGIC 1 >> 
        // string s = to_string(n);
        // int sum=0;
        // for (int i=0;i<s.size();i++){
        //     sum += int(s[i])-48;
        // }

        // LOGIC 2 >>
        // int sum=0;
        // while (n > 0){
        //     int lastDigit = n - int(n/10)*10;
        //     n = int(n/10);
        //     sum += lastDigit;
        // }

        //LOGIC 3 >> 
        int sum = 0;
        while (n != 0){
            sum += n%10;
            n = (n - (n%10))/10;
        }
        cout << sum << endl;
    }
    return 0;
}