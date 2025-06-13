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
        vector<int> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        auto m = max_element(a.begin(), a.end());
        if (m != a.end()-1){
            cout << *m + *(a.end()-1) << endl;
        }else{
            int x = *m;
            a.pop_back();
            cout << *(max_element(a.begin(), a.end())) + x << endl;
        }

    }

    return 0;
}