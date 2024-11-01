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
        vi a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        int dist = 0;
        int x = (n - 1)/2;
        int y = n - x - 1;
        // cout << x << endl;
        if (n%2 == 0){
            if (a[x] == a[y]){
                dist += 1;
            }
        }else if (n == 1){dist = 0;}
        else{
            if (a[x] == a[x-1]){
                dist += 1;
                // cout << "1: " << x << endl;
            }
            if (a[x] == a[x+1]){
                dist += 1;
                // cout << "2: " << x << endl;

            }
            x--;y++;
        }
        // cout << dist << endl;
        while (x!=0 && y!=n-1){
            int c=a[x], d = a[y], e = a[x-1], f=a[y+1];
            if (((c == d && (c == e || c == f)) && e != f) || ((e == f && (e == c || e == d)) && c != d)){
                dist += 1;
            }else if(c == d && (d == e && e == f)){
                dist += 2;
            }
            x--;y++;
            // if (a[x] != a[y]){
            //     if (!((a[x-1] == a[x] && a[y+1] == a[y]) || (a[x-1] == a[y] && a[y+1] == a[x]))){
                    
            //     }
            // }else{

            // }
        }
    cout << dist << endl;

    }
    return 0;
}