#include <bits/stdc++.h>
#include <fstream>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    ll ans = 0;
        bool on = 1;
    while (1){
        string s;
        inp >> s;
        int i = 0;
        while (i<s.size()){
            if (i+3 < s.size() && (s.substr(i, 4) == "do()")){on = 1;i+=4;}
            if (i+6 < s.size() && s.substr(i, 7)=="don't()"){on = 0;i+=7;}
            if (i+3 < s.size()){
                if (on && (s[i]=='m' && (s[i+1]=='u' && (s[i+2]=='l' && s[i+3] == '(')))){
                    i += 4;
                    bool valid = 1;
                    string xs, ys;
                    for (int j=0;valid && j<3;j++){
                        if (s[i] < 48 || s[i] > 57){
                            valid = 0;
                            break;
                        }
                        xs += s[i];
                        i += 1;
                        if (s[i]==','){
                            i += 1;
                            break;
                        }
                    }
                    for (int j=0;valid && j<3;j++){
                        if (s[i] >= 48 && s[i] <= 57){
                            ys += s[i];
                            i += 1;
                        }else{
                            valid = 0;
                            break;
                        }
                        if (s[i]==')'){
                            break;
                        }
                    }
                    if (valid && s[i]==')'){
                        ans += stoi(xs)*stoi(ys);
                    }
                }
            }
            i += 1;
        }
        if (s == ""){break;}
    }
    cout << ans << endl;
    inp.close();

    

    return 0;
}