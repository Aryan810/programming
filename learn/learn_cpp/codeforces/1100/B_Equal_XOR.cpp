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
        int n, k;
        cin >> n >> k;
        vi tos;
        vi ones;
        unordered_map<int, int> came;
        unordered_map<int, int> m;
        for (int i=0;i<2*n;i++){
            int x;
            cin >> x;
            if (i < n){m[x] += 1;came[x] = 1;}
        }
        for (auto a: m){
            if (a.second == 2){
                tos.push_back(a.first);
            }else{
                ones.push_back(a.first);
            }
        }
        int c = 2*k;
        for (int i=0;i<tos.size() && c>=2;i++){
            cout << tos[i] << " " << tos[i] << " ";
            c-=2;
        }
        for (int i=0;i<c;i++){
            cout << ones[i] << " ";
        }
        cout << endl;
        int j = c;
        c = 2*k - c;
        for (int i=1;i<=n;i++){
            if (!came[i] && c > 0){
                cout << i << " " << i << " ";
                c-=2;
            }
        }
        // cout << "J: " << j << endl;
        for (int i=0;i<j;i++){
            cout << ones[i] << " ";
        }
        cout << endl;



    }

    return 0;
}