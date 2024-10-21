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

        lli a, b;
        int n;
        cin >> a >> b >> n;
        vlli x(n);
        for (int i=0;i<n;i++) cin >> x[i];
        sort(x.begin(), x.end());

        lli mt = 0ll;
        lli timer = b;
        // while (!(x.size() == 0 && timer == 0)){
        //     if (timer > a){mt += a-1;break;}
        //     mt += timer;
        //     timer = 0;
        //     if (x.size() != 0){
        //         timer += x[0];
        //         x.erase(x.begin());
        //     }
        // }
        while (1){
            // cout << "TIMER - 1: " << timer << endl;
            if (timer == 1 && x.size()!=0){
                timer += x[0];
                x.erase(x.begin());
            }
            if (timer > a){timer = a;}
            // cout << "TIMER - 2: " << timer << endl;
            
            if (timer > 1){
                mt += timer-1;
                timer = 1;
            }else{
                mt += 1;
                timer -= 1;
            }
            // cout << tim
            // cout << "TIMER - 3: " << timer << endl << endl;

            
            if (timer == 0){
                break;
            }

        }
        cout << (mt) << endl;

    }

    return 0;
}