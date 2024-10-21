#include <iostream>
#include <vector>
#include <unordered_map>
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

        int n, k;
        cin >> n >> k;
        unordered_map <char, int> m;
        int diff = 0;
        for (int i=0;i<n;i++){
            char c;
            cin >> c;
            if (m[c]%2 == 0){
                diff += 1;
                m[c]+=1;
            }else{
                diff -= 1;
                m[c] = 0; 
            }
        }
        cout << ((diff-k<=1)?"YES":"NO") << endl;
    }

    return 0;
}