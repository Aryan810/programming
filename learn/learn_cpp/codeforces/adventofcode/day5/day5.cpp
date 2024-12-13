#include <bits/stdc++.h>
#include <fstream>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int search(vector<int> & a, int x){
    for (int i=0;i<a.size();i++){
        if (a[i] == x){
            return i;
        }
    }
    return a.size()+10;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    ll ans = 0;

    vector <pair <int, int> > rules;
    int l = 1176;
    while (l--){
        string s;
        inp >> s;
        // if (s == ""){break;}
        rules.push_back({
            stoi(s.substr(0, 2)), stoi(s.substr(3, 2))
        });
        // cout << rules.size() << endl;
        // cout << stoi(s.substr(0, 2)) << " " << stoi(s.substr(3, 2)) << endl;
    }
    sort(rules.rbegin(), rules.rend());
    // ll ans = 0;
    while (1){
        string s;
        inp >> s;
        // cout << s << endl;
        if (s == ""){break;}
        vi a;
        for (int i=0;i<s.size()-1;i+=3){
            a.push_back(stoi(s.substr(i, 2)));
            // cout << stoi(s.substr(i, 2)) << " ";
        }
        bool good = 1;
        for (int i=0;i<rules.size();i++){
            auto c = search(a, rules[i].first);
            auto d = search(a, rules[i].second);
            if (c < a.size() && d < a.size()){
                if (c > d){
                    good = 0;
                    int temp = a[c];
                    a[c] = a[d];
                    a[d] = temp;
                }
            }
        }
        if (!good){
            while (!good){
                good = 1;
                cout << "repeat!" << endl;
                for (int i=0;i<rules.size();i++){
                    auto c = search(a, rules[i].first);
                    auto d = search(a, rules[i].second);
                    if (c < a.size() && d < a.size()){
                        if (c > d){
                            good = 0;
                            int temp = a[c];
                            a[c] = a[d];
                            a[d] = temp;
                        }
                    }
                }
            }
            ans += a[(a.size()-1)/2];
        }
    }
    
    cout << ans << endl;
    inp.close();

    

    return 0;
}