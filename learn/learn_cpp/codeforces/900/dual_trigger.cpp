#include <iostream>
#include <vector>
#include <numeric>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> s(n);
        for(int i=0;i<n;i++){
            char c;
            cin >> c;
            s[i] = c-48;
        }
        int sum = accumulate(s.begin(), s.end(), 0);
        if (sum == 2){
            bool found = 0;
            for (int i=0;i<n-1;i++){
                if (s[i] == 1 && s[i+1]==1){
                    found = 1;
                    break;
                }
            }
            cout << (found?"NO":"YES") << endl;
        }else{
            cout << (((sum)%2 == 0)?"YES":"NO") << endl;
        }

    }

    return 0;
}