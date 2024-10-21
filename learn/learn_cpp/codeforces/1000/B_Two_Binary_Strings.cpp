#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(string & a, string & b){
    for (int i=0;i<a.size();i++){
        if ((a[i] == '0' and b[i] == '0') and (a[i+1] == '1' and b[i+1] == '1')){
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
        string a, b;
        cin >> a;
        cin >> b;
        cout << (logic(a, b)?"YES":"NO") << endl;
    }

    return 0;
}