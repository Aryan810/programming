#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(vi &a, vi &b){   
    if (a == b){
        return 0;
    }
    for (int i=0;i<a.size();i++){
        if (a[i] != b[a.size()-1-i]){
            return 1;
        }
    }
    return 0;
    // if (a == b){
    //     return 0;
    // }
    // while (b.size() > 1){
    //     if ((a[0] != b[0] && a[0] != *(b.end()-1)) || (*(a.end()-1) != b[0] && *(a.end()-1) != *(b.end()-1))){
    //         return 1;
    //     }else{
    //         if (a[0] == b[0]){
    //             b.erase(b.begin());
    //         }else{
    //             b.erase(b.end()-1);
    //         }
    //         a.erase(a.begin());
    //     }
    // }
    
    // return (a[0] == b[0])?0:1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        cout << (logic(a, b) ? "Alice" : "Bob") << endl;
    }

    return 0;
}