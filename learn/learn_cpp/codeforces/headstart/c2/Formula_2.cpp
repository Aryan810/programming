// #include <bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define vii vector<int>::iterator
// #define vlli vector<ll>::iterator
// #define vll vector<ll>

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     // int t;
//     // cin >> t;

//     // while(t--){
//         int n, r;
//         cin >> n >> r;

//         vll a(n);
//         for (int i=0;i<n;i++) cin >> a[i];
//         ll R = a[r-1];
//         vll b(n);
//         for (int i=0;i<n;i++) cin >> b[i];
//         sort(b.begin(), b.end());
//         R += *(b.end()-1);
//         b.pop_back();
//         int k1 = 0;
//         for (int i=0;i<n;i++){
//             if (i != r-1 && a[i] < R){
//                 k1 = i;
//                 break;
//             }
//             b.pop_back();
//         }
//         for (int i=0;i<n-r;i++){
//             b.pop_back();
//         }
//         int bk = 0;
//         int sm = 0;
//         // cout << "sc: " << b.size() << endl;
//         // unordered_map<int, int> came;
//         // for (int i=n-1;i>=0;i++){
//         //     if (i != r-1){
//         //         ll e = R - a[i];
//         //         auto lb = lower_bound(b.begin(), b.end(), e);
//         //         if (lb != b.end() && *lb == e){
//         //             came[lb-b.begin()] = 1;
//         //             bk += 1;
//         //         }
//         //     }
//         // }

//         // for (int i=k1;i<r;i++){
//         //     ll d = R - a[i];
//         //     auto lb = lower_bound(b.begin(), b.end(), d);
//         //     auto x = lb;
//         //     if (lb != b.begin()){
//         //         x--;
//         //     }else{
//         //         lb == 
//         //     }
//         //     bk += 1;
//         // }
//         int k2 = r-1;
//         ll m = b[0];
//         ll M = *(b.end()-1);
//         while (1){
//             if (M > R-a[k2]){
//                 k1 += 1;
//                 if (b.size() > 1){
//                     b.pop_back();
//                     M = *(b.end()-1);
//                 }
//             }else if (M == R-a[k2]){
//                 sm += 1;
//                 k2 -= 1;
//                 if (b.size() > 1){
//                     b.pop_back();
//                     M = *(b.end()-1);
//                 }
//             }else{
//                 bk += 1;
//                 k2 -= 1;
//                 if (b.size() > 1){
//                     b.pop_back();
//                     M = *(b.end()-1);
//                 }
//             }
//             if (m == M){
//                 break;
//             }
//         }
//         ll rank = n - bk - n + r - sm;
//         cout << rank << endl;
        

//     // }

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

    int n, r;
    cin >> n >> r;

    vi c(n);
    for (int i=0;i<n;i++){
        cin >> c[i];
    }
    multiset<int> p;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        p.insert(x);
    }
    int k = (*(--p.end())) + c[r-1];
    p.erase(--p.end());
    int rank = 0;
    int same = 0;
    for (int i=n-1;i>=0;i--){
        if (i+1 != r){
            auto it = p.lower_bound(k-c[i]);
            if (it != p.begin()){
                rank += 1;
                p.erase(--it);
            }else{
                    // cout << "YES" << endl;
                if (*it == k-c[i]){
                    same += 1;
                }
            }
        }
    }
    cout << (n -rank-same) << endl;


    return 0;
}