#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool logic(string & s, int i, char v, int & cnt){
    i -= 1;
    if (s.size() < 4){
        return 0;
    }
    string sub1 = s.substr(((i-3>0)?(i-3):0), (i - ((i-3>0)?(i-3):0))+4);
    s[i] = v;
    int st = (i-3>0)?(i-3):0;
    string sub2 = s.substr(((i-3>0)?(i-3):0), (i - ((i-3>0)?(i-3):0))+4);
    bool x1 = sub1.find("1100") < sub1.size();
    bool x2 = sub2.find("1100") < sub2.size();
    // cout << x1 << " <- " << sub1 << " " << sub2 << " -> " << x2 << endl;
    if (x1 && x2){
        return 1;
    }else if(!x1 && !x2){
        if (cnt == 0){return 0;}else{return 1;}
    }else if (!x1 && x2){
        cnt += 1;
        return 1;
    }else{
        cnt -= 1;
        if (cnt == 0){return 0;}else{return 1;}
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int q;
        cin >> q;
        int cnt = 0;
        for (int i=0;i<(s.size()-3);i++){
            if (s.substr(i, 4) == "1100"){
                cnt += 1;
            }
        }
        // cout << "size: " << a.size() << endl;
        while (q--){
            int i;
            char v;
            cin >> i >> v;
            cout << ((logic(s, i, v, cnt))?"YES":"NO") << endl;
        }
    }

    return 0;
}