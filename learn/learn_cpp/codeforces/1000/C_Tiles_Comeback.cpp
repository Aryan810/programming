#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(int n, int k, vi & color){
    int l = color[n-1];
    int f = color[0];
    if(l == f){
        int fs = 0;
        for (int i=0;i<n;i++){
            if (color[i] == f){
                fs += 1;
            }
        }
        if (fs >= k){
            return 1;
        }
    }else{
        int nf = 0;
        int nl = 0;
        int i=0;
        for (;i<n;i++){
            if (color[i] == f){
                nf+=1;
                if (nf % k == 0){break;}
            }
        }
        for (;i<n;i++){
            if (color[i] == l){
                nl += 1;
            }
        }
        if (nf >= k && nl >= k){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> color(n);
        for (int i=0;i<n;i++) cin >> color[i];
        cout << (logic(n, k, color)?"YES":"NO") << endl;
    }

    return 0;
}