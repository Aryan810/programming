#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool logic(string & s, int n, int m, int k){
    int i = 0;
    while (i < n+1){
        if (s[i] == 'L'){
            string x = s.substr(i+1, m);
            // if (i+m >= n+1){
            //     return 1;
            // }
            int y = x.size()-1;
            // cout << "L: " << x << endl;
            if (x.find('L') < x.size()){
                while (x[y] != 'L'){
                    y--;
                }
                i += y+1;
            }else if (x.find('W') < x.size()){
                while (x[y] != 'W'){
                    y--;
                }
                i += y+1;
            }else{
                return 0;
            }
            // cout << "L: " << i << endl;
        }else if (s[i] == 'W'){
            string x = s.substr(i+1, k);
            int y = 0;
            // cout << "W: " << x << endl;

            if (x.find('L') >= x.size()){
                if (x.find('C') >= x.size() && i+k >= n+1){
                    return 1;
                }
                return 0;
            }else{
                while (x[y] != 'L'){
                    if (x[y] == 'C'){return 0;}
                    y++;
                    if (y >= x.size()){
                        return 0;
                    }
                }
                i += y+1;
                k -= y+1;
            }
            // cout << "W: " << i << endl;
        }else{
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
        int n, m, k;cin >> n >> m >> k;
        string s;cin >> s;
        s = "L" + s + "L";
        cout << ((logic(s, n, m, k)?"YES":"NO")) << endl;


    }

    return 0;
}