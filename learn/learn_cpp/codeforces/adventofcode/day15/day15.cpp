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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        ifstream inp;
        inp.open("input.txt");

        vector<string> v;
        pair<int, int> robo;
        while (1){
            string s;
            getline(inp, s);
            // cout << 1 << " " << s << endl;
            if (s == ""){break;}
            v.push_back(s);
            auto pos = s.find('@');
            if (pos < s.size()){
                robo = {v.size()-1, pos};
            }
        }

        vector<string> moves;
        
        while (1){
            string s;
            getline(inp, s);
            // cout << 2 << " " << s << endl;
            if (s == ""){break;}
            moves.push_back(s);
        }
        // cout << "ROBO: " << robo.first << " " << robo.second << endl;
        for (auto line: v){cout << line << endl;}cout << endl;
        for (int i=0;i<moves.size();i++){
            for (int j=0;j<moves[i].size();j++){
                auto move = moves[i][j];
                // cout << "MOVE: " << move << endl;
                if (move == '>'){
                    // cout << "here!" << endl;
                    auto temp = robo;
                    temp.second += 1;
                    while (v[temp.first][temp.second] == 'O'){
                        temp.second += 1;
                    }
                    if (v[temp.first][temp.second] == '.'){
                        temp.second -= 1;
                        while (temp != robo){
                            v[temp.first][temp.second] = '.';
                            v[temp.first][temp.second+1] = 'O';
                            cout << "changing..1." << endl;
                            temp.second -= 1;
                        }
                        v[temp.first][temp.second] = '.';
                        v[temp.first][temp.second+1] = '@';
                        robo.second += 1;
                    }
                }else if (move == '<'){
                    auto temp = robo;
                    temp.second -= 1;
                    while (v[temp.first][temp.second] == 'O'){
                        temp.second -= 1;
                    }
                    cout << "<<<: " << v[temp.first][temp.second] << endl;
                    if (v[temp.first][temp.second] == '.'){
                        temp.second += 1;
                        while (temp != robo){
                            v[temp.first][temp.second] = '.';
                            v[temp.first][temp.second-1] = 'O';
                            temp.second += 1;
                            cout << "changing..2." << endl;

                        }
                        v[temp.first][temp.second] = '.';
                        v[temp.first][temp.second-1] = '@';
                        robo.second -= 1;
                    }
                }else if (move == '^'){
                    bool canMove = 1;
                    auto temp = robo;
                    temp.first -= 1;
                    while (v[temp.first][temp.second] == 'O'){
                        temp.first -= 1;
                    }
                    if (v[temp.first][temp.second] == '.'){
                        temp.first += 1;
                        while (temp != robo){
                            v[temp.first][temp.second] = '.';
                            v[temp.first-1][temp.second] = 'O';
                            temp.first += 1;
                            cout << "changing..3." << endl;

                        }
                        v[temp.first][temp.second] = '.';
                        v[temp.first-1][temp.second] = '@';
                        robo.first -= 1;
                    }
                }else if (move == 'v'){
                    bool canMove = 1;
                    auto temp = robo;
                    temp.first += 1;
                    while (v[temp.first][temp.second] == 'O'){
                        temp.first += 1;
                    }
                    if (v[temp.first][temp.second] == '.'){
                        temp.first -= 1;
                        while (temp != robo){
                            v[temp.first][temp.second] = '.';
                            v[temp.first+1][temp.second] = 'O';
                            temp.first -= 1;
                            cout << "changing..4." << endl;

                        }
                        v[temp.first][temp.second] = '.';
                        v[temp.first+1][temp.second] = '@';
                        robo.first += 1;
                    }
                }
            }
        }

        for (auto line: v){cout << line << endl;}

        // calculating answer
        ll ans = 0;
        for (int i=0;i<v.size();i++){
            for (int j=0;j<v[i].size();j++){
                if (v[i][j] == 'O'){
                    ans += i*100 + j;
                }
            }
        }
        cout << ans << endl;
        inp.close();
    

    return 0;
}