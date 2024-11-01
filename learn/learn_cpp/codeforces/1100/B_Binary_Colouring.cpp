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
        vector<int> out(32, 0);
        vector<int> bin(32, 0);
        int x = n;
        int i=0;
        while (x != 0){
            bin[i] = int(x&1);
            i+=1;
            x = x/2;
        }
        // cout << "bin" << endl;
        // for(auto a: bin){cout <<  a << " ";}cout << endl;
        for (int i=0;i<bin.size();i++){
            if (bin[i] == 1){
                int num = 0;
                while (bin[i] != 0){
                    num += 1;
                    i += 1;
                }
                if (num >= 2){
                    out[i] = 1;
                    bin[i] = 1;
                    out[i-num] = -1;
                    i -= 1;
                }
                else{
                    i -= 1;
                    out[i] = 1;
                }
            }
        }
        // for (int i=0;i<out.size();i++){
        //     cout << out[i] << " ";
        // }
        // cout << endl;
        // while (x >= 0){
        //     int k = x&1;
        //     if (k == 1){
        //         int num = 0;
        //         if (out[i] == 1){
        //             num += 1;
        //         }
        //         while (x&1 != 0){
        //             num += 1;
        //             x = x/2;
        //         }
        //         if (num >= 2){
        //             out[i] = -1;
        //             out[i+num] = 1;
        //         }else{
        //             out[i] = 1;
        //         }
        //         i += num;
        //     }else{
        //         i += 1;
        //         x = x/2;
        //     }
        //     if (x == 0){
        //         break;
        //     }
        // }

        int sz = 0;
        for (int i=31;i>=0;i--){
            if (out[i] != 0){
                sz = i+1;
                break;
            }
        }
        cout << sz << endl;
        for (int i=0;i<sz;i++){
            cout << out[i] << " ";
        }
        cout << endl;

    }

    return 0;
}