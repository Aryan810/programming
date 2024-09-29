// OLD APPROACH >> 

// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <math.h>

// using namespace std;

// int is_correct_in_between(string s, int size){
//     int a = int(sqrt(size));
//     for (int i=a;i<=(size-2*a);i+=a){
//         if (s.substr(i, a) != to_string(1 + pow(10, a-1)).substr(0, a)){
//             return 0;
//         }
//     }
//     return 1;
// }

// int is_all_ones(string s, int size){
//     int a = int(sqrt(size));
//     for (int i=0;i<a;i++){
//         if ((s[i] == '0') || (s[s.length()-1-i] == '0')){
//             return 0;
//         }
//     }
//     return 1;
// }
// // int no_of_first_1s(string s, int size){
// //     int n=0;
// //     for (int i=0;i<size;i++){
// //         if (s.at(i) == '0'){
// //             break;
// //         }
// //         n += 1;
// //     }
// //     return n;
// // }

// int main(){

//     int t;
//     cin >> t;
//     int size;
//     int temp;
//     for (int i=0;i<t;i++){
//         cin >> size;
//         string s;
//         cin >> s;
//         if (s.find('0') < s.length()){
//             if ((sqrt(s.length()) - int(sqrt(s.length()))) == 0.0){
//                 if (is_all_ones(s, size)){
//                     if (is_correct_in_between(s, size)){
//                         cout << "Yes" << endl;
//                     }else{
//                         cout << "No" << endl;
//                     }
//                 }else{
//                     cout << "No" << endl;
//                 }
//             }else{
//                 cout << "No" << endl;
//             }
//         }else{
//             // temp = no_of_first_1s(s);
//             // if (((sqrt(temp) - int(sqrt(temp))) == 0.0) &&(temp%2 == 0)){
//             //     cout << "Yes" << endl;
//             // }else{
//             //     cout << "No" << endl;
//             // }
//             if ((s == "1") || (s == "1111")){
//                 cout << "Yes" << endl;
//             }else{
//                 cout << "No" << endl;
//             }
//         }
//     }

//     return 0;
// }


// New Approach >> 

#include <iostream>
#include <vector>
#include <math.h>

#define lli long long int

using namespace std;

bool is_square(string& data, lli a){
    if (a == 1){
        return ((data.substr(0, a) == "1")?1:0);
    }
    string s = "";
    for (lli i=0ll;i<a;i++){s+="1";}
    if (data.substr(0, a) != data.substr((a-1ll)*a, a) || data.substr(0ll, a)!=s){
        // cout << "first error" << endl;
        return 0;
    }

    // I DID THIS IMPORTANT MISTAKE !!!!
    // s = to_string(1ll+(lli)(pow(10, a-1ll))); // *****THIS IS A VERY WRONG LINE 
              
                                                 // AS IF 'a' IS VERY LARGE THEN even LONG LONG INT can hold it but it can be stored in string by a simple loop!*****
    s = "";
    for (int i=0;i<a;i++){s += ((i==0 || i==a-1))?"1":"0";}
    // cout << "S: " << s << endl;
    
    for (lli i=1ll;i<=a-2ll;i++){
        if (data.substr(a*i, a) != s){
            // cout << "second error" << endl;
            return 0;
        }
    }
    return 1;


}

int main(){

    int t;
    cin >> t;

    while(t--){
        lli n;
        cin >> n;
        string inp;
        cin >> inp;
        if (sqrt(n)-(lli)(sqrt(n)) != 0ll){
            cout << "NO" << endl;
        }else{
            lli a = (lli)(sqrt(n));
            // vector<string> data(a);
            // for (int i=0;i<a;i++){
            //     string temp = "";
            //     for (int j=0;i<a;j++){
            //         char x;
            //         cin >> x;
            //         temp += x;
            //     }
            //     data[i] = temp;
            // }
            
            cout << ((is_square(inp, a))?"YES":"NO") << endl;
        };
    }

    return 0;
}
