#include <bits/stdc++.h>
#include <fstream>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;
ll binexpiter(ll a, ll b){
    ll ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

void solve(ll curr, vi & a, int i, ll & value, bool & ans){
    if (i == a.size()){
        if (curr == value){
            ans = 1;
        }
        return ;
    }
    solve(curr*a[i], a, i+1, value, ans);
    solve(curr+a[i], a, i+1, value, ans);
    ll b = log10(a[i])+1;
    solve((curr*binexpiter(10, b))+a[i], a, i+1, value, ans);
}

bool logic(vi & a, ll value){
    bool ans = 0;
    ll curr = a[0];
    solve(curr, a, 1, value, ans);
    return ans;
}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    ll ans = 0;
    while (1){
        string s;
        getline(inp, s);
        if (s == ""){break;}
        int j = s.find(": ");
        ll value = stol(s.substr(0, j));
        vi a;
        for (int i=j+2;i<s.size();i++){
            string x;
            while (i < s.size() && s[i] != ' '){
                x.push_back(s[i]);
                i+=1;
            }
            a.push_back(stol(x));
        }
        // cout << a.size() << endl;
        // for (int i=0;i<a.size();i++){
        //     cout << a[i] << " ";
        // }cout << endl;
        // cout << value << endl;
        if (logic(a, value)){
            ans += value;
        }
    }
    cout << ans << endl;



    inp.close();

    

    return 0;
}