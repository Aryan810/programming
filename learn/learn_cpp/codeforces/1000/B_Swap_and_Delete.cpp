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
        string s;
        cin >> s;

        int one=0;
        int zero=0;
        for (int i=0;i<s.size();i++){
            (s[i]=='0')?zero+=1:one+=1;
        }
        for (int i=0;i<s.size();i++){
            if (s[i] == '0'){
                if (one == 0){
                    break;
                }else{
                    one -= 1;
                }
            }else{
                if (zero == 0){
                    break;
                }else{
                    zero -= 1;
                }
            }
        }
        cout << one+zero << endl;

        

    }

    return 0;
}