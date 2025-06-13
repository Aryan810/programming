#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

lli logic(vlli & a){
    bool inc = 1;
    vector<lli> b(a.size());
    
    lli recent_max = a[0];
    for (int i=0;i<a.size();i++){
        // int bi = *max_element(a.begin(), a.begin()+i);
        if (a[i] > recent_max){
            recent_max = a[i];
        }
        b[i] = recent_max;
        // cout << b[i] << endl;
    }
    lli cmax = b[0]-a[0];
    lli sum = 0;
    for (int i=0;i<a.size();i++){
        lli ci = b[i]-a[i];
        if (ci > cmax){
            cmax = ci;
        }
        sum += ci;
    }
    return (cmax + sum);


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vlli a(n);
        for (int i=0;i<n;i++) cin >> a[i];

        cout << logic(a) << endl;
    }

    return 0;
}