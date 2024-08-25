#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main(){
    class Matrix{
    public:
        vector<vector<int>> a;
        Matrix operator + (Matrix& m){
            Matrix result;
            int i, j;
            for(i=0;i<m.a.size();i++){
                for(j=0;j<m.a[i].size();j++){
                    result.a[i][j] = (this->a[i][j]) + (m.a[i][j]);
                }
            }
            return result;
        }
};
    return 0;
}