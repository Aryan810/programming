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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> goal;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            a[i] = x;
            int g = k*(x/k + 1) - x; 
            if (g%k == 0){
                goal.push_back(0);
            }else{
            goal.push_back(g);
            }
        }
        if (k != 4){
        
            cout << *min_element(goal.begin(), goal.end()) << endl;
        }
        else{
            int evens = 0;
            int fourd = 0;
            for (int i=0;i<n;i++){
                if (a[i]%2 == 0){
                    evens += 1;
                    if (a[i]%4 == 0){
                        fourd += 1;
                    }
                }
            }
            if (evens >= 2 || fourd >= 1){
                cout << "0" << endl;
            }else{
                if (n >= 2){
                    if (evens == 1){
                        cout << "1" << endl;
                    }else{
                        cout << ((*min_element(goal.begin(), goal.end()) == 1)?(1):(2)) << endl;
                    }
                }else{
                    cout << goal[0] << endl;
                }
            }
        }

    }

    return 0;
}