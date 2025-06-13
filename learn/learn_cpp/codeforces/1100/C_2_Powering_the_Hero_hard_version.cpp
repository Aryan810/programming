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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vll d(n);
        for (int i=0;i<n;i++) cin >> d[i];
        multiset<int> s;
        ll power = 0ll;
        for (int i=0;i<n;i++){
            if (d[i] == 0){
                if (s.size() > 0){
                    power += *(--s.end());
                    s.erase(--s.end());
                }
            }else{
                s.insert(d[i]);
            }
        }
        cout << power << endl;

    }

    return 0;
}