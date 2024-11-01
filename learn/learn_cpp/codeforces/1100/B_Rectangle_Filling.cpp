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
        int n, m;
        cin >> n >> m;

        vector< vector<int> > v(n, vector<int>(m));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                char c;
                cin >> c;
                v[i][j] = (c=='W')?1:0;
            }
        }

        int a=0, b=0, c=0, d=0;
        for (int i=0;i<m;i++){
            a += v[0][i];
        }
        for (int i=0;i<m;i++){
            b += v[n-1][i];
        }
        for (int i=0;i<n;i++){
            c += v[i][0];
        }
        for (int i=0;i<n;i++){
            d += v[i][m-1];
        }

        bool ans = 0;
        // W
        if (v[0][0] && (b!=0 && d!=0)){
            ans = 1;
        }
        if (v[n-1][0] && (a!=0 && d!=0)){
            ans = 1;
        }
        if (v[0][m-1] && (b!=0 && c!=0)){
            ans = 1;
        }
        if (v[n-1][m-1] && (a!=0 && c!=0)){
            ans = 1;
        }
        
        // B
        a=0, b=0, c=0, d=0;
        for (int i=0;i<m;i++){
            a += !v[0][i];
        }
        for (int i=0;i<m;i++){
            b += !v[n-1][i];
        }
        for (int i=0;i<n;i++){
            c += !v[i][0];
        }
        for (int i=0;i<n;i++){
            d += !v[i][m-1];
        }
        // W
        if (!v[0][0] && (b!=0 && d!=0)){
            ans = 1;
        }
        if (!v[n-1][0] && (a!=0 && d!=0)){
            ans = 1;
        }
        if (!v[0][m-1] && (b!=0 && c!=0)){
            ans = 1;
        }
        if (!v[n-1][m-1] && (a!=0 && c!=0)){
            ans = 1;
        }
        if (n == 1 && m == 1){
            ans = 1;
        }
        cout << ((ans)?"YES":"NO") << endl;
        

    }

    return 0;
}