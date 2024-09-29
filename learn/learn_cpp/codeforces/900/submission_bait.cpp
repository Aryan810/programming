#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define lli long long int

using namespace std;

int willWin = 0;

void can_win(vector<int> a, int mx, int alice){
    vector<int>::iterator x = lower_bound(a.begin(), a.end(), mx);
    if (x == a.end()){
        if (alice == 0){
            willWin = 1;
        }
    }else{
        a.erase(a.begin(), x);
        int last = 0;
        alice = (alice == 0)?1:0;
        for (int i=0;i<a.size();i++){
            if (a[i] != last){
                last = a[i];
                mx = a[i];
                a[i] = 0;
                can_win(a, mx, alice);
            }
        }
    }
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        can_win(a, 0, 1);
        cout << (willWin?"YES":"NO") << endl;
        willWin = 0;
    }

    return 0;
}