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
        string s;
        cin >> s;
        string p;
        cin >> p;
        int ans = 0;
        unordered_map <int, int> m;
        for(int i=0;i<n-1;i++){
            char a = p[25-p.find(s[i])];
            char b = p[25-p.find(s[i+1])];
            if (s[i+1] < s[i]){
                if (a <= s[i+1]){
                    if (!m[i]){
                        s[i] = a;
                        m[i] = 1;
                    }else{
                        ans = -1;
                        break;
                    }
                    ans += 1;
                }else if (b >= s[i]){
                    if (!m[i+1]){s[i+1] = b;m[i+1] = 1;}else{ans = -1;break;}
                    ans += 1;
                }else if (a <= b){
                    if (!m[i]){s[i] = a;m[i]=1;}else{ans = -1;break;}

                    if (!m[i+1]){s[i+1] = b;m[i+1]=1;}else{ans = -1;break;}

                    ans += 2;
                    // cout << "here" << endl;
                }else{
                    ans = -1;
                    break;
                }
            }
        }

        // for (int i=0;i<n-1;i++){
        //     char c = s[i+1];
        //     int x = p.find(c);
        //     char d = p[25-(x)];
        //     char e = p[25-p.find(s[i])];
        //     // cout << i << " " << c << " " << d << endl;
        //     if (c > s[i] && d!=c){
        //         if (d-s[i] >= 0 && d<c){
        //             if (i+2 < n){
        //                 if (s[i+2] < c){
        //                     s[i+1] = d;
        //                     ans += 1;
        //                 }
        //             }
        //         }
        //     }else if (c < s[i]){
        //         if (d >= s[i]){
        //             s[i+1] = d;
        //             ans += 1;
        //         }else if(e <= c && (i > 0 && s[i-1]<=e)){
        //             s[i] = e;
        //             ans += 1;
        //         }else{
        //             ans = -1;
        //             break;
        //         }
        //     }
        //     // cout << s << endl;
        // }
        cout << ans << endl;
        

    }

    return 0;
}