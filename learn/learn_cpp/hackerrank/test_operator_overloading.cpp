#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public:
        vector< vector<int> > a;
        Matrix operator + (Matrix& m){
            Matrix result;
            int i, j;
            vector <int> row;
            cout << 3 << endl;
            for(i=0;i<m.a.size();i++){
               row.erase(row.begin(), row.end());
                for(j=0;j<m.a[i].size();j++){
                     row.push_back(m.a[i][j]+this->a[i][j]);
                }
               result.a.push_back(row);
            }
            return result;
        }
};

int main () {
   // int cases,k;
   // cin >> cases;
   // for(k=0;k<cases;k++) {
   //    Matrix x;
   //    Matrix y;
   //    Matrix result;
   //    int n,m,i,j;
   //    cin >> n >> m;
   //    for(i=0;i<n;i++) {
   //       vector<int> b;
   //       int num;
   //       for(j=0;j<m;j++) {
   //          cin >> num;
   //          b.push_back(num);
   //       }
   //       x.a.push_back(b);
   //    }
   //    for(i=0;i<n;i++) {
   //       vector<int> b;
   //       int num;
   //       for(j=0;j<m;j++) {
   //          cin >> num;
   //          b.push_back(num);
   //       }
   //       y.a.push_back(b);
   //    }
   //    cout << 1 << endl;
   //    result = x+y;
   //    cout << 2 << endl;
   //    for(i=0;i<n;i++) {
   //       for(j=0;j<m;j++) {
   //          cout << 4 << endl;
   //          cout << result.a[i][j] << " ";
   //       }
   //       cout << endl;
   //    }
   // }
   cout << 30%2;

   return 0;
}