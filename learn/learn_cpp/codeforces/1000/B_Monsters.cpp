#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool comp1(pair<int, int> a, pair<int, int> b){
    return (a.second > b.second);
}

bool comp2(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return (a.first < b.first);
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
        vector< pair<int, int> > h(n);
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            h[i] = {i, x};
        }
        for (int i=0;i<n;i++){
            if (h[i].second % k == 0){
                cout << (h[i].first+1) << " ";
                h[i].second = 0;
            }else{
                h[i].second -= k*(h[i].second/k);
            }
        }
        stable_sort(h.begin(), h.end(), comp1);
        // sort(h.begin(), h.end(), comp2);
        for (int i=0;i<n;i++){
            if (h[i].second != 0){
                cout << (h[i].first+1) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}