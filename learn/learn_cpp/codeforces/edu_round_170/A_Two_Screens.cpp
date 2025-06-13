#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s, t;
        cin >> s >> t;
        int ans = 0;
        for (int i=0;i<min(s.size(), t.size());i++){
            if (s[i] != t[i]){
                    if (i != 0){
                        ans += i + 1;
                    }
                    ans += s.size()-i;
                    ans += t.size()-i;
                    break;
            }else if(i  == min(s.size(), t.size())-1){
                i += 1;
                if (i != 0){
                        ans += i + 1;
                    }
                    ans += s.size()-i;
                    ans += t.size()-i;
                    break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}