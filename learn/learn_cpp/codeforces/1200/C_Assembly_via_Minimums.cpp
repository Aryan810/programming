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
        int n;cin >> n;
        vi a(n);
        vi b(n*(n-1)/2);
        unordered_map<int, int> m;
        set<int> diff_b;
        for (int i=0;i<(n*(n-1)/2);i++){
            int x;
            cin >> x;
            m[x] += 1;
            b[i] = x;
            diff_b.insert(x);
        }
        sort(b.begin(), b.end());
        a[n-1] = *(b.end()-1);
        int i = n-2;
        auto it = --diff_b.end();
        while(i >= 0){
            int num = m[*it];
            int k = 2*(n - i - 1) - 1;
            int x = (sqrt(k*k + 8*num) - k)/2;
            while(x--){
                a[i] = *it;
                i--;
            }
            it--;
        }
        for (i=0;i<n;i++){
            cout << a[i] << " ";
        }cout << endl;
    }

    return 0;
}