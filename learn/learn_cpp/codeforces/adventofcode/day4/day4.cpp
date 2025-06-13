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
    vector<string> v;
    int sz = 0;
    // // horizontal
    // while (1){
    //     string s;
    //     inp >> s;
    //     if (s == ""){break;}
    //     v.push_back(s);
    //     sz = s.size();
    //     for (int i=0;i<s.size()-3;i++){
    //         // cout << i << endl;
    //         if (s.substr(i, 4) == "XMAS" || s.substr(i, 4) == "SAMX"){
    //             ans += 1;
    //             // cout << 'h' << endl;
    //         }
    //     }
    // }
    // // cout << ans << endl;

    // // verticle
    // for (int i=0;i<sz;i++){
    //     for (int j=0;j<v.size();j++){
    //         if (j+3 < v.size()){
    //             if ((v[j][i] == 'X' && (v[j+1][i] == 'M' && (v[j+2][i] == 'A' && (v[j+3][i]=='S')))) ||
    //             (v[j][i] == 'S' && (v[j+1][i] == 'A' && (v[j+2][i] == 'M' && (v[j+3][i]=='X'))))
    //             ){
    //                 ans += 1;
    //                 // cout << 'v' << endl;
    //             }
    //         }
    //     }
    // }
    // // cout << ans << endl;


    // // diagonal
    // for (int j=0;j<v.size()-3;j++){
    //     for (int i=3;i<sz;i++){
    //         if ((v[j][i] == 'X' && (v[j+1][i-1]=='M' && (v[j+2][i-2]=='A'&&(v[j+3][i-3]=='S')))) || ((v[j][i] == 'S' && (v[j+1][i-1]=='A' && (v[j+2][i-2]=='M'&&(v[j+3][i-3]=='X')))))){
    //             ans += 1;
    //             // cout << "d1" << endl;

    //         }
    //     }
    // }
    // // cout << ans << endl;

    // for (int j=0;j<v.size()-3;j++){
    //     for (int i=0;i<sz-3;i++){
    //         if ((v[j][i] == 'X' && (v[j+1][i+1]=='M' && (v[j+2][i+2]=='A'&&(v[j+3][i+3]=='S')))) || ((v[j][i] == 'S' && (v[j+1][i+1]=='A' && (v[j+2][i+2]=='M'&&(v[j+3][i+3]=='X')))))){
    //             ans += 1;
    //             // cout << "d2" << endl;

    //         }
    //     }
    // }

    // part 2
    while (1){
        string s;
        inp >> s;
        if (s == ""){break;}
        v.push_back(s);
        sz = s.size();
    }

    for (int i=1;i<v.size()-1;i++){
        for (int j=1;j<sz-1;j++){
            if (v[i][j] == 'A'){
                if (((v[i-1][j-1] == 'S' && v[i+1][j+1] == 'M') || (v[i-1][j-1] == 'M' && v[i+1][j+1] == 'S')) && (
                    (v[i-1][j+1] == 'S' && v[i+1][j-1] == 'M') || (v[i-1][j+1] == 'M' && v[i+1][j-1] == 'S')
                )){
                    ans += 1;
                }
            }
        }
    }

    cout << ans << endl;
    inp.close();

    

    return 0;
}