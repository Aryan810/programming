#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;cin >> n;
    vi a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    vi nge(n);
    stack<int> s;
    for (int i=0;i<n;i++){
        if (s.empty()){
            s.push(i);
        }else{
            while (!s.empty() && a[s.top()] < a[i]){
                nge[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty()){
        nge[s.top()] = -1;
        s.pop();
    }
    for (int i=0;i<n;i++){
        cout << a[i] << " " << nge[i] << endl;;
    }

    return 0;
}