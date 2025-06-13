// #include <bits/stdc++.h>
// #define lli long long int
// #define vi vector<int>
// #define vii vector<int>::iterator
// #define vllii vector<lli>::iterator
// #define vlli vector<lli>

// using namespace std;

// lli sqroot(lli n){
//     lli r = n;
//     lli l = 1ll;
//     while (l <= r){
//         lli mid = (l+r)/2;
//         if (mid*mid > n){
//             r = mid-1;
//         }else{
//             l = mid+1;
//         }
//     }
//     return r;
// }

// void primeFactors(int n) 
// { 
//     // Print the number of 2s that divide n 
//     while (n % 2 == 0) 
//     { 
//         cout << 2 << " "; 
//         n = n/2; 
//     } 
 
//     // n must be odd at this point. So we can skip 
//     // one element (Note i = i +2) 
//     for (int i = 3; i <= sqrt(n); i = i + 2) 
//     { 
//         // While i divides n, print i and divide n 
//         while (n % i == 0) 
//         { 
//             cout << i << " "; 
//             n = n/i; 
//         } 
//     } 
 
//     // This condition is to handle the case when n 
//     // is a prime number greater than 2 
//     if (n > 2) 
//         cout << n << " "; 
// } 

// int main(){
//     ios_base::sync_with_stdio(0);
//     // int n = 93;
//     // primeFactors(n);
//     // string s = "110011100110001";
//     // cout << s.find('0') << endl;
//     vector<string> k(32);
//     cout << "g" << k[0][0] << "h" << endl;
     
//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vi a = {4, 5, 5, 9};
    cout << (upper_bound(a.begin(), a.end(), 9)-a.begin()) << endl;

    return 0;
}