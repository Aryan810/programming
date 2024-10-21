#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        lli k;
        cin >> n >> k;
        vlli d(n);
        for (int i=0;i<n;i++) cin >> d[i];
        sort(d.begin(), d.end());

        vector<int> num;
        int temp = 1;
        for (int i=0;i<n;i++){
            if (i == n-1){break;}
            if (d[i+1]-d[i] > k){
                num.push_back(temp);
                temp = 1;
            }else{
                temp += 1;
            }
        }
        num.push_back(temp);
        // for (int i=0;i<num.size();)1
        

        cout << n-*(max_element(num.begin(), num.end())) << endl;
    }

    return 0;
}