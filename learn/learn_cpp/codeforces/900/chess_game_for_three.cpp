#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

// bool is_int(double d){
//     return d - int(d) == 0.0;
// }

// int logic(int p1, int p2, int p3){
//     double c1 = (p2+p3-p1)/double(2);
//     double c2 = (p1+p3-p2)/double(2);
//     double c3 = (p1+p2-p3)/double(2);
//     if (!(is_int(c1)&&(is_int(c1)&&is_int(c1)))){
//         return -1;
//     }
//     if ((c1 >= 0)&&(c2 >= 0)&&(c3 >= 0)){
//         return int(c1 + c2 + c3);
//     }


// }

int main(){

    int t;
    cin >> t;

    while(t--){
        vi p(3);
        cin >> p[0] >> p[1] >> p[2];
        int draws = 0;
        while (1){
            int m1 = (p[0]>=p[1])?0:1;
            int m2 = (p[1] <= p[2])?2:1;
            if (!(p[m1] >= 1 && p[m2] >= 1)){
                if (max(p[m1], p[m2])%2 != 0){
                    draws = -1;
                }
                break;
            }
            p[m1]-=1;
            p[m2]-=1;
            draws += 1;
        }
        cout << draws << endl;
    }
    return 0;
}