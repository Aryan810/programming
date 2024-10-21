#include <iostream>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

lli logic(string s){
    if (s.size() < 3){
        return 0;
    }
    lli x = 0;
    for (lli i=0;i<=s.size()-3;i++){  
        if (s.substr(i, 3) == "pie" || s.substr(i, 3) == "map"){
            if (s.size()-i >= 5){
                if (s.substr(i, 5)=="mapie"){
                    x -= 1;
                }
            }
            x += 1;
        }
    }
    return x;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        lli n;
        cin >> n;
        string s;
        cin >> s;
        cout << logic(s) << endl;


    }

    return 0;
}