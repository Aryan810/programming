#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(vii f, vii l){
    // cout << "IN LOGIC" << endl;
    // cout << "A1: " << endl;
    // for (int i=0;i<a.size();i++){
    //     cout << a[i] << endl;
    // }
    int n = int(l-f)+1;
    if (n == 1){
        if (*f == 0){return 1;}
        else{return 0;}
    }
    if (n == 2){
        if (*f == 0 && *(f+1) == 0){return 1;}
        else{return 0;}
    }

    if (*(f+1) >= 2ll*(*f) && *(f+2) >= *f){
        *(f+1) -= 2ll*(*f);
        *(f+2) -= *f;
        *f = 0;
    }else{
        return 0;
    }

    if (*(l-1) >= 2ll*(*l) && *(l-2) >= (*l)){
        *(l-1) -= 2ll*(*l);
        *(l-2) -= *l;
        *l = 0;
        // cout << "IN L" << endl;
    }else{
        return 0;
    }
    // cout << "A2: " << endl;
    // for (int i=0;i<a.size();i++){
    //     cout << a[i] << endl;
    // }
    l--;
    f++;
    return logic(f, l);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << (logic(a.begin(), a.end()-1)?"YES":"NO") << endl;
    }

    return 0;
}