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
        int q;
        cin >> q;
        vector<int> a(1);
        cin >> a[0];
        string out;
        out.push_back('1');
        bool dec = 0;
        for (int i=1;i<q;i++){
            int x;
            cin >> x;
            // cout << "edd: " << dec << endl;
            if (!dec && x < *a.begin()){
                out.push_back('1');
            a.push_back(x);

                dec = 1;
            }
            else if (!dec && x>=*(a.end()-1)){
                out.push_back('1');
            a.push_back(x);

            }
            else if (dec && (x<=*(a.begin()) && x >=*(a.end()-1))){
                out.push_back('1');
            a.push_back(x);

            
            }else{
                out.push_back('0');
            }
        }
        cout << out << endl;

    }

    return 0;
}