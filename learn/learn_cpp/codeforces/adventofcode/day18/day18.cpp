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
set< pair<int, int> > currupted;
int X = 71;
int Y = 71;
void solve(pair<int, int> s, set< pair<int, int> > path, pair<int, int> prev){

    cout << path.size() << " " << ans << endl;
    if (path.find(s) != path.end()){cout << "Yes" << endl;return;}else{path.insert(s);}

    if (s.first == X-1 && s.second == Y-1){
        if (path.size() < ans){
            cout << "HERE!" << endl;
            ofstream out;
            out.open("output.txt");
            for (int i=0;i<Y;i++){
                for (int j=0;j<X;j++){
                    if (path.find({j, i}) != path.end()){
                        out << '*';
                    }else if (currupted.find({j, i}) == currupted.end()){
                        out << '.';
                    }else{
                        out << '#';
                    }
                }out << endl;
            }
            out.close();
            ans = path.size();
        }
        return;
    }
    if ((s.first-1 >= 0 && currupted.find({s.first-1, s.second}) == currupted.end()) && !(s.first-1 == prev.first && s.second == prev.second)){
        solve({s.first-1, s.second}, path, s);
    }
    if ((s.first + 1 < X && currupted.find({s.first+1, s.second}) == currupted.end()) && !(s.first+1 == prev.first && s.second == prev.second)){
        solve({s.first+1, s.second}, path, s);
    }
    if ((s.second-1 >= 0 && currupted.find({s.first, s.second-1}) == currupted.end()) && !(s.first == prev.first && s.second-1 == prev.second)){
        solve({s.first, s.second-1}, path, s);
    }
    if ((s.second + 1 < Y && currupted.find({s.first, s.second+1}) == currupted.end()) && !(s.first == prev.first && s.second+1 == prev.second)){
        solve({s.first, s.second+1}, path, s);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    int num = 1;
    while (1){
        string s;
        getline(inp, s);
        if (s == ""){break;}
        int i=0;
        while (s[i] != ','){
            i += 1;
        }
        currupted.insert({stoi(s.substr(0, i)), 
        stoi(s.substr(i+1, s.size()-i-1))});
        num-=1;
        if (num == 0){
            break;
        }
    }
    for (auto curr: currupted){
        cout << curr.first << " : " << curr.second << endl;
    }
    
    pair<int, int> s;
    s = {0, 0};

    set <pair<int, int> > path;
    path.insert(s);
    if ((s.first+1 < X && currupted.find({s.first+1, s.second}) == currupted.end())){
        solve({s.first+1, s.second}, path, s);
    }
    if ((s.second + 1 < Y && currupted.find({s.first, s.second+1}) == currupted.end())){
        solve({s.first, s.second+1}, path, s);
    }
    cout << ans-1 << endl;
    inp.close();
    return 0;
}