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
    int ans = 0;
    while (1){
        string s;
        getline(inp, s);
        if (s == ""){break;}
        vi a;
        string t;
        for (int i=0;i<s.size();i++){
            if (s[i] == ' '){
                a.push_back(stoi(t));
                t="";
                continue;
            }
            t.push_back(s[i]);
        }
        if (t.size() > 0){a.push_back(stoi(t));}
        int inc = -1;
        int safe = 1;
        for (int i=0;i<a.size()-1;i++){
            if (inc == -1){
                if (a[i+1] > a[i]){
                    inc = 1;
                }else if (a[i+1] < a[i]){
                    inc = 0;
                }
            }else{
                if((inc && a[i+1] < a[i]) || (!inc && a[i+1] > a[i])){
                    safe = 0;
                    break;
                }
            }
            if (abs(a[i+1]-a[i]) > 3 || abs(a[i+1]-a[i]) < 1){
                safe = 0;
                break;
            }
        }
        if (!safe){
            for (int l=0;l<a.size();l++){
                auto b = a;
                bool safe1 = 1;
                b.erase(b.begin() + l);
                inc = -1;
                for (int i=0;i<b.size()-1;i++){
                    if (inc == -1){
                        if (b[i+1] > b[i]){
                            inc = 1;
                        }else if (b[i+1] < b[i]){
                            inc = 0;
                        }
                    }else{
                        if((inc && b[i+1] < b[i]) || (!inc && b[i+1] > b[i])){
                            safe1 = 0;
                            break;
                        }
                    }
                    if (abs(b[i+1]-b[i]) > 3 || abs(b[i+1]-b[i]) < 1){
                        safe1 = 0;
                        break;
                    }
                }
                if (safe1){
                    ans += 1;
                    break;
                }
            }
        }
        ans += safe;
    }
    cout << ans << endl;
    inp.close();

    

    return 0;
}