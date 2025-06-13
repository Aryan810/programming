#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void logic(string s){
    if (s == "()"){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i=0;i<s.size()-1;i++){
        if (s[i] == ')' && s[i+1] == '('){
            for (int j=0;j<s.size();j++){
                cout << '(';
            }
            for (int j=0;j<s.size();j++){
                cout << ')';
            }
            break;
        }
        if (s[i] == s[i+1]){
            for (int j=0;j<s.size();j++){cout << "()";}
            break;
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        logic(s);
        

    }

    return 0;
}