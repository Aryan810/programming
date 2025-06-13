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
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i=0;i<=n-3;i++){
            if ((((a[i]=='.' && a[i+1]=='.')&&(a[i+2]=='.'))&&((b[i]=='x' && b[i+1]=='.')&&(b[i+2]=='x')))){
                ans += 1;
            }
            if ((((b[i]=='.' && b[i+1]=='.')&&(b[i+2]=='.'))&&((a[i]=='x' && a[i+1]=='.')&&(a[i+2]=='x')))){
                ans += 1;
            }
        }

        cout << ans << endl;


    }

    return 0;
}