#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

// bool logic(vlli & a, int & n){
//     auto it1 = min_element(a.begin(), a.end());
//     lli m1 = *it1;
//     if (m1 == 1){
//         return 1;
//     }
//     lli m2 = 0;
//     bool m2set = false;
//     for (int i=0;i<n;i++){
//         if (a[i] % m1 != 0){
//             if (!m2){
//                 m2 = a[i];
//             }else if (m2 >= a[i] && !m2set){
//                 if (m2 == a[i]){
//                     m2set = 1;
//                 }else{
//                     m2 = gcd(m2, a[i]);
//                     if (m2 == 1){
//                         return 0;
//                     }
//                 }
//             }else{
//                 return 0;
//             }

//         }
//     }
//     return 1;
// }

bool logic(vlli & a, int & n){
    sort(a.begin(), a.end());
    lli m1 = a[0];
    lli m2 = 0;
    for(int i=0;i<n;i++){
        if (a[i]%m1 != 0){
            m2 = a[i];
            break;
        }
    }
    for (int i=1;i<n;i++){
        if (a[i]%m1 != 0 && a[i]%m2 != 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<lli> a(n);
        for (int i=0;i<n;i++) cin >> a[i];

        cout << (logic(a, n)?"YES":"NO") << endl;

    }

    return 0;
}