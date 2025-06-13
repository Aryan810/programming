// #include <bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define vii vector<int>::iterator
// #define vlli vector<ll>::iterator
// #define vll vector<ll>

// using namespace std;

// bool comp(pair<char, int> & a, pair<char, int> & b){
//     return a.second > b.second;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int t;
//     cin >> t;

//     while(t--){
//         int n;cin >> n;
//         string s;
//         cin >> s;
//         unordered_map<char, int> m;
//         for (int i=0;i<s.size();i++){
//             m[s[i]] += 1;
//         }
//         vector< pair<char, int> > v;
//         for (auto a: m){
//             v.push_back({a.first, a.second});
//         }
//         sort(v.begin(), v.end(), comp);
//         string out = "";
//         int i = 0;
//         int j = 1;
//         while (i<n){
//             for (int k=0;k<v[i].second;k++){
//                 // cout << v[i].first << " " << v[i].second << endl;
//                 out = out + v[i].first;
//                 if (j < n && v[j].second > 0){
//                     out = out + v[j].first;
//                     v[j].second -= 1;
//                 }else{
//                     if (j<n){
//                         j += 1;
//                     }
//                     if (j < n){
//                         out = out + v[j].first;
//                         v[j].second -= 1;
//                     }
//                 }
//                 // v[i].second -= 1;
//             }
//             v[i].second = 0;
//             i = j++;
//             if (i >= n){break;}
//         }
//         cout << out << endl;
//     }

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

    int t;
    cin >> t;

    while(t--){

        int n;cin >> n;
        vi a(26, 0);

        for (int i=0;i<n;i++){
            char x;
            cin >> x;
            a[x-'a'] += 1;
        }
        while (n != 0){
            for (int i=0;i<26;i++){
                if (a[i] > 0){
                    cout << (char)(i+'a') << "";
                    n--;
                    a[i]--;
                }
            }
        }
        cout << endl;
    }

    return 0;
}