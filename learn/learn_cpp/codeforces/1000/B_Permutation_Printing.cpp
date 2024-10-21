#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void logic(int n){
    for (int i=0;i<ceil(n/double(2));i++){
        cout << i+1 << " ";
        if (i+1+ceil(n/(double)2) <= n){
            cout << i+1+ceil(n/(double)2) << " ";
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int  x;
        cin >> x;
        logic(x);
    }

    return 0;
}