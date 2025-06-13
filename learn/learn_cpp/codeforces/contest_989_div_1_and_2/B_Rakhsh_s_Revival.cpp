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
        int n, m, k;cin >> n >> m >> k;
        string s;
        cin >> s;
        s += '1';
        int x =  m-1;
        int i = -1;
        int ans = 0;
        while (i < n){
            while (i < n && s[i+1] != '0'){
                i += 1;
            }
            bool c = 0;
            for (int j=0;j<x;j++){
                i += 1;
                if (i < n && s[i] == '1'){
                    c = 1;
                    break;
                }
            }
            if (c){continue;}
            if (i+1 < n){
                if (s[i+1] == '0'){
                    i += k;
                    ans += 1;
                }else{
                    continue;
                }
            }
        }
        cout << ans << endl;

        

    }

    return 0;
}