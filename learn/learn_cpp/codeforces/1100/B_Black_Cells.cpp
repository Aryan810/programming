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
        cin >> n;
        vector<lli> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }

        if (n%2 == 0){
            lli gape = 0;
            for (int i=0;i<n-1;i+=2){
                if (a[i+1]-a[i] > gape){
                    gape = a[i+1]-a[i];
                }
            }
            cout << gape << endl;
        }else{
            //case 1
            
                lli mgape = 1e18;
                for (int i=0;i<n;i+=2){
                    lli gape = 0;
                    // for (int j=0;j<(n-1)/2;j++){
                        // if (k == i){
                        //     if (a[k+2]-a[k+1] > gape){
                        //         gape = a[k+2]-a[k+1];
                        //     }
                        //     k+=3;
                        // }else if (k+1 == i){
                        //     if (a[k+2]-a[k] > gape){
                        //         gape = a[k+2]-a[k];
                        //     k+=3;
                        //     }
                        // }else{
                        //     if (a[k+1]-a[k] > gape){
                        //         gape = a[k+1]-a[k];
                        //         k+=2;
                        //     }
                        // }
                    // }
                    for (int j=0;j<i;j+=2){
                        if (a[j+1]-a[j] > gape){
                            gape = a[j+1]-a[j];
                        }
                    }
                    for (int j=i+1;j<n-1;j+=2){
                        if (a[j+1]-a[j] > gape){
                            gape = a[j+1]-a[j];
                        }
                    }
                    if (mgape > gape){
                        mgape = gape;
                    }
                }
                
                
                if (n != 1){
                    cout << mgape << endl;
                }else{
                    cout << 1 << endl;
                }
        }
        

    }

    return 0;
}