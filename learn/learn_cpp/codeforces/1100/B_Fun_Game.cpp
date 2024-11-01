#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(string & s, string & t){
    if (s[0] == '1'){return 1;}
    else if (s[0] == '0' && t[0] == '1'){return 0;}
    else{
        for (int i=0;i<s.size();i++){
            if (s[i] == '1')
            if (s[i] == '0' && t[i] == '1'){return 0;}
            if (s[i] == '1' && t[i] == '0'){return 1;}
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        cout << (logic(s, t)?"YES":"NO") << endl;
    }

    return 0;
}