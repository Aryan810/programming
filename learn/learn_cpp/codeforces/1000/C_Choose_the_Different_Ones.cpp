#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(int n, int m, int k){
    set<int> a;
    set<int> b;
    set<int> c;
    // for (int i=0;i<k;i++) c.insert(i+1);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if (x >= 1 && x <= k){
            a.insert(x);
        }
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        if (x >= 1 && x <= k){
            b.insert(x);
        }
    }
    if (a.size() < k/2){
        return 0;
    }
    if (b.size() < k/2){
        return 0;
    }
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
    return (a.size()+b.size() - c.size() == k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, m, k;
        cin >> n >> m >> k;
        
        cout << (logic(n, m, k)?"YES":"NO") << endl;

    }

    return 0;
}