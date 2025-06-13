#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        unordered_map<int, int> m;
        unordered_set<int> s;
        string out;
        bool done = 0;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            m[x] += 1;
            if (m[x] == 2){
                s.insert(x);
                if (!done){
                    out.push_back('3');
                    out.push_back(' ');
                    done = 1;
                }else{
                    out.push_back('2');
                    out.push_back(' ');
                }
            }else{
                out.push_back('1');
                out.push_back(' ');
            }
        }
        if (s.size() < 2){
            cout << "-1" << endl;
        }else{
            cout << out << endl;
        }
        

    }

    return 0;
}