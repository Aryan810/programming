#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return (a.first + a.second) < (b.first + b.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i=0;i<n;i++){cin >> a[i];}
        for (int i=0;i<n;i++){cin >> b[i];}

        vector< pair<lli, lli> > m(n);
        for (int i=0;i<n;i++){
            m[i] = {a[i], b[i]};
        }

        sort(m.begin(), m.end(), comp);
        for (int i=0;i<n;i++){
            cout << m[i].first << " ";
        }
        cout << endl;
        for (int i=0;i<n;i++){
            cout << m[i].second << " ";
        }
        cout << endl;

    }

    return 0;
}