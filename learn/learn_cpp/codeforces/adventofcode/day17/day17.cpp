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
ll A, B, C;
ll combo(ll a){
    if (a >= 0 && a <= 3){
        return a;
    }else if (a == 4){return A;}
    else if (a == 5){return B;}
    else if (a == 6){return C;}
    else{
        return -1;
    }
}

ll binexpiter(ll a, ll b){
    ll ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");

    string s;
    getline(inp, s);
    A = stol(s.substr(12, s.size()-12));
    s = "";
    getline(inp, s);
    B = stol(s.substr(12, s.size()-12));
    s = "";
    getline(inp, s);
    C = stol(s.substr(12, s.size()-12));
    getline(inp, s);
    s = "";

    getline(inp, s);
    s = s.substr(9, s.size()-9);
    string inpstr = s;
    vector<pair<int, int> > prog;
    for (int i=0;i<s.size();i+=4){
        string x = s.substr(i, 4);
        prog.push_back({x[0]-'0', x[2]-'0'});
    }
    ll fixA = 191474976710655;
    while (1){
        ll i = 0;
        string out;
        A = fixA;
        B = 0;
        C = 0;
;
        // if (fixA > 281474976710656){break;}
        while (i < prog.size()){
            if (prog[i].first == 0){
                A = A/(binexpiter(2, combo(prog[i].second)));
            }else if (prog[i].first == 1){
                B = B^prog[i].second;
            }else if (prog[i].first == 2){
                B = combo(prog[i].second)%8;
            }else if (prog[i].first == 3){
                if (A > 0){
                    i = prog[i].second;
                    continue;
                }
            }else if (prog[i].first == 4){
                B = B^C;
            }else if (prog[i].first == 5){
                out.push_back(combo(prog[i].second)%8 + '0');
                out.push_back(',');
            }else if (prog[i].first == 6){
                B = A/(binexpiter(2, combo(prog[i].second)));
            }
            else if (prog[i].first == 7){
                C = A/(binexpiter(2, combo(prog[i].second)));
            }
            i += 1;
        }

        out.pop_back();
        cout << fixA << endl;
        cout << out << endl;
        cout << inpstr << endl;

        break;
        if (out == inpstr){
            break;
        }
        fixA -= 1;
    }
    cout << fixA << endl;
    inp.close();
    return 0;
}