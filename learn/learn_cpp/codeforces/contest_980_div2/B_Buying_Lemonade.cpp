#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

lli logic(vi & a, int n, int k, map<int, int> & m){
    lli ans = 0ll;
    int m1 = a[0];
    if (n*m1 >= k){return k;}
    auto it = a.begin();
    auto l = a.end();
    auto mit = m.begin();
    int mp = 0;
    while (k!=0 && it!=a.end() && mit!=m.end()){
        if ((*it - mp)*(l-it) >= k){
            ans += k;
            break;
        }else{
            k -= (*it - mp)*(l-it);
            ans += (*it - mp)*(l-it) + mit->second;
            mp += *it - mp;
            if (l-it >= mit->second){
                it += mit->second;
            }
            mit++;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        map<int, int> m;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            m[x] += 1;
            a[i] = x;
        }
        sort(a.begin(), a.end());
        cout << logic(a, n, k, m) << endl;


        

    }

    return 0;
}