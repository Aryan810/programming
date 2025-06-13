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
    inp.open("input1.txt");
    // 1748
    vector<string> v;
    while (1){
        string s;
        inp >> s;
        if (s == ""){break;}
        v.push_back(s);
        // cout << "EY" << endl;
    }

    pair<int, int> g;
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            if (v[i][j] == '^'){
                g = {i, j};
                break;
            }
        }
    }
    auto g1 = g;
    set< pair<int, int> > s;
    int facing = 0;
    while ((g.first < v.size() && g.first >= 0) && (g.second < v[0].size() && g.second >= 0)){
    cout << g.first << " " << g.second << " " << facing << endl;

        if (facing == 0){
            while (g.first >= 0){
                s.insert(g);
                if (g.first > 0 && v[g.first-1][g.second] == '#'){
                    facing = 1;
                    break;
                }
                g.first -= 1;
            }
            if (g.first < 0){
                break;
            }
        }else if (facing == 1){
            while (g.second < v[0].size()){
                s.insert(g);
                if (g.second < v[0].size()-1 && v[g.first][g.second+1] == '#'){
                    facing = 2;
                    break;
                }
                g.second += 1;
            }
            if (g.second >= v[0].size()){break;}
        }else if (facing == 2){
            while (g.first < v.size()){
                s.insert(g);
                if (g.first < v.size()-1 && v[g.first+1][g.second] == '#'){
                    facing = 3;
                    break;
                }
                g.first += 1;
            }
            if (g.first >= v.size()){break;}
        }else if (facing == 3){
            while (g.second >= 0){
                s.insert(g);
                if (g.second > 0 && v[g.first][g.second-1] == '#'){
                    facing = 0;
                    break;
                }
                g.second -= 1;
            }
            if (g.second < 0){
                break;
            }
        }
    }
    // cout << s.size() << endl;
    ll ans = 0;
    for (auto o: s){
        if (o == g1){continue;}
        v[o.first][o.second] = '#';
        // loop
        g = g1;
        set< pair<int, int> > s1;
        int facing = 0;
        int x = 0;
        while ((g.first < v.size() && g.first >= 0) && (g.second < v[0].size() && g.second >= 0)){
            // cout << g.first << " " << g.second << " " << facing << endl;
            x += 1;
            cout << ans << endl;
            if (facing == 0){
                while (g.first >= 0){
                    s1.insert(g);
                    if (g.first > 0 && v[g.first-1][g.second] == '#'){
                        facing = 1;
                        break;
                    }
                    g.first -= 1;
                }
                if (g.first < 0){
                    break;
                }
            }else if (facing == 1){
                while (g.second < v[0].size()){
                    s1.insert(g);
                    if (g.second < v[0].size()-1 && v[g.first][g.second+1] == '#'){
                        facing = 2;
                        break;
                    }
                    g.second += 1;
                }
                if (g.second >= v[0].size()){break;}
            }else if (facing == 2){
                while (g.first < v.size()){
                    s1.insert(g);
                    if (g.first < v.size()-1 && v[g.first+1][g.second] == '#'){
                        facing = 3;
                        break;
                    }
                    g.first += 1;
                }
                if (g.first >= v.size()){break;}
            }else if (facing == 3){
                while (g.second >= 0){
                    s1.insert(g);
                    if (g.second > 0 && v[g.first][g.second-1] == '#'){
                        facing = 0;
                        break;
                    }
                    g.second -= 1;
                }
                if (g.second < 0){
                    break;
                }
            }
            if (x > 6000){ans += 1;break;}
        }
        // loop end
        v[o.first][o.second] = '.';
    }

    cout << ans << endl;

    inp.close();

    

    return 0;
}