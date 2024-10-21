#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

lli logic(vlli& a, int x){
    if (a[0] > 0){return 0;}
    lli mex = 0;
    vector<lli> rep; 
    for (int i=0;i<a.size();i++){
        if (a[i] != mex){
            if (a[i]==mex-1){
                rep.push_back(a[i]);
            }else{
                break;
            }
        }else{
            mex += 1;
        }
    }
    // cout << "mex: " << mex << endl;
    // mex--;
    sort(rep.begin(), rep.end());
    for (int i=rep.size()-1;i>=0;i--){
        if ((mex - (rep[i]))%x == 0){
            mex += 1;
            rep.erase(rep.begin()+i);
        }
    }
    return mex;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, x;
        cin >> n >> x;
        vector<lli> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << logic(a, x) << endl;
    
    }

    return 0;
}