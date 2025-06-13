#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool comp1(pair<int, int> p1, pair<int, int> p2){
    return (p1.first > p2.first);
}

bool comp2(pair<int, int> p1, pair<int, int> p2){
    return (p1.second < p2.second);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, p;
        cin >> n >> p;

        vector< pair<int, int> > v(n);
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            v[i].first = x;
        }

        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            v[i].second = x;
        }

        sort(v.begin(), v.end(), comp1);
        sort(v.begin(), v.end(), comp2);
        
        lli ans = 0;
        ans += p;
        // v.pop_back();
        // int left = n;
        for (int i=0;i<v.size();i++){
            if (i == v.size()-1){break;}
            auto pr = v[i];
            if (pr.second <= p){
                int sz = v.size();
                for (int j=0;j<pr.first-1;j++){
                    v.pop_back();
                    ans += pr.second;
                    if (v.size() <= i+1){
                        break;
                    }
                }
                if (v.size() > i+1){
                    ans += pr.second;
                }
            }else{
                if (v.size() > i+1){
                    ans += p;
                }
            }
            // if (pr.second <= p){
            //     if (left >= pr.second){
            //         left -= pr.first;
            //         ans += (pr.first)*(pr.second);
            //     }else{
            //         ans += left*pr.second;
            //         left = 0;
            //         break;
            //     }
            // }else{
            //     ans += left*p;
            //     break;
            // }
        }
        cout << ans << endl;

    }

    return 0;
}