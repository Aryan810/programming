#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string& s){
    int t = s.size()/2;
    for (int i=0;i<t;i++){
        if (s[i] != s[s.size()-1-i]){
            return 0;
        }
    }
    return 1;

}

int main(){

    // string s, s2;
    // getline(cin, s);
    // getline(cin, s2);
    // cout << s << endl;
    // cout << endl << s2 << endl;

    // // printing reverse of a given string.
    // string s = "aryan mahan";
    // string reverse_of_s;

    // // Method 1: 
    // for (int i=s.size()-1;i>=0;i--){
    //     // reverse_of_s =  reverse_of_s + s[i];
    //     reverse_of_s.push_back(s[i]); // better approach due to time complexity reasons!!!!
    // }

    // // Method 2: 
    // // for (int i=0;i<s.size();i++){
    // //     reverse_of_s = s[i] + reverse_of_s;
    // // }
    // cout << reverse_of_s << endl;

    // // Checking if string is a palindrome

    // Approach 1
    // int t;
    // cin >> t;
    // while (t--){
    //     string s;
    //     cin >> s;
    //     cout << ((is_palindrome(s))?"YES":"NO");
    // }

    // Approach 2 (using result of reversing the strings)
    string s;
    getline(cin, s);
    string reverse_of_s;
    for (int i=s.size()-1;i>=0;i--){
        // reverse_of_s =  reverse_of_s + s[i];
        reverse_of_s.push_back(s[i]); // better approach due to time complexity reasons!!!!
    }
    cout << ((reverse_of_s == s)?"YES":"NO") << endl;



    return 0;
}