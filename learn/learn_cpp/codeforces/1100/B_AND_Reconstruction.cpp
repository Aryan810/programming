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
        int m;
        cin >> m;
        int n = m-1;
        vector<lli> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        vector< vector<int> > b(n+1, vector<int>(30, 2));
        
        // cout << "here1" << endl;
        lli f = a[n-1];
        for (int i=0;i<30;i++){
            b[n][i] = f&1;
            if (f&1){
                b[n-1][i] = 1;
            }
            f = f/2;
        }
        // cout << "here2" << endl;
        // for (int i=0;i<30;i++){
        //     cout << b[0][i] << " ";
        // }
        // cout << endl;
        bool valid = 1;
        for (int i=n-1;i>=1;i--){
            lli x = a[i-1];
            // cout << x << endl;
            for (int j=0;j<30;j++){
                bool req = x&1;
                int found = b[i][j];
                // if (x == 2){
                // // cout << found << " " << req << endl;
                // }
                if (req){
                    if (found == 0){
                        valid = 0;
                        break;
                    }else{
                        b[i][j] = 1;
                        b[i-1][j] = 1;
                    }
                }else{
                    if (found == 1){
                        b[i-1][j] = 0;
                        // cout << "doing" << endl;
                    }else{
                        b[i][j] = 0;
                    }
                }
                if (x > 0){x = x/2;}
            }
            if (!valid){
                break;
            }
        }
        // cout << "here3" << endl;

        if (!valid){
            cout << -1 << endl;
        }else{
            for (int i=0;i<n+1;i++){
                lli x = 0;
                for (int j=0;j<30;j++){
                    // cout << i << " == " << j << endl;
                    x += pow(2, j)*(b[i][j]==1?1:0);
                }
                cout << x << " ";
            }
            cout << endl;
        }
        

    }

    return 0;
}