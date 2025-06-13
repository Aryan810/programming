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

ll ans = 1e18;
vector<string> v;
void solve(pair<int, int> s, int face, ll curr, set< pair<int, int> > path){

    cout << path.size() << endl;
    if (path.find(s) != path.end()){return;}else{path.insert(s);}
    // cout <<s .first << " : " << s.second << " face: " << face << " curr: " << curr << v[s.first][s.second] << endl;
    if (v[s.first][s.second] == 'E'){
        if (ans > curr){
            ans = curr;
            cout << ans << endl;
            ofstream out;
            out.open("output.txt");
            out << ans << endl;
            out.close();
        }
        return;
    }
    if (face == 1){ // north
        if (v[s.first-1][s.second] != '#'){
            solve({s.first-1, s.second}, 1, curr+1, path);
        }
        if (v[s.first][s.second+1] != '#'){
            solve({s.first, s.second+1}, 0, curr+1001, path);
        }
        if (v[s.first][s.second-1] != '#'){
            solve({s.first, s.second-1}, 2, curr+1001, path);
        }
    }
    else if (face == 2){ // west
        if (v[s.first-1][s.second] != '#'){
            solve({s.first-1, s.second}, 1, curr+1001, path);
        }
        if (v[s.first+1][s.second] != '#'){
            solve({s.first+1, s.second}, 3, curr+1001, path);
        }
        if (v[s.first][s.second-1] != '#'){
            solve({s.first, s.second-1}, 2, curr+1, path);
        }
    }
    else if (face == 0){ // east
        if (v[s.first-1][s.second] != '#'){
            solve({s.first-1, s.second}, 1, curr+1001, path);
        }
        if (v[s.first+1][s.second] != '#'){
            solve({s.first+1, s.second}, 3, curr+1001, path);
        }
        if (v[s.first][s.second+1] != '#'){
            solve({s.first, s.second+1}, 0, curr+1, path);
        }
    }else{ // south
        if (v[s.first+1][s.second] != '#'){
            solve({s.first+1, s.second}, 3, curr+1, path);
        }
        if (v[s.first][s.second+1] != '#'){
            solve({s.first, s.second+1}, 0, curr+1001, path);
        }
        if (v[s.first][s.second-1] != '#'){
            solve({s.first, s.second-1}, 2, curr+1001, path);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input1.txt");

    while (1){
        string s;
        getline(inp, s);
        if (s == ""){break;}
        v.push_back(s);
    }
    pair<int, int> s, e;
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            if (v[i][j] == 'E'){
                e = {i, j};
            }else if (v[i][j] == 'S'){
                s = {i, j};
            }
        }
    }
    // 0 -> east;
    // 1 -> north;
    // 2 -> west;
    // 3 -> south;
    int face = 0;
    set <pair<int, int> > path;
    solve(s, face, 0, path);
    cout << ans << endl;
    inp.close();
    return 0;
}