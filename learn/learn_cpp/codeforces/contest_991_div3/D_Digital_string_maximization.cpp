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

        string s;
        cin >> s;

        for(int i=1;i<s.size();i++){
            int j = i;
            while (j > 0 && s[j] > 0 && s[j]-1 > s[j-1]){
                int temp = s[j-1];
                s[j-1] = s[j]-1;
                s[j] = temp;
                j--;
            }
        }
        cout << s << endl;

    }

    return 0;
}