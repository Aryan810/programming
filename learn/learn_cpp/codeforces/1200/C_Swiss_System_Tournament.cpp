#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t;
    // cin >> t;

    // while(t--){
        int n, m;
        cin >> n >> m;
        // unordered_map<int, int> rank;
        vector< vector<char> > d(2*n);
        for (int i=0;i<2*n;i++){
            vector<char> x(m);
            for (int j=0;j<m;j++){
                char y;
                cin >> y;
                x[j] = y;
            }
            d[i] = x;
        }
        vector< pair<int, int> > ranks(2*n);
        for (int i=0;i<2*n;i++){
            ranks[i] = {0, i};
        }
        // auto comp = [](pair<int, int> a, pair<int, int> b){
        //     return (a.second != b.second)?(a.second > b.second):(a.first < b.first);
        // };
        for (int i=0;i<m;i++){
            for (int j=0;j<2*n-1;j+=2){
                char a = d[ranks[j].second][i];
                char b = d[ranks[j+1].second][i];
                if (a == 'G'){
                    if (b == 'C'){
                        ranks[j].first -= 1;
                    }else if (b == 'P'){
                        ranks[j+1].first -= 1;
                    }
                }else if (a == 'C'){
                    if (b == 'P'){
                        ranks[j].first -= 1;
                    }else if (b == 'R'){
                        ranks[j+1].first -= 1;
                    }
                }else if (a == 'P'){
                    if (b == 'R'){
                        ranks[j].first -= 1;
                    }else if (b == 'C'){
                        ranks[j+1].first -= 1;
                    }
                }
                // else{
                    // ranks[j].second += 1;
                    // ranks[j+1].second += 1;
                // }
            }
            sort(ranks.begin(), ranks.end());
        }
        // cout << "L: " << rank.size() << endl;
        
        
        for (auto a: ranks){
            cout << a.second+1 << endl;
        }
    // }

    return 0;
}