#include <bits/stdc++.h>

using namespace std;
const int M = 180;
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}

int main(){

    int n = 180;
    set<int> st;
    for (int i=0;i<180;i++){
        int k = (binexpiter(i, 54))%180;
        st.insert(k);
    }

    for (auto & ele: st){
        cout << ele << " ";
    }cout << endl;

    return 0;
}