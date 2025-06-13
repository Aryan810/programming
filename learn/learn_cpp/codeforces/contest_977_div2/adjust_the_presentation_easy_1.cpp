#include <iostream>
#include <set>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

bool logic(vi& a, vi& b){
    for (int i=0;i<b.size();i++){
        // cout << "I: " << i << endl;
        if (b[i] != a[0]){
            // cout << "EXIT: " << i << endl;
            return 0;
        }else{
            int last = b[i];
            int n = 0;
            for (int j=i+1;(j<b.size())&&(b[j]!=b[i]);j++){
                if (b[j] != last){
                    last = b[j];
                    n += 1;
                }
            }
            // cout << "Size: " << s.size() << endl;
            a.erase(a.begin());
            a.insert(a.begin()+n, b[i]);
        }
    }
    return 1;
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
        for (int i=0;i<n;i++) cin >> a[i];

        vector<int> b(m);
        for (int i=0;i<m;i++) cin >> b[i];

        cout << (logic(a, b)?"YA":"TIDAK") << endl;
    }

    return 0;
}