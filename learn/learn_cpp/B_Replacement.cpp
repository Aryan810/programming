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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int o = 0, z = 0;
        string inp;
        cin >> inp;
        for (int i=0;i<n;i++){
            if (inp[i] == '0'){z+=1;}else{
                o += 1;
            }
        }
        bool lost = false;
        string inp1;
        cin >> inp1;
        for (int i=0;i<n-1;i++){
            char x = inp1[i];
            // cout << z << " " << o << endl;
            if (o == 1 && z == 1){
                break;
            }
            if (x-48){
                z -= 1;
            }else{
                o -= 1;
            }
            // cout << z << " " << o << endl;
            if (o <= 0 || z <= 0){
                cout << "NO" << endl;
                lost = true;
                break;
            }
        }
        
        if (!lost){
            cout << "YES" << endl;
        }
    }

    return 0;
}