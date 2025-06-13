#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(string & s){
    for (int i=0;i<s.size();i++){
        if (s[i] == 'h'){
            string sub = "h";
            string r = "hello";
            for (int j=1;j<r.size() && i<s.size();j++){
                if (s[i] == r[j]){
                    sub.push_back(s[i]);
                    i++;
                }else{
                    j--;
                    i++;
                }
                // cout << sub << endl;

                // cout << i << endl;
            }
            if (sub == r){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    cout << (logic(s)?"YES":"NO") << endl;

    return 0;
}