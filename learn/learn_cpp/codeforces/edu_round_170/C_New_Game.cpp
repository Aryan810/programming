#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void max_sum(vii a, vii b, int k, int & ans){
    int min = *a;
    vii c = a;
    for (int i=0;i<k && c != b;i++){
        c++;
    }
    if (ans < (*c - *a)){
        ans = *c - *a;
    }
    while (c != b){
        a++;
        c++;
        if (ans < (*c - *a)){
            ans = *c - *a;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        map<lli, int> m;
        for (int i=0;i<n;i++){
            lli ai;
            cin >> ai;
            m[ai] += 1;
        }
        vector<int> cum(n+1);
        cum[0] = 0;
        lli sum = 0;
        int ind = 1;
        for(auto it = m.begin();it!=m.end();){
            sum += it->second;
            cum[ind] = sum;
            ind += 1;
            it++;
        }
        int ans = 0;
        vii a = cum.begin();
        vii b = cum.begin()+1;
        auto it = m.begin();
        auto it1 = ++m.begin();
        while (it != m.end()){
            if (it1->first != it->first + 1){
                max_sum(a, b, k, ans);
                a = b;
            }
            b++;
            it++;
            it1++;
            if (it1 == m.end()){
                max_sum(a, b, k, ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}