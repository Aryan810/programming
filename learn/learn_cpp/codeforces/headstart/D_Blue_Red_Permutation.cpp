#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool logic(vll & r, vll & b, int & n){
    int c = b.size()+1;
    for (auto x: r){
        if (x > c){
            return 0;
        }
        c++;
    }
    c = b.size();
    for (int i=b.size()-1;i>=0;i--){
        if (b[i] < c){
            return 0;
        }
        c--;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vll a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        vll r;
        vll b;
        for (int i=0;i<n;i++){
            char x;
            cin >> x;
            if (x == 'B'){
                b.push_back(a[i]);
            }else{
                r.push_back(a[i]);
            }
        }
        sort(r.begin(), r.end());
        sort(b.begin(), b.end());
        cout << (logic(r, b, n)?"YES":"NO") << endl;

    }

    return 0;
}