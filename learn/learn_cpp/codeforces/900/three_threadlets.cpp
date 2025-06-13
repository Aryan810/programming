#include <iostream>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

bool logic(lli a, lli b, lli c){
    lli sum = a+b+c;
    vector<lli> e(3);
    e[0] = a;
    e[1] = b;
    e[2] = c;
    int d[] = {3, 4, 5, 6};
    // cout << "SUM: " << sum << endl;
    for (int di: d){
        if (sum%di == 0){
            // cout << "IN: " << di << endl;
            int x = sum/di;
            int oper = 0;
            for (int i=0;i<e.size();i++){
                if (e[i]%x != 0){
                    break;
                }else{
                    oper += e[i]/x;
                }
            }
            if (oper == di){
                return 1;
            }
        }
    }
    return 0;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        lli a, b, c;
        cin >> a >> b >> c;
        cout << (logic(a, b, c)?"YES":"NO") << endl;

    }

    return 0;
}