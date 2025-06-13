#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool is_nbr(pair<int, int> & p1, pair<int, int> & p2){
    int i = p1.first;
    int j = p1.second;
    set< pair<int, int> > nbr;
    nbr.insert({i+1, j+1});
    nbr.insert({i+1, j-1});
    nbr.insert({i+1, j});
    nbr.insert({i-1, j});
    nbr.insert({i-1, j+1});
    nbr.insert({i-1, j-1});
    nbr.insert({i, j+1});
    nbr.insert({i, j-1});
    return (nbr.find(p2) != nbr.end());
}

string logic(multimap <int, pair<int, int> > & m){
    if (m.begin()->first == int('C')){return "CCC";}
    auto fit = m.begin();
    int f = fit->first;
    set<string> p;
    while (fit->first == f){
        auto fir = *fit;
        // part 2
        auto sit = m.begin();
        pair <int, pair<int, int> > thi = *(m.begin());
        int schar = sit->first;
        set<string> k;
        while (1){
            if (sit != fit){
                if (is_nbr(fir.second, sit->second)){
                    // cout << "CHANGE 1" << endl;
                    auto sec = *sit;
                    
                    // part 3
                    string s;
                    s.push_back(char(fir.first));
                    s.push_back(char(sec.first));
                    s.push_back('A');
                    auto b = ++m.begin();
                    while (b != m.end()){
                        if (b->second != sec.second && b->second != fit->second){
                            if (is_nbr(sec.second, b->second)){
                                    // cout << "CHANGE 2" << endl;
                                    thi = *b;
                                    s[2] = char(thi.first);
                                    k.insert(s);
                            }
                        }
                        b++;
                    }
                };
            }
            // cout << "INC" << endl;
            sit++;
        }
        p.insert(*(k.begin()));
        cout << "II: " << *(k.begin()) << endl;
        cout << fir.second.first << " " << fir.second.second << endl;
        k.clear();
        fit++;
    }
    return *(p.begin());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t;
    // cin >> t;

    // while(t--){
        vector< vector<int> > v(3, vector<int>(3));
        multimap <int, pair<int, int> > m;
        // cout << "NOW" << endl;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                char x;
                cin >> x;
                v[i][j] = (int)x;
                m.insert({(int)x, {i, j}});
            }
        }
        // for (auto a: m){
        //     cout << char(a.first) << endl;
        // }
        // cout << "HERE: " << endl;
        cout << logic(m) << endl;
        
    // }

    return 0;
}