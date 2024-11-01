#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

void logic(lli n){

    if (n%2 == 0){
        if (n == 2){
            cout << "2" << endl << "1 2" << endl;
            return;
        }
        if (n == 4){
            cout << "6" << endl << "1 2 3 4" << endl;
            return;
        }
        if (n == 6){
            cout << "7" << endl << "1 2 4 6 5 3" << endl;
            return;
        }
        lli x = log2(n);
        cout << pow(2, x+1) - 1 << endl;
        for (int i=1;i<(n);i++){
            if (log2(i+1) - (lli)log2(i+1) != 0 && i != pow(2, x)-2){
                cout << i << " ";
            }
        }
        
        for (int i=1;i<=x;i++){
            if (i == x){
                cout << pow(2, i) - 2 << " ";
            }
            cout << pow(2, i)-1 << " ";
            
        }
        cout << n << endl;
    }else{
        if (n == 1){
            cout << '0' << endl << '1' << endl;
            return;
        }else if (n == 3){
            cout << '2' << endl << "1 2 3" << endl;
            return;
        }

        lli x = log2(n);
        cout << n << endl;
        for (int i=1;i<(n);i++){
            if (log2(i+1) - (lli)log2(i+1) != 0 && i!=n-1){
                cout << i << " ";
            }
        }
        
        for (int i=1;i<=x;i++){
            cout << pow(2, i)-1 << " ";
        }
        cout << n-1 << " " << n << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        lli n;
        cin >> n;
        logic(n);
        

    }

    return 0;
}