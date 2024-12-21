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
ll ans = 0;
int num = 0;
int induced = 0;
void logic(string s, unordered_set<string> & patt, ll count){

    // cout << s << " " << count << endl;
    // cout << count << " " << possible << endl;

    if (s == ""){ans += 1;return;}
    string temp="";
    for (int i=0;i<s.size();i++){
        temp.push_back(s[i]);
        cout << "SIZE: " << s.size() << " " << temp <<  " " << count << " " << ans << endl;
        num++;
        if (num > 100000){induced += 1;break;}
        if (patt.find(temp) != patt.end()){
            if (i == s.size()-1){
                ans += 1;
                break;
            }else if (i+1<s.size()){logic(s.substr(i+1, s.size()-i-1), patt, count+1);}
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");

    unordered_set<string> avail_patt;
    while (1){
        string s;
        inp >> s;
        if (s.find(',') >= s.size()){
            avail_patt.insert(s);
            break;
        }
        s.pop_back();
        avail_patt.insert(s);
    }

    for (auto s:avail_patt){
        cout << s << endl;
    }cout << endl;
    int index = 0;
    ifstream out;   
    out.open("output.txt");
    while (1){
        index += 1;
        string s;
        out >> s;
        if (s == ""){break;}
        cout << s << endl;
        cout << ans << " " << index << endl;
        logic(s, avail_patt, 0);
        num = 0;
    }

    out.close();
    cout << ans << endl;
    cout << induced << endl;
    inp.close();
    return 0;
}