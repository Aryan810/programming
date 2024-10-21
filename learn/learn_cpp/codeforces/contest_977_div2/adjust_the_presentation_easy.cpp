#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

bool logic(vi& a, vi& b){
    if (b[0] != a[0]){
        return 0;
    }
    for (int i=0;i<b.size();i++){
        if(b[i] == a[0]){
            if (b[i+1] != a[1]){
                return 0;
            }
            int gape = (int)(lower_bound(b.begin()+i+1, b.end(), b[i])-b.begin())-i;
            if (gape > a.size()-1){
                gape = a.size()-1;
            }
            a.erase(a.begin());
            a.insert(a.begin()+1+gape)
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, m, q;

        cin >> n >> m >> q;

        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i=0;i<m;i++){
            cin >> b[i];
        
        cout << (logic(a, b)?"YA":"TIDAK") << endl;

    }

    return 0;
}