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
set< pair<int, int> > used;
vector< set<pair<int, int> > > dta;

void add(pair<int, int> a, vector<string> & v, set< pair<int, int> > & temp){
    int x = a.first;
    int y = a.second;
    char val = v[x][y];
    bool usedd = (used.find(a) != used.end());
    used.insert({x, y});
    // cout << "USED: {" << x << ", " << y << "} "<<dta.size() << endl;
    temp.insert({x, y});
    cout << x << " : " << y << endl;
    if (x+1 < v.size() && (v[x+1][y] == val && used.find({x+1, y}) == used.end())){
        add({x+1, y}, v, temp);
    }
    if(x-1 >= 0 && (v[x-1][y] == val && used.find({x-1, y}) == used.end())){
        add({x-1, y}, v, temp);
    }
    if(y-1 >= 0 && (v[x][y-1] == val && used.find({x, y-1}) == used.end())){
        add({x, y-1}, v, temp);
    }
    if(y+1 < v[0].size() && (v[x][y+1] == val && used.find({x, y+1}) == used.end())){
        add({x, y+1}, v, temp);
    }
}

void add_all(pair<int, int> a, vector<string> & v){
    cout << "{" <<  a.first << ", " << a.second << "}" << v[a.first][a.second] << endl;
    set< pair<int, int> > temp;
    add(a, v, temp);
    dta.push_back(temp);
}

void solve(vector<string> & v){
    for (int i = 0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            if (used.find({i, j}) == used.end()){
                add_all({i, j}, v);
            }
        }
    }
    ll ans = 0;
    for (auto a: dta){
        ll peri = 0;
        ll area = a.size();
        for (auto b: a){
            int x = b.first;
            int y = b.second;
            int contrib = 4;
            int ip = peri;
            bool r=0, l=0, u=0, d=0;
            if (x+1 < v.size() && a.find({x+1, y})!=a.end()){
                contrib -= 1;
                d = 1;
            }
            if(x-1 >= 0 && a.find({x-1, y})!=a.end()){
                contrib -= 1;
                u = 1;
            }
            if(y-1 >= 0 && a.find({x, y-1})!=a.end()){
                contrib -= 1;
                l = 1;
            }
            if(y+1 < v[0].size() && a.find({x, y+1})!=a.end()){
                contrib -= 1;
                r = 1;
            }
            
            if (contrib == 3){
                peri += 2;
            }else if (contrib == 2){
                // case 1:
                if (r&u){
                    if ((x-1>=0 && y+1 < v[0].size()) && a.find({x-1, y+1}) == a.end()){
                        peri += 2;
                    }else{
                        peri += 1;
                    }
                }else if (l&d){
                    if ((x+1<v.size() && y-1 >= 0) && a.find({x+1, y-1}) == a.end()){
                        peri += 2;
                    }else{
                        peri += 1;
                    }
                }else if (u&l){
                    if ((x-1>=0 && y-1 >= 0) && a.find({x-1, y-1}) == a.end()){
                        peri += 2;
                    }else{
                        peri += 1;
                    }
                }else if (r&d){
                    if ((x+1<v.size() && y+1 < v[0].size()) && a.find({x+1, y+1}) == a.end()){
                        peri += 2;
                    }else{
                        peri += 1;
                    }
                }
            }else if(contrib == 1){
                // case 2: 
                peri += 2;
                if (!r){
                    if ((x+1>=0 && y-1 < v[0].size()) && a.find({x+1, y-1}) != a.end()){
                        peri -= 1;
                    }
                   if ((x-1>=0 && y-1 < v[0].size()) && a.find({x-1, y-1}) != a.end()){
                        peri -= 1;
                    }
                }else if (!l){
                    if ((x+1>=0 && y+1 < v[0].size()) && a.find({x+1, y+1}) != a.end()){
                        peri -= 1;
                    }
                   if ((x-1>=0 && y+1 < v[0].size()) && a.find({x-1, y+1}) != a.end()){
                        peri -= 1;
                    }
                }else if (!u){
                    if ((x+1>=0 && y-1 < v[0].size()) && a.find({x+1, y-1}) != a.end()){
                        peri -= 1;
                    }
                   if ((x+1>=0 && y+1 < v[0].size()) && a.find({x+1, y+1}) != a.end()){
                        peri -= 1;
                    }
                }else{ // if (!d)
                    if ((x-1>=0 && y-1 < v[0].size()) && a.find({x-1, y-1}) != a.end()){
                        peri -= 1;
                    }
                   if ((x-1>=0 && y+1 < v[0].size()) && a.find({x-1, y+1}) != a.end()){
                        peri -= 1;
                    }
                }
            }else if(contrib == 0){
                peri += 4;
                if ((x+1>=0 && y-1 < v[0].size()) && a.find({x+1, y-1}) != a.end()){
                        peri -= 1;
                    }
                if ((x+1>=0 && y+1 < v[0].size()) && a.find({x+1, y+1}) != a.end()){
                    peri -= 1;
                }
                if ((x-1>=0 && y-1 < v[0].size()) && a.find({x-1, y-1}) != a.end()){
                        peri -= 1;
                    }
                if ((x-1>=0 && y+1 < v[0].size()) && a.find({x-1, y+1}) != a.end()){
                    peri -= 1;
                }
                
            }else{ // contrib == 4
                peri += 4;
            }

            cout << "{" << x << ", " << y << "}" << "contrib: " << contrib << " " << "delta-peri: " << peri-ip << endl;
            // peri += contrib;
        }
        cout << a.size() << endl;
        cout << "PERI: " << peri << endl;
        ans += peri*area;
    }
    cout << ans << endl;
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

    solve(v);

    inp.close();
    return 0;
}