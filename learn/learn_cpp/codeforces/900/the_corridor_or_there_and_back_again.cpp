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
        vector< pair<int, int> > p(n);
        for (int i=0;i<n;i++){
            int d, s;
            cin >> d >> s;
            p[i] = {d, s};
        }
        vector<int> possible_ks;
        for (int i=0;i<p.size();i++){
            possible_ks.push_back(p[i].first + (int)ceil(p[i].second/double(2)));
        }
        cout << *min_element(possible_ks.begin(), possible_ks.end())-1 << endl;


        

    }

    return 0;
}