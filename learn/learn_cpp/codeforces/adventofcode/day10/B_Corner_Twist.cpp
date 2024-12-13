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
        int n, m;cin >> n >> m;
        vector<vector<int> > a(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                char x;
                cin >> x;
                a[i].push_back(x-'0');
            }
        }
        vector<vector<int> > b(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                char x;
                cin >> x;
                b[i].push_back(x-'0');
            }
        }
        
        for (int i=0;i<n-1;i++){
                    // cout << "here1" << endl;

            for (int j=0;j<m-1;j++){
                if (a[i][j] == b[i][j]){continue;}
                    // cout << "here2" << endl;

                while (a[i][j] != b[i][j]){
                    // cout << a[i][j] << " here3 " << b[i][j] << endl;
                    // cout << "here3" << endl;
                    a[i][j] = (a[i][j] + 1)%3;
                    a[i+1][j+1] = (a[i+1][j+1] + 1)%3;
                    a[i][j+1] = (a[i][j+1] + 2)%3;
                    a[i+1][j] = (a[i+1][j]+2)%3;
                }
            }
        }
        cout << ((a == b)?"YES":"NO") << endl;

    }

    return 0;
}