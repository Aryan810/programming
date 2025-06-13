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
        vector<lli> e;
        vector<lli> o;
        for (int i=0;i<n;i++){
            lli x;
            cin >> x;
            if (x%2ll == 0){e.push_back(x);}
            else{o.push_back(x);}
        }
        lli M = 0;
        if (o.size() > 0){
            M = *max_element(o.begin(), o.end());
        }
        if (e.size() > 0){
            sort(e.begin(), e.end());
        }
        lli ans = 0;
        if (!(o.size() == 0 || e.size() == 0)){
            for (auto a: e){
                if (M < a){
                    ans = e.size()+1;
                    break;
                }else{
                    ans += 1;
                    M += a;
                }
            }
        }
        cout << ans << endl;


        

    }

    return 0;
}