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
        vector<int> v(n);
        for (int i=0;i<n;i++) cin >> v[i];

        cout << (n-1)*(*max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end())) << endl;
        

    }

    return 0;
}