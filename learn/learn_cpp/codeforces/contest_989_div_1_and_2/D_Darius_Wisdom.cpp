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

//     int t;
//     cin >> t;

//     while(t--){
//         int n;
//         cin >> n;

//         vi a(n);
//         for (int i=0;i<n;i++) cin >> a[i];

//         auto b = a;
//         sort(b.begin(), b.end());
//         map <int, vector<int> > sp;
//         map <int, vector<int> > sn;
//         vector< pair<int, int> > out;

//         vector<int> oo; // one-one
//         vector<int> ot; // one-two
//         vector<int> oz; // one-zero
//         for (int i=0;i<n;i++){
//             if (a[i] == 1){
//                 switch (b[i])
//                 {
//                 case 1:
//                     oo.push_back(i);
//                     break;
//                 case 0:
//                     oz.push_back(i);
//                     break;
//                 case 2:
//                     ot.push_back(i);
//                     break;
//                 default:
//                     break;
//                 }
//             }
//         }
//         vector<int> tz;
//         vector<int> zt;
//         // while (1){
//         //     bool done = 1;
//             for (int i=0;i<n;i++){
//                 if (a[i]-b[i] == 2){ // 2/0
//                     tz.push_back(i);
//                     // if (!ot.empty()){
//                     //     out.push_back({i, ot.back()});
//                     //     a[i] = 1;
//                     //     a[ot.back()] = 2;
//                     //     oz.push_back(i);
//                     //     ot.pop_back();
//                     // }else{
//                     //     if (!oo.empty()){
//                     //         out.push_back({i, oo.back()});
//                     //         a[i] = 1;
//                     //         a[oo.back()] = 2;
//                     //         oz.push_back(i);
//                     //         oo.pop_back();
//                     //     }else{
//                     //         done = 0;
//                     //     }
//                     // }
//                 }else if (a[i]-b[i] == -2){ // 0/2
//                     zt.push_back(i);
//                     // if (!oz.empty()){
//                     //     out.push_back({i, oz.back()});
//                     //     a[i] = 1;
//                     //     a[oz.back()] = 0;
//                     //     ot.push_back(i);
//                     //     oz.pop_back();
//                     // }else{
//                     //     if (!oo.empty()){
//                     //         out.push_back({i, oo.back()});
//                     //         a[i] = 1;
//                     //         ot.push_back(i);
//                     //         a[oo.back()] = 0;
//                     //         oo.pop_back();
//                     //     }else{
//                     //         done = 0;
//                     //     }
//                     // }
//                 }
//             }
//             // if (done){break;}
//         // }
//         while (1){
//             int done = 1;
//             for (int i=0;i<tz.size();i++){
//                 if (!ot.empty()){
//                     out.push_back({tz[i], ot.back()});
//                     a[tz[i]] = 1;
//                     a[ot.back()] = 2;
//                     oz.push_back(i);
//                     ot.pop_back();
//                 }else{
//                     if (!oo.empty()){
//                         out.push_back({tz[i], oo.back()});
//                         a[tz[i]] = 1;
//                         a[oo.back()] = 2;
//                         oz.push_back(i);
//                         oo.pop_back();
//                     }else{
//                         done = 0;
//                     }
//                 }
//             }
//             for (int i=0;i<zt.size();i++){
//                 if (!ot.empty()){
//                     out.push_back({zt[i], oz.back()});
//                     a[zt[i]] = 1;
//                     a[oz.back()] = 0;
//                     ot.push_back(i);
//                     oz.pop_back();
//                 }else{
//                     if (!oo.empty()){
//                         out.push_back({zt[i], oo.back()});
//                         a[zt[i]] = 1;
//                         a[oo.back()] = 0;
//                         ot.push_back(i);
//                         oo.pop_back();
//                     }else{
//                         done = 0;
//                     }
//                 }
//             }
//             if (done){break;}
//         }

//         // for (int i=0;i<n;i++){
//         //     cout << a[i] << " ";
//         // }cout << endl;



//         for (int i=0;i<n;i++){
//             if (a[i]-b[i] == 1){
//                 sn[2*a[i]-1].push_back(i);
//             }else if (a[i]-b[i] == -1){
//                 sp[2*a[i]+1].push_back(i);
//             }
//         }
//         for (auto k: sp){
//             for (int i=0;i<k.second.size();i++){
//                 out.push_back({k.second[i], sn[k.first][i]});
//             }
//         }
        
//         cout << out.size() << endl;
//         for (int i=0;i<out.size();i++){
//             cout << out[i].first+1 << " " << out[i].second+1 << endl;
//         }

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
        int n;
        cin >> n;

        vi a(n);
        int z=0, o=0, tw=0;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            if (x == 0){z += 1;}else if (x == 1){o += 1;}else{tw += 1;}
            a[i] = x;
        }

        auto b = a;
        sort(b.begin(), b.end());
        
        int i=0,j=n-1,k=n-1;
        int ans = 0;
        vector< pair<int, int> > out;
        while (i<z){
            while (a[i] == 0){
                i += 1;
            }
            if (i >= z){break;}
            // cout << i << endl;
            if (a[i] == 1){
                while (a[j] != 0){
                    j--;
                }
                a[i] = 0;
                a[j] = 1;
                out.push_back({i, j});
            }else{
                while (a[k] != 1){
                    k--;
                }
                a[i] = 1;
                a[k] = 2;
                out.push_back({i, k});
                while (a[j] != 0){
                    j--;
                }
                a[i] = 0;
                a[j] = 1;
            // cout << "=>" << " " << i << " " << j << endl;

                out.push_back({i, j});
            }
        }
        j = n-1;
        while (i < z+o){
            while (a[i] == 1){
                i++;
            }
            if (i >= z+o){break;}
            // cout << i << endl;
            while (a[j] != 1){
                j--;
            }
            a[i] = 1;
            a[j] = 2;
            // cout << "_>" << " " << i << " " << j << endl;
            out.push_back({i, j});
        }

        cout << out.size() << endl;
        for (int i=0;i<out.size();i++){
            cout << out[i].first+1 << " " << out[i].second+1 << endl;
        }
    }

    return 0;
}