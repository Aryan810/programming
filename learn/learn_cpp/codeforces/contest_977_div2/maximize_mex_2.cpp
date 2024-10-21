#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

lli logic(vector<lli>& a, int x){
    lli mex = 0;
    vector<lli> rep;
    for (lli i=0;i<a.size();i++){
        if (a[i] == mex){
            mex += 1;
        }else if(a[i] == mex-1){
            rep.push_back(a[i]);
        }else{
            for (lli j=0;j<rep.size();j++){
                if ((mex-rep[j])%x == 0){
                    a.insert(a.begin()+i, mex);
                    rep.erase(rep.begin()+j);
                    mex += 1;
                    break;
                }
            }
        }
    }
    for (lli i=0;i<rep.size();i++){
        if ((mex-rep[i])%x == 0){
            mex += 1;
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
        for (int i=0;i<n;i++){cin >> a[i];}

        sort(a.begin(), a.end());

        cout << logic(a, x) << endl;
    }

    return 0;
}