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

    // int t;
    // cin >> t;

    // while(t--){
        string s;
        cin >> s;
        int m = s.size()-1;
        int ans = (int)ceil(m/double(2) + 0.1);
        s.erase(s.begin());
        if (s.find('1') >= s.size() && s.size()%2 == 0){
            ans -= 1;
        }
        cout << ans << endl;

    // }

    return 0;
}