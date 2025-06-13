#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// void lop(int a, int b, int c, int d, vector<string> & v, map<pair<int, int>, int> & s){
void lop(int a, int b, int c, int d, vector<string> & v, ll& ans){
    auto x = v[a][b];
    // cout << a << " " << b << " " << x << endl;

    if (x == '9'){
        // s[{a, b}] = 1;
        ans += 1;
        return;
    }
    if (c == a){
        if (a+1 < v.size() && v[a+1][b] == x + 1){
            lop(a+1, b, a, b, v, ans);
        }
        if (a-1 >= 0 && v[a-1][b] == x + 1){
            lop(a-1, b, a, b, v, ans);
        }
        if (b > d){
            if (b+1 < v[0].size() && v[a][b+1] == x+1){
                lop(a, b+1, a, b, v, ans);
            }
        }else{
            if (b-1 >= 0 && v[a][b-1] == x+1){
                lop(a, b-1, a, b, v, ans);
            }
    }
    }else{
        if (b-1 >= 0 && v[a][b-1] == x + 1){
            lop(a, b-1, a, b, v, ans);
        }
        if (b+1 < v[0].size() && v[a][b+1] == x + 1){
            lop(a, b+1, a, b, v, ans);
        }
        if (c > a){
            if (a-1 >= 0 && v[a-1][b] == x+1){
                lop(a-1, b, a, b, v, ans);
            }
        }else{
            if (a+1 < v.size() && v[a+1][b] == x+1){
                lop(a+1, b, a, b, v, ans);
            }
        }
    }
}


void isgood(int i, int j, vector<string> & v, ll & ans){
    if (i+1 < v.size() && v[i+1][j] == '1'){
        lop(i+1, j, i, j, v, ans); 
    }
    if (i-1 >= 0 && v[i-1][j] == '1'){
        lop(i-1, j, i, j, v, ans);
    }
    if (j+1 < v[0].size() && v[i][j+1] == '1'){
        lop(i, j+1, i, j, v, ans);
    }
    if (j-1 >= 0 && v[i][j-1] == '1'){
        lop(i, j-1, i, j, v, ans);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");

    vector<string> v;
    while (1){
        string s;
        inp >> s;
        if (s == ""){break;}
        v.push_back(s);
    }
    ll ans = 0;
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            if (v[i][j] == '0'){
                isgood(i, j, v, ans);
            }
        }
    }
    cout << ans << endl;
    inp.close();
    return 0;
}