#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m, q;
        cin >> n >> m >> q;
        vector<int> t(m);
        for(int i=0;i<m;i++){
            cin >> t[i];
        }
        cin >> q;
        sort(t.begin(), t.end());

        int moves = 0;
        if (q < t[0]){
            while (t[0]!=q){
                if (q > 1){
                    q -= 1;
                }
                if (t[0] > q){
                    t[0] -= 1;
                }
                moves += 1;
            }
        }else if (q > t[1]){
            while (t[1] != q){
                if (q < n-1){
                    q += 1;
                }
                if (t[1] < q){
                    t[1] += 1;
                }
                moves += 1;
            }

        }else{
            while (!((t[0] == q)||(t[1] == q))){
                int mid = (t[0] + t[1])/2;
                if ((t[0]+t[1])%2 == 0){
                    if (q > mid+1){
                        q-=1;
                    }else if(q < mid){
                        q+=1;
                    }
                }else{
                    if (q > mid){
                        q-=1;
                    }else if(q < mid){
                        q+=1;
                    }
                }
                t[0] += 1;
                t[1] -= 1;
                moves += 1;
            }
        }
        cout << moves << endl;


    }

    return 0;
}