#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int logic(vi & a, int n){
    int l = 0, r = 0;
    int cost = 0;
    for (int i=0;i<n;i++){
        if (a[i] != a[0]){
            l = i;
            break;
        }
    }
    if (l == 0){return 0;}
    for (int i=n-1;i>=l-1;i--){
        if (a[i] != a[n-1]){
            r = i;
            break;
        }
    }
    
    if (a[0] != a[n-1]){
        (l >= n-r-1)?(cost += n-l):(cost += r+1);
    }else{
        cost += r-l+1;
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vi a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        cout << logic(a, n) << endl;
    }

    return 0;
}