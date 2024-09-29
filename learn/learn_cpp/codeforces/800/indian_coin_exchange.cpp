#include <bits/stdc++.h>
using namespace std;
#define veci vector<int>;
#define iter(i, n, a) for(int i=a;i<n;i++)


int just_less_than(int x, vector<int>& types){
    if (x <= 0){return 0;}
    for (int i=types.size()-1;i>=0;i--){
        if (types[i] <= x){
            return types[i];
        }
    }
    return 0;
}

int main(){
    int x;
    vector<int> types(10);
    types[0] = 1;
    types[1] = 2;
    types[2] = 5;
    types[3] = 10;
    types[4] = 20;
    types[5] = 50;
    types[6] = 100;
    types[7] = 200;
    types[8] = 500;
    types[9] = 2000;

    
    cout << "Enter x: ";
    cin >> x;
    int temp;
    int min_coins=0;
    while (x != 0){
        temp = just_less_than(x, types);
        // cout << temp;
        cout << "TEMP: " << temp << " X: " << x << endl;
        if (temp){
            min_coins += (x-(x%temp))/temp;
            x = x%temp;
        }
        // cout << x << endl;
    }
    cout << "MIN COINS: " << min_coins << endl;

    return 0;
}