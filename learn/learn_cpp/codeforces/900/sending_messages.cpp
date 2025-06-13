#include <iostream>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        lli n, f, a, b;
        cin >> n >> f >> a >> b;
        vlli mes(n+1);
        mes[0ll] = 0ll;
        for (int i=1;i<n+1;i++){
            cin >> mes[i];
        }
        lli i=0ll;
        while ((f > 0) && (i < n)){
            if ((mes[i+1]-mes[i])*a > b){
                cout << "I: " << i << endl;
                cout << "OFF, " << f << endl;
                f -= b;
                i += 1;
            }else{
                cout << "ON, " << f << endl;
                cout << "I: " << i << endl;
                // cout << "mes[i+1]: " << mes[i+1] << endl;
                f -= a*(mes[i+1]-mes[i]);
                cout << "ff: " << f << endl;
                  i += 1;
            }
        }
        cout << "F: " << f << endl;
        cout << ((f>0)?"YES":"NO") << endl;

    }

    return 0;
}