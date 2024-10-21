#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        cin >> s;

        // string reverse_s;
        // for (int i=n-1;i>=0;i--){
        //     reverse_s = reverse_s + s[i];
        // }
        // if (reverse_s == s){
        //     cout << "YES" << endl;
        // }else{
        //     cout << "NO" << endl;
        // }
        bool is_pallindrome = true;
        for (int i=0;i<n/2;i++){
            if (s[i] != s[n-i-1]){
                is_pallindrome = false;
            }
        }
        if (is_pallindrome){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }

    return 0;
}