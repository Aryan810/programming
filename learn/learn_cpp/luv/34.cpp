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

    int t=1;
    // cin >> t;

    while(t--){
        int n;
        cin >> n;
        unordered_map<string, int> m;
        for (int i=0;i<n;i++){
            string s;
            cin >> s;
            m[s] += 1;
        }
        int q;
        cin >> q;
        for (int i=0;i<q;i++){
            string s;
            cin >> s;
            cout << m[s] << endl;
        }
        

    }

    return 0;
}