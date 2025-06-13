// we just need to see if there is an element wtih frequency 'odd' and
// if yes then alice will first select the greatest number with odd frequency


#include <iostream>
#include <vector>
#include <map>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int sum = 0;
        vector<int> freq(n+1, 0);
        for (int i=0;i<n;i++){
            int t;
            cin >> t;
            freq[t] += 1;
        }
        bool alice = 0;
        for (int i=0;i<freq.size();i++){
            if (freq[i]%2 != 0){
                alice = true;
            }
        }
        cout << (alice?"YES":"NO") << endl;

    }

    return 0;
}