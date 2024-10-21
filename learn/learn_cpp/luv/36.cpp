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

        int n,  k;
        cin >> n >> k;
        multiset<lli> s;
        for (int i=0;i<n;i++){
            lli x;
            cin >> x;
            s.insert(x);
        }
        lli c = 0;
        for (int i=0;i<k;i++){
            auto x = *(--s.end());
            c += x;
            s.erase(--s.end());
            s.insert(x/2);
        }
        cout << c << endl;
    }

    return 0;
}