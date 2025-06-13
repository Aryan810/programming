#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void algo(vector< vector<int> >& mat, int& n, int& m){
    bool found = 1;
    while (found){
        found = 0;
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if (max({
                ((i==0)?0:mat[i-1][j]), 
                ((i == n-1)?0:mat[i+1][j]),
                ((j==0)?0:mat[i][j-1]), 
                ((j == m-1)?0:mat[i][j+1])}) < mat[i][j]){
                    
                    mat[i][j] = max({
                ((i==0)?0:mat[i-1][j]), 
                ((i == n-1)?0:mat[i+1][j]),
                ((j==0)?0:mat[i][j-1]), 
                ((j == m-1)?0:mat[i][j+1])});
                    found = 1;
                    break;
                }
            }
            if (found){
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector< vector<int> > mat(n);
        for (int i=0;i<n;i++){
            vector<int> temp(m);
            for (int j=0;j<m;j++){
                cin >> temp[j];
            }
            mat[i] = temp;
        }
        algo(mat, n, m);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        
    }

    return 0;
}