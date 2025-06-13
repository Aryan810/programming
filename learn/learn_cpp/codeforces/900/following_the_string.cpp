#include <iostream>
#include <map>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vi a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        int x = 97; // ascii value for -> 'a'
        map <char, int> data;
        string s = "";
        for (int i=0;i<n;i++){
            if (a[i] == 0){
                data[(char)x] += 1;
                s.push_back(char(x));
                x+=1;
            }else{
                for (map<char, int>::iterator j=data.begin();j!=data.end();j++){
                    if (j->second == a[i]){
                        s.push_back(j->first);
                        j->second += 1;
                        break;
                    }
                }
            }
        }
        cout << s << endl;



    }

    return 0;
}