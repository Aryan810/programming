#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;


bool logic(string s, ll sum){
    if (sum%9 == 0){
        return 1;
    }
    ll two = 0;
    ll six = 0;
    for (int i=0;i<s.size();i++){
        if (s[i] == '2'){two += 1;}
        else if (s[i] == '3'){six += 1;}
    }

    for (int i=0;i<six+1;i++){
        ll x = sum + 6*i;
        ll y = x + 2*two;
        // cout << x << " " << y << endl;
        if (x % 9 == 0){
            return 1;
        }else{
            if (x%2 == 0){
                if (y >= x + 18 - x%18){
                    return 1;
                }
            }else{
                ll p = x + 9 - x%9;
                if (p%2 == 0){
                    p += 9;
                }
                if (y >= p){
                    return 1;
                }
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
        string s;
        cin >> s;
        ll sum = 0;
        for (int i=0;i<s.size();i++){
            sum += s[i]-'0';
        }
        // cout << "sum: " << sum << endl;
        cout << (logic(s, sum)?"YES":"NO") << endl;
        

    }

    return 0;
}