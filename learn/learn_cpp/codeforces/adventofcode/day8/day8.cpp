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

    vector <string> v;
    while (1){
        string s;
        inp >> s;
        if (s == ""){break;}
        v.push_back(s);
    }
    set< pair<int, int> > antinodes;
    map<char, vector<pair<int, int> > > m;
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            if (v[i][j] != '.'){
                m[v[i][j]].push_back({i, j});
                antinodes.insert({i, j});
            }
        }
    }
    for (auto a: m){
        auto b = a.second;
        auto n = b.size();

        for (int i=0;i<n-1;i++){

            for (int j=i+1;j<n;j++){
                pair<int, int> p = b[i];
                pair<int, int> q = b[j];
                while (1){
                    pair<int, int> p1 = {2*(q.first)-(p.first), 2*(q.second)-(p.second)};
                    // pair<int, int> p2 = {2*(p.first)-(q.first), 2*(p.second)-(q.second)};
                    if ((p1.first >= 0 && p1.first < v[0].size())&&(p1.second >= 0 && p1.second < v.size())){antinodes.insert(p1);}else{break;}
                    // if ((p2.first >= 0 && p2.first < v[0].size())&&(p2.second >= 0 && p2.second < v.size())){antinodes.insert(p2);}else{x += 1;}
                    p = q;
                    q = p1;
                }
                p = b[i];
                q = b[j];
                while (1){
                    // pair<int, int> p1 = {2*(q.first)-(p.first), 2*(q.second)-(p.second)};
                    pair<int, int> p2 = {2*(p.first)-(q.first), 2*(p.second)-(q.second)};
                    // if ((p1.first >= 0 && p1.first < v[0].size())&&(p1.second >= 0 && p1.second < v.size())){antinodes.insert(p1);}else{x += 1;}
                    if ((p2.first >= 0 && p2.first < v[0].size())&&(p2.second >= 0 && p2.second < v.size())){antinodes.insert(p2);}else{break;}
                    q = p;
                    p = p2;
                }
            }
        }
    }
    cout << antinodes.size() << endl;
    inp.close();

    return 0;
}