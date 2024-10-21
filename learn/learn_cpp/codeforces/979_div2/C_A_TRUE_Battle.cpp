#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(string & s, int n){
    if (s[0] == '1' || s[n-1] == '1'){
        return 1;
    }else{
        for (int i=0;i<n;i++){
            if (s[i] == '1'){
                int ones = 0;
                while (s[i] != '0' && i!=n-1){
                    ones += 1;
                    i++;
                }
                if (ones >= 2){return 1;}
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << (logic(s, n)?"YES":"NO") << endl;
    }

    return 0;
}